---
layout: default
title: Knuth - Morris - Pratt
parent: String
---
# Knuth - Morris - Pratt
{: .no_toc}

## Table of contents
{: .no_toc .text-delta }

1. TOC
{:toc}
---
## Thuật toán

KMP chủ yếu dùng để xử lý các bài toán về xâu.

## Code

```cpp
vector<int> pifunc(string s){
    vector<int> pi = vector<int>(s.size(), 0);
 
    for (int i = 1, k = 0; i < s.size(); ++i) {
        while (k && s[k] != s[i]) k = pi[k - 1];
        if (s[k] == s[i]) ++k;
        pi[i] = k;
    }

    return pi;
}

vector<int> kmp(string s, string p){
    vector <int> pi = pifunc(p), res;

    for (int i = 0, k = 0; i < s.size(); ++i) {
        while (k && (k == p.size() || p[k] != s[i])) k = pi[k - 1];
        if (p[k] == s[i]) ++k;
        if (k == p.size()) res.push_back(i - k + 1);
    } 

    return res;
}
```
