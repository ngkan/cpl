/**
 * Modular multiplicative inverse
 * Author: ngkan
 * Description: find a' such that a * a' = 1 mod m, if such a' exists.
 * Complexity: O(log^2)
 * Status: OK
 */

int mod_inverse(int a, int mod){
    int r1 = a, r2 = mod, x1 = 1, x2 = 0, q, tmp;
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
