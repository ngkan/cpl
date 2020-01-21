#include <bits/stdc++.h>
#define ll long long
#define ff(i,a,b) for(int i=(a);i<=(b);i++)
#define fb(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const ll mod = (ll) 1e9 + 7;
const ll _M = (ll) 5e5 + 5;
ll fact[_M],inv[_M];
ll zzpow(ll x,ll p){
    if (!p) return 1ll;
    ll t = zzpow(x,p/2);
    if (p % 2 == 0) return t * t % mod;
    return t * t % mod * x % mod;
}
long long mod_inverse(long long a,long long mod){
    // gcd(a,m) must equal to 1
    // calucate a^(-1) % mod
    // khung hon fermat
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
    return (x1+mod+mod)%mod;
}
void pre_fact(){
    fact[0] = 1ll;
    ff(i,1,(int)5e5) fact[i] = (fact[i-1] * i) % mod;
    ff(i,0,(int)5e5) inv[i] = mod_inverse(fact[i],mod);
}
ll Ckn(ll k,ll n){
    return fact[n] * inv[k] % mod * inv[n-k] % mod;
}
ll test,n,m,ans;
int main(){
    pre_fact();
    cin >> test;
    while(test--){
        cin >> m >> n;
        ans = zzpow(n,m);
        ff(i,0,n-1)
            ans = (ans - zzpow(n-1,m-i) * Ckn(i,m) % mod+ mod + mod) % mod;
        cout << ans << endl;
    }
}
