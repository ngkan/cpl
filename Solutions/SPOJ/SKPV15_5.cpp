#include <bits/stdc++.h>
#define ll long long
using namespace std;
int prime[1000005];
ll cnt[1000005];
const int N = (int) 1e6;
const ll mod = (ll) 1e9+9;
vector <int> pr;
ll zzpow(ll x,ll p){
    if (!p) return 1ll;
    ll t = zzpow(x,p/2);
    if (p%2) return t*t%mod*x%mod;
    return t*t%mod;
}
void era(){
    for(int i=2;i<=1000;i++){
        if (prime[i]) continue;
        for(int j=i;j<=1000000;j+=i)
            prime[j] = i;
    }
    for(int i=1001;i<=1000000;i++)
        if (!prime[i]) prime[i] = i;
    for(int i=2;i<=N;i++)
        if (prime[i] == i) pr.push_back(i);
}
int m,n,k;
int main(){
    era();
    scanf("%d %d %d",&m,&n,&k);
    for(int i=1;i<=m;i++){
        int x;
        scanf("%d",&x);
        while(prime[x])
            cnt[prime[x]]--,
            x/=prime[x];
    }
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        while(prime[x])
            cnt[prime[x]]++,
            x/=prime[x];
    }
    for(int i=0;i<pr.size();i++)
        if (cnt[pr[i]] < 0) return cout << 0,0;
    ll ans = 1;
    for(int i=0;i<pr.size();i++)
        if (cnt[pr[i]])
            ans = (zzpow(cnt[pr[i]]+1,k) - 2ll*zzpow(cnt[pr[i]],k) + zzpow(cnt[pr[i]]-1,k) + mod*4ll) % mod * ans % mod;
    printf("%lld",ans);
}
