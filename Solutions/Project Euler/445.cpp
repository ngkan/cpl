#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = (ll) 1e9+7;
ll cnt[10000005];
ll ans = 1;
ll res = 0;
ll x = 1;
int prime[10000005];
void prep(int n = 10000000){
    for(int i=2;i<=n;i++){
        if (prime[i]) continue;
        for(int j=i;j<=n;j+=i)
            prime[j] = i;
    }
}
ll zzpow(ll x,ll p){
    if (!p) return 1;
    ll t = zzpow(x,p/2);
    if (p%2) return t*t%mod*x%mod;
    return t*t%mod;
}
int main(){
    prep();
    ll n = (ll) 1e7;
    for(ll i=1;i<n;i++){
        ll val = n+1-i;
        x = x * val % mod;
        while(val != 1){
            ll dis = prime[val];
            if (cnt[dis])
                ans = ans * zzpow(zzpow(dis,cnt[dis])+1,mod-2) % mod;
            while(val % dis == 0) cnt[dis]++, val/=dis;
            if (cnt[dis])
                ans = ans * (zzpow(dis,cnt[dis])+1) % mod;
        }
        val = i;
        x = x * zzpow(val,mod-2) % mod;
        while(val != 1){
            ll dis = prime[val];
            if (cnt[dis])
                ans = ans * zzpow(zzpow(dis,cnt[dis])+1,mod-2) % mod;
            while(val % dis == 0) cnt[dis]--, val/=dis;
            if (cnt[dis])
                ans = ans * (zzpow(dis,cnt[dis])+1) % mod;
        }
        res = (res + ans - x + mod) % mod;
        //cout << ans << endl;
    }
    cout << res;
}
