#include <bits/stdc++.h>
using namespace std;
int l[5005],r[5005],u[5005],d[5005],x[5005],y[5005];
int tcd[1005][1005];
int n, test, waysize;
string s[1005], way;
void init(){
   cin >> waysize >> n;
   cin >> way;
   for(int i=1;i<=n;i++)
      cin >> s[i], s[i] = '0' + s[i];
}
void prep(){
   int xn = 0, yn = 0;
   for(int i=0;i<waysize;i++){
      x[i+1] = x[i];
      y[i+1] = y[i];
      if (way[i] == 'U') x[i+1]--;
      else if (way[i] == 'D') x[i+1]++;
      else if (way[i] == 'L') y[i+1]--;
      else y[i+1]++;
      l[i+1] = min(l[i], y[i+1]);
      r[i+1] = max(r[i], y[i+1]);
      u[i+1] = min(u[i], x[i+1]);
      d[i+1] = max(d[i], x[i+1]);
   }
   for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
         tcd[i][j] = tcd[i][j-1] + tcd[i-1][j] - tcd[i-1][j-1] + (s[i][j] == '#');
}
int gettcd(int x1,int y1,int x2,int y2){
   return tcd[x2][y2] - tcd[x1-1][y2] - tcd[x2][y1-1] + tcd[x1-1][y1-1];
}
int main(){
   iostream::sync_with_stdio(0);
   cin >> test;
   while(test--){
      init();
      prep();
      int ans = 0;
      for(int i=1;i<=n;i++){
         for(int j=1;j<=n;j++){
            if (s[i][j] == '#') continue;
            int ll = 0, rr = waysize+1;
            while(ll+1<rr){
               int mid = (ll+rr)/2;
               int un = i + u[mid];
               int dn = i + d[mid];
               int ln = j + l[mid];
               int rn = j + r[mid];
               if (un < 1 || dn > n || ln < 1 || rn > n){
                  rr = mid;
                  continue;
               }
               if (gettcd(un,ln,dn,rn) > 0)  rr = mid;
               else ll = mid;
            }
            //cout << ll << ' ' << i+x[ll] << ' ' << j+y[ll] << endl;
            while(ll<waysize){
               ++ll;
               if (i + x[ll] < 1 || i + x[ll] > n || j + y[ll] < 1 || j + y[ll] > n){
                  --ll;
                  break;
               }
               if (s[i+x[ll]][j+y[ll]] == '#'){
                  --ll;
                  break;
               }
            }
            //cout << i << ' ' << j << ' ' << ll << endl;
            ans^=ll;
         }
      }
      cout << ans << endl;
   }
}
