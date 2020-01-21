#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,a[20],c[20],p[20],l[20], need;
int phi[1000005];
int zzpow(int x,int p,int mod){
   int mjk = x;
   int res = 1;
   for(int bit=0;(1<<bit)<=p;++bit){
      if ((p>>bit)&1) res = 1ll * res * mjk % mod;
      mjk = 1ll * mjk * mjk % mod;
   }
   return res;
}
void prep(){
   for(int i=2;i<=1000000;++i){
      if (phi[i]) continue;
      for(int j=i;j<=1000000;j+=i){
         if (!phi[j]) phi[j] = j;
         phi[j] = phi[j] / i * (i-1);
      }
   }
}
int main(){
   prep();
   scanf("%d",&n);
   for(int i=1;i<=n;i++)
      scanf("%d %d %d",&c[i],&p[i],&l[i]),
      need = max(need, c[i]);
   int a,x,mjk,rest,t;
   for(int res=need;;++res){
      assert(res <= 1000000);
      bool ok = 1;
      for(int i=1;i<=n;++i){
         if (!ok) break;
         for(int j=i+1;j<=n;++j){
            a = c[i] - c[j] + res;
            x = (p[i] - p[j])%res + res;
            if (a%res==0) {ok = 0;break;}
            if (x==res) continue;
            a = res-a;
            mjk = __gcd(x, res);
            if (a % mjk) continue;
            rest = res;
            a /= mjk;
            x /= mjk;
            rest /= mjk;
            t = 1ll * a * zzpow(x, phi[rest] - 1, rest) % rest;
            if (t <= min(l[i], l[j])) {ok = 0; break;}
         }
      }
      if (ok) return printf("%d",res),0;
   }
}
