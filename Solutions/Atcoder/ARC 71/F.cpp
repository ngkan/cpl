#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = (ll) 1e9+7;
int n;
ll f[2000005], ax[2000005];
int main(){
   cin >> n;
   f[0] = 1;
   ll ans = 0, tmp = 0;
   for(int i=0;i<n;i++){
      tmp = (tmp + ax[i]) % mod;
      f[i] = (f[i] + tmp) % mod;
      if (i == n-1)
         ans = (ans + f[i] * n) % mod;
      else{
         ans = (ans + f[i] * (n-1) % mod * (n-1) % mod) % mod;
         ans = (ans + (i+1) * f[i]) % mod;
         if (i == n-1) ans = (ans - f[i] + mod) % mod;
      }
      if (i != n-1)
      ax[i+1] = (ax[i+1] + f[i]) % mod,
      ax[i+2] = (ax[i+2] - f[i] + mod) % mod,
      ax[i+3] = (ax[i+3] + f[i]) % mod;
      //cout << i << ' ' << ans << ' ' << f[i] << endl;
   }
   tmp = (tmp + ax[n]) % mod;
   f[n] = (f[n] + tmp) % mod;
   ans = (ans + f[n]) % mod;
//   for(int i=n;i<=n;i++){
//      tmp = (tmp + ax[i]) % mod;
//      f[i] = (f[i] + tmp) % mod;
//      ans =  (ans + f[i]) % mod;
//   }
   cout << ans;
}
