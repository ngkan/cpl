---
layout: default
title: Binary exponential
parent: Math
---
# Binary Exponential
{: .no_toc}

## Table of contents
{: .no_toc .text-delta }

1. TOC
{:toc}
---

## Thuật toán

Lũy thừa nhanh

## Code

```cpp
int binpow(int a, int n, int mod = (int) 1e9 + 7){
    int res = 1;
    while (n) {
        if (n & 1)
            res = 1ll * res * a % mod;
        a = 1ll * a * a % mod;
        n >>= 1;
    }
    return res;
}
```
