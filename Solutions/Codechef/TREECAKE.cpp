#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = (ll) 1e9+7;
ll zzpow(ll x,ll p){
    if (!p) return 1;
    ll t = zzpow(x,p/2);
    if (p%2) return t*t%mod*x%mod;
    return t*t%mod;
}
struct matrix{
    ll n,m;
    vector < vector<ll> > ele;
    void init(){
        ele.assign(n+1,vector<ll>());
        for(int i=1;i<=n;i++)   ele[i].assign(m+1,0);
    }
    matrix operator * (matrix y){
        ll p = y.m;
        matrix res;
        res.n = n, res.m = p;
        res.init();
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                for(int k=1;k<=p;k++)
                    res.ele[i][k] = (res.ele[i][k] + ele[i][j] * y.ele[j][k] % mod);
        return res;
    }
};
matrix fib,base;
ll p,inv2 = 500000004;
int test;
int main(){
    scanf("%d",&test);
    while(test--){
        fib.n = 1, fib.m = 2;
        base.n = 2, base.m = 2;
        fib.init(), base.init();
        fib.ele[1][1] = 1, fib.ele[1][2] = 1;
        base.ele[1][1] = 0, base.ele[1][2] = 1;
        base.ele[2][1] = 1, base.ele[2][2] = 1;
        scanf("%lld",&p);
        p=max(0ll,p-2);
        for(ll i=0;i<=60;i++){
            if (((1ll<<i)&p)) fib = fib * base;
            base = base * base;
        }
        if (p%3 == 1) printf("%lld\n",fib.ele[1][2] * inv2 % mod);
        else printf("%lld\n",(fib.ele[1][2] + 1 + mod) % mod * inv2 % mod);
    }
}
