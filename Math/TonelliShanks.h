/**
 * Tonelli–Shanks algorithm
 * Author: ngkan
 * Description: give n and p odd prime, find x such that x**2 = n mod p, if such
 * x exists.
 * Complexity: O(log^2) (?)
 * Status: Tested
 *   > judge.yosupo.jp: t = 100000, 309ms
 */

#include "BinaryExponentiation.h"
mt19937 rng(std::chrono::system_clock::now().time_since_epoch().count());

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