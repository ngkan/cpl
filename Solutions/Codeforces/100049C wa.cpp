#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007ll;
long long fact[1000005],inv[1000005];
long long _(long long x){
    return (x%mod+mod)%mod;
}
long long _pow(long long x,long long p){
    if (!p) return 1ll;
    long long t = _pow(x,p/2);
    if (p%2) return t*t%mod*x%mod;
    return t*t%mod;
}
long long mod_inverse(long long a,long long mod){
    // calucate a^(-1) % mod
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
    return _(x1);
}
void pre(long long x){
    fact[0] = 1ll;
    for(long long i=1;i<=x;i++) fact[i] = (fact[i-1] * i) % mod;
    for(long long i=0;i<=x;i++) inv[i] = mod_inverse(fact[i],mod);
}
long long Ckn(long long k,long long n){
    return fact[n] * inv[k] % mod * inv[n-k] % mod;
}
long long f[1000005];  // so cach to dung i mau cho n box
long long cal(long long num_color,long long box){
    if (f[num_color] != -1) return f[num_color];
    long long res = _pow(num_color,box);    // so cach to mau cho boxes
    for(long long i=1;i<num_color;i++)
        res = _(res - Ckn(i,num_color) * f[i]);
    return f[num_color] = res;
}
long long n,m,k,ans;
int main(){
    pre(1000000);
    for(int i=0;i<=1000000;i++) f[i] = -1;
    cin >> n >> m >> k;
    f[1] = 1;
    if (m == 1) return cout << _pow(k,n*m),0;
    if (m == 2){
        for(long long color = 1;color <= min(k,n);color ++){
            ans = _(ans + cal(color,n) * cal(color,n) % mod * Ckn(color,k) % mod * Ckn(color,k) % mod);
        }
        return cout << ans, 0;
    }
    for(long long color = 1;color <= min(k,n);color ++){
        ans = _(ans + cal(color,n) * cal(color,n) % mod * _pow(color,n*(m-2)) % mod * Ckn(color,k) % mod);
    }
    cout << ans;
}
