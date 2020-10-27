/**
 * Binary Exponentiation
 * Author: ngkan
 * Description: Calculate a^n % mod.
 * Complexity: O(log n)
 * Status: Tested
 */

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