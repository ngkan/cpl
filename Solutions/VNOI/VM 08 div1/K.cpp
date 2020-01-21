#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
int n,x[1505],y[1505];
vector <iii> mjk[205][205];
int main(){
   cin >> n;
   for(int i=1;i<=n;i++)
      cin >> x[i] >> y[i],
      x[i] = 2*x[i] + 100,
      y[i] = 2*y[i] + 100;
   for(int i=1;i<=n;i++)
      for(int j=i+1;j<=n;j++){
         int X = (x[i] + x[j])/2;
         int Y = (y[i] + y[j])/2;
         assert(x[i] != x[j] || y[i] != y[j]);
         int a = abs(X - x[i]);
         int b = abs(Y - y[i]);
         if (a == 0){
            mjk[X][Y].push_back(iii(1,ii(0,0)));
            continue;
         }
         if (b == 0){
            mjk[X][Y].push_back(iii(-1,ii(0,0)));
            continue;
         }
         int gcd = __gcd(a,b);
         a/=gcd;
         b/=gcd;
         bool rem = 0;
         if (y[i] > y[j]) rem = 1, swap(x[i],x[j]), swap(y[i],y[j]);
         if (x[i] > x[j])
            mjk[X][Y].push_back(iii(1,ii(a,b)));
         else
            mjk[X][Y].push_back(iii(-1,ii(a,b)));
         if (rem)
            swap(x[i],x[j]), swap(y[i],y[j]);
      }
   int ans = 0;
   for(int i=0;i<=200;i++)
      for(int j=0;j<=200;j++){
         sort(mjk[i][j].begin(), mjk[i][j].end());
         for(int k=0;k<mjk[i][j].size();k++){
            iii thiss = iii(0-mjk[i][j][k].fi, ii(mjk[i][j][k].se.se, mjk[i][j][k].se.fi));
            int vl;
            vl = upper_bound(mjk[i][j].begin()+k+1, mjk[i][j].end(), thiss) - mjk[i][j].begin();
            vl -= lower_bound(mjk[i][j].begin()+k+1, mjk[i][j].end(), thiss) - mjk[i][j].begin();
            ans += vl;
            //if (vl) cout << i << ' ' << j << ' ' << vl << endl;
         }
      }
   cout << ans;
}
