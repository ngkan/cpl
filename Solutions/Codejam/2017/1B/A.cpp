#include <bits/stdc++.h>
#define int long long
using namespace std;
int test;
int d,n;
signed main(){
   freopen("A-large.in","r",stdin);
   freopen("Aout.txt","w",stdout);
   cin >> test;
   for(int t=1;t<=test;t++){
      cin >> d >> n;
      double ans = 5e18;
      for(int i=1;i<=n;i++){
         int k,s;
         cin >> k >> s;
         ans = min(ans, 1.0 * d / (1.0 * (d-k) / s));
      }
      cout << fixed << setprecision(6) << "Case #" << t << ": " << ans << endl;
   }
}
