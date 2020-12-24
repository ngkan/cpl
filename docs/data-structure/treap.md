---
layout: default
title: Treap
parent: Data Structure
---
# Treap
{: .no_toc}

## Table of contents
{: .no_toc .text-delta }

1. TOC
{:toc}
---

## Code

```cpp
/**
 * Treap (+ Implicit)
 * Author: Khanh Nguyen
 * Description: A randomized binary search tree. Uncomment for its implicit version.
 * Complexity: O(log) for all queries.
 * Status: Tested, SPOJ - TREAP
 *  
 * Notes:
 * Every node has 3 values: key, priority, and number of nodes in its subtree. 
 * WARNING: when insert an exist key into the (non-implicit) treap, this code 
 * will replace that key.
 * split(t, l, r, key): split t into 2 trees where keys on l is less than or 
 * equals to key and keys on r is greater than key
 * 
 * Implicit key for node T = cnt(T->L) + [cnt(P->L)+1 for each ancestor of T 
 * that T is in P->R].
 * Index from 0.
 * Stored values are keys.
 */

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Treap{
    struct node {
        int key, prior, cnt;
        node * l, * r;
        node() {}
        node(int key): key(key), prior(rng()), cnt(1), l(0), r(0) {}
    };

    typedef node * pnode;
    int cnt(pnode t) {
        return t ? t->cnt : 0;
    }
    void recal(pnode t) {
        if (t)
            t->cnt = 1 + cnt(t->l) + cnt(t->r);
    }
    void split(pnode t, pnode & l, pnode & r, int key) {// int carry = 0
        if (!t)
            return void(l = r = 0);
        // int cur_key = carry + cnt(t->l); // implicit key
        if (key < t->key)   // key < cur_key
            split(t->l, l, t->l, key),  r = t; // carry
        else
            split(t->r, t->r, r, key),  l = t; // carry + 1 + cnt(t->l)

        recal(t);
    }
    void merge(pnode &t, pnode l, pnode r) {
        if (!l || !r)
            t = l ? l : r;
        else if (l->prior > r->prior)
            merge(l->r, l->r, r),  t = l;
        else
            merge(r->l, l, r->l),  t = r;
        
        recal(t);
    }

    pnode root;
    Treap(): root(0) {}
    void insert(int key) {          // pos, key
        pnode l, k, r;
        split(root, l, r, key);     // pos-1
        split(l, l, k, key-1);      // comment this line
        k = new node(key);          
        merge(root, l, k);
        merge(root, root, r);
    }
    void erase(int key){            // pos
        pnode l, k, r;
        split(root, l, k, key-1);   // pos-1
        split(k, k, r, key);        // 0
        delete k;
        merge(root, l, r);
    }
};
```
