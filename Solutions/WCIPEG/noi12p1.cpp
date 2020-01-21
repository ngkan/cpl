#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll mod_inv(ll a,ll mod){
   ll r1 = a, r2 = mod, coef1 = 1, coef2 = 0, tmp;
   while(r1 % r2 != 0){
      ll q = r1 / r2;
      tmp = r1;
      r1 = r2;
      r2 = tmp % r2; // r1 % r2
      tmp = coef1;
      coef1 = coef2;
      coef2 = coef1 - tmp * q;// coef1 - coef2 * q;
   }
   return (coef2 + mod) % mod;
}
ll mod,a,c,x0,n,g;
ll pow2[130];
void prep(){
   pow2[0] = 1ll;
   for(int i=1;i<=120;i++)
      pow2[i] = pow2[i-1] * 2ll % mod;
}
ll mul(ll x,ll y){
   ll res = 0;
   for(int i=0;i<=60;i++)
      for(int j=0;j<=60;j++)
         if (((x>>i)&1) && ((y>>j)&1))
            res = (res + pow2[i+j]) % mod;
   return res;
}
ll zzpow(ll x,ll p){
   if (!p) return 1ll;
   ll t = zzpow(x,p/2);
   if (p%2) return mul(mul(t,t),x);
   return mul(t,t);
}
ll cal(ll a,ll p){
   if (!p) return 1ll;
   if (p%2){
      ll t = cal(a,p/2);
      return (t + mul(t, zzpow(a,p/2+1)))%mod;
   }
   ll t = cal(a,p/2-1);
   return (t + mul(t, zzpow(a,p/2)) + zzpow(a,p))%mod;
}
int main(){
   cin >> mod >> a >> c >> x0 >> n >> g;
   prep();
   cout << (mul(x0, zzpow(a,n)) + mul(c, cal(a,n-1))) % mod % g;
}
