---
layout: default
title: Tonelli Shanks
parent: Math
---
# Tonelli Shanks
{: .no_toc}

## Table of contents
{: .no_toc .text-delta }

1. TOC
{:toc}
---

## Thuật toán

Tính căn bậc hai của một số modulo $mod$ (nếu tồn tại).

## Code

```cpp
mt19937 rng(std::chrono::system_clock::now().time_since_epoch().count());

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

int Tonelli_Shanks(int n, int p){
    int q = p - 1, s = 0;
    
    while (q % 2 == 0)
        ++ s,
        q >>= 1;  

    int z;
    do {
        z = rng() % p;
    } while(binpow(z, (p-1)/2, p) != p-1);

    int m = s,
        c = binpow(z, q, p),
        t = binpow(n, q, p),
        r = binpow(n, (q+1)/2, p);
    
    while (t > 1) {
        i = 0;
        do {
            i ++;
            t = 1ll * t * t % p;
        } while (t != 1);

        if (t == m)
            return -1;
        
        int b = binpow(c, (1<<(m-i-1)), p);
        m = i;
        c = binpow(b, 2, p);
        t = 1ll * t * c % p;
        r = 1ll * r * b;
    }

    if (t == 0)
        return 0;
    else
        return r;
}
```
