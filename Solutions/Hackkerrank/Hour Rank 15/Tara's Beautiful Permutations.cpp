#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,q,ahi,ans,a[2005],dp[2005][1005];
ll fact[5005],inv[5005],p2[5005],invp2[5005];
const ll mod = (ll) 1e9+7;
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
ll Ckn(ll k,ll n){
    return fact[n] * inv[k] % mod * inv[n-k] % mod;
}
map <int,int> cnt;
int main(){
    fact[0] = p2[0] = 1;
    for(int i=1;i<=5000;i++)    fact[i] = (fact[i-1] * i) % mod, p2[i] = p2[i-1] * 2 % mod;
    for(int i=0;i<=5000;i++)    inv[i] = mod_inverse(fact[i],mod), invp2[i] = mod_inverse(p2[i],mod);
    scanf("%lld",&q);
    while(q--){
        cnt.clear();
        ans = ahi = 0;
        scanf("%lld",&n);
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            ahi += (++cnt[a[i]] == 2);
        }
        for(int i=0;i<=ahi;i++){
            if (i%2==0) ans = (ans + fact[n-i] * Ckn(i,ahi) % mod * p2[i] % mod)%mod;
            else ans = (ans - fact[n-i] * Ckn(i,ahi) % mod * p2[i] % mod + mod)%mod;
            cout << ans << endl;
        }

        ans = ans * invp2[ahi] % mod;
        printf("%lld\n",ans);
    }
}
