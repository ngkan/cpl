#include <bits/stdc++.h>
using namespace std;

// calculate (1/a) % mod, only works when gcd(a, mod) = 1
template<typename T>
T mod_inverse(T a,T mod){
    T r1 = a, r2 = mod, x1 = 1,x2 = 0, q, tmp;
    while(r2 != 0){
        q = r1 / r2;
        tmp = x1 -  q * x2;
        x1 = x2;
        x2 = tmp;
        tmp = r1 % r2;
        r1 = r2;
        r2 = tmp;
    }
    return (x1+mod) % mod;
}
