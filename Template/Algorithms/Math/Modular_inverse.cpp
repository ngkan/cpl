#include <bits/stdc++.h>
using namespace std;

/*
    Calculate (1/a) % mod based on Euclidean algorithm.
    Only works when gcd(a, mod) = 1.
    Status: Untested
*/

int mod_inverse(int a,int mod){
    int r1 = a, r2 = mod, x1 = 1,x2 = 0, q, tmp;
    while(r2 != 0){
        q = r1 / r2;
        tmp = x1 -  q * x2;
        x1 = x2;
        x2 = tmp;
        tmp = r1 % r2;
        r1 = r2;
        r2 = tmp;
    }
    return (x1 + mod) % mod;
}
