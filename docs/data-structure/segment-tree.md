---
layout: default
title: Segment Tree
parent: Data Structure
---
# Segment Tree
{: .no_toc}

## Table of contents
{: .no_toc .text-delta }

1. TOC
{:toc}
---

## Code

```cpp
template<typename T>
struct SegmentTree{
    int n;
    vector <T> node, lazy;
    SegmentTree (int n): n(n), node(4*n+5, 0), lazy(4*n+5, 0) {}
    
    void pushLazy(int l, int r, int id){
        node[id] += lazy[id] * (r - l + 1);             
        if (l != r)
            lazy[2*id] += lazy[id],
            lazy[2*id+1] += lazy[id];
        lazy[id] = 0;
    }
    void update(int u, int v, T val, int l=0, int r=0, int id = 1){
        if (!l) l = 1, r = n;
        pushLazy(l, r, id);
        if (r < u || v < l)     return;
        if (u <= l && r <= v)   { lazy[id] += val; pushLazy(l, r, id); return; }
        update(u, v, val, l, (l+r)/2, 2*id);
        update(u, v, val, (l+r)/2+1, r, 2*id + 1);
        node[id] = node[2*id] + node[2*id+1];
    }
    T get(int u, int v, int l=0, int r=0, int id = 1){
        if (!l) l = 1, r = n;
        pushLazy(l, r, id);
        if (r < u || v < l)     return 0;
        if (u <= l && r <= v)   return node[id];
        return get(u, v, l, (l+r)/2, 2*id) + get(u, v, (l+r)/2+1, r, 2*id + 1);
    }
};
```
