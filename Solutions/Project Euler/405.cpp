#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 410338673ll;

ll haimubangmot = 193100552;// chay trau
ll pow2 = 152370032;

ll bonmubangmot = 96550276;
ll pow4 = 55819756;

ll mod_inv(ll a){
    ll r1 = a, r2 = mod, x1 = 1,x2 = 0, q, tmp;
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

ll zzpow(ll x,ll p,ll MOD){
    if (!p) return 1ll;
    ll t = zzpow(x,p/2,MOD);
    if (p%2) return t*t%MOD*x%MOD;
    return t*t%MOD;
}

ll check1(int n){
    // l = 2 hcn xep hinh chu L giao nhau tai i
    // g = 2 hcn xep chong len nhau canh dai = i
    // d = do dai canh
    // f = res
    ll d[3], f[3], l[3], g[3];
    memset(d,0,sizeof(d));
    memset(f,0,sizeof(f));
    memset(l,0,sizeof(l));
    memset(g,0,sizeof(g));
    for(int i=1;i<=n;i++){
        f[0] = f[1];
        f[1] = f[2];
        d[0] = d[1];
        d[1] = d[2];
        d[2] = (2 + d[1] + d[0] * 2) % mod;
        l[0] = l[1];
        l[1] = l[2];
        //g[0] = g[1];
        //g[1] = g[2];
        //g[2] = (1 + 2 * l[0]) % mod;
        l[2] = (l[1] + 2 * l[0] + 1) % mod;
        f[2] = (4ll * f[1] + d[1] + 4 * l[0]) % mod;
    }
    return f[2];
}

double check2(int n){
    return 4.0/3*pow(2,n)*(pow(2,n)-1) - (pow(4,n)-1) + (pow(4,n) + pow(-1,n+1)) / 15;
}

int main(){
    cout << check2(6);
    // tinh 2 ^ x = 1 mod 17^7
    haimubangmot = 1;
    for(int i=1;;i++){
        haimubangmot = haimubangmot * 2 % mod;
        if (haimubangmot == 1){
            haimubangmot = i;
            break;
        }
    }

    // tinh 4 ^ x = 1 mod 17^7
    bonmubangmot = 1;
    for(int i=1;;i++){
        bonmubangmot = bonmubangmot * 4 % mod;
        if (bonmubangmot == 1){
            bonmubangmot = i;
            break;
        }
    }

    pow2 = zzpow(10,(ll)1e18,haimubangmot);
    pow4 = zzpow(10,(ll)1e18,bonmubangmot);

    ll ans = 0;
    ans = 1ll * 4 * mod_inv(3) % mod * zzpow(2,pow2,mod) % mod * (zzpow(2,pow2,mod) - 1 + mod) % mod;
    ans = (ans - zzpow(4,pow4,mod) + 1 + mod)% mod;
    ans = (ans + (zzpow(4,pow4,mod) - 1 + mod) * mod_inv(15) % mod) % mod;
    cout << ans;
}
