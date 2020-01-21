#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = (ll) 1e9+7;
ll n,m,x[100005],y[100005];
int main(){
   iostream::sync_with_stdio(0);
   cin >> n >> m;
   for(int i=1;i<=n;i++) cin >> x[i];
   for(int j=1;j<=m;j++) cin >> y[j];
   ll totalx = 0, totaly=0;
   for(int i=2;i<=n;i++){
      totalx = (totalx + (x[i] - x[i-1]) * (i-1) * (n-i+1)) % mod;
   }
   for(int i=2;i<=m;i++){
      totaly = (totaly + (y[i] - y[i-1]) * (i-1) * (m-i+1)) % mod;
   }
   cout << totalx * totaly % mod;
}
