---
layout: default
title: Suffix Array
parent: String
---
# Suffix Array
{: .no_toc}

## Table of contents
{: .no_toc .text-delta }

1. TOC
{:toc}
---
## Thuật toán

Mảng hậu tố chủ yếu dùng để xử lý các bài toán về xâu.

## Code

```cpp
struct SuffixArray{
    string s;
    int n;
    vector <int> sa, saRank, t, lcp;
    
    SuffixArray(string _s = ""): s(_s), n(s.size()), sa(n, 0), saRank(n ,0),
            t(n, 0), lcp(n, 0){
        prefixDoubling();
        kasai();
    }
 
    bool cmp(int x,int y,int gap){
        return (saRank[x] != saRank[y]) ? saRank[x] < saRank[y] : 
            (x+gap < n && y+gap < n ? saRank[x+gap] < saRank[y+gap] : x > y);
    }
 
    void prefixDoubling(){
        for(int i = 0; i < n; i ++)
            sa[i] = i, saRank[i] = s[i];

        for(int gap = 1; ; gap <<= 1){
            sort(sa.begin(), sa.begin() + n, [&](int a, int b) {return cmp(a, b, gap);});
            for(int i = 1; i < n; i ++) t[i] = t[i-1] + cmp(sa[i-1], sa[i], gap);
            for(int i = 0; i < n; i ++) saRank[sa[i]] = t[i];
            if (t[n-1] == n - 1) break;
        }
    }
 
    void kasai(){
        for(int i = 0, k = 0; i < n; i ++){
            if (saRank[i] != n - 1){
                for (int j = sa[saRank[i] + 1]; max(i+k, j+k) < n && s[i + k] == s[j + k]; ++k);
                lcp[saRank[i]] = k;
                if (k) k--;
            }
        }
    }
};
```
