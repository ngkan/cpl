#include <bits/stdc++.h>
#define ll long long
using namespace std;
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

ll t,n,m,fact[2005],inv[2005];
int main(){
    fact[0] = 1;
    for(int i=1;i<=2000;i++) fact[i] = fact[i-1] * i % mod;
    for(int i=0;i<=2000;i++) inv[i] = mod_inverse(fact[i],mod);
    cin >> t;
    while(t--){
        cin >> n >> m;
        m--;
        cout << fact[n+m] * inv[n] % mod * inv[m] % mod << endl;
    }
}
