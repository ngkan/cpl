#include <bits/stdc++.h>
#define mod1 1024ll
#define mod2 9765625ll
#define fi first
#define se second
using namespace std;
long long res1,res2,n;
long long zzpow1(long long x,long long p){
    if (p == 0) return 1;
    long long tmp = zzpow1(x,p/2);
    if (p%2) return tmp * tmp % mod1 * x % mod1;
    return tmp * tmp % mod1;
}
long long zzpow2(long long x,long long p){
    if (p == 0) return 1;
    long long tmp = zzpow2(x,p/2);
    if (p%2) return tmp * tmp % mod2 * x % mod2;
    return tmp * tmp % mod2;
}
long long mod_inverse(long long a,long long mod){
    // gcd(a,m) must equal to 1
    long long r1 = a, r2 = mod, x1 = 1,x2 = 0, q, tmp;
    while(r2 != 0){
        q = r1 / r2;
        tmp = x1 -  q * x2;
        x1 = x2;
        x2 = tmp;
        tmp = r1 % r2;
        r1 = r2;
        r2 = tmp;
    }
    return x1;
}
int main(){
    cin >> n;
    for(long long i=1;i<=n;i++){
        res1 = (res1 + zzpow1(i,i)) % mod1;
        res2 = (res2 + zzpow2(i,i)) % mod2;
    }
    long long res = res1 * mod2 * mod_inverse(mod2,mod1) + res2 * mod1 * mod_inverse(mod1,mod2) ;
    cout << res % 10000000000;
}
