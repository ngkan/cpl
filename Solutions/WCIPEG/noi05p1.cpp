#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int,int> ii;
int n,m,x,y,k;
bool ok[205][205];
int dp[205][205][205];
string s;
int main(){
   cin >> n >> m >> x >> y >> k;
   for(int i=1;i<=n;i++){
      cin >> s;
      for(int j=0;j<m;j++) ok[i][j+1] = (s[j] == '.');
   }
   for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
         for(int l=0;l<=k;l++)
            dp[i][j][l] = (int) -1e9;
   dp[x][y][0] = 0;
   for(int id=0;id<k;id++){
      int s,t,d;
      cin >> s >> t >> d;
      if (d == 1){
         d = t - s + 1;
         for(int j=1;j<=m;j++){
            deque <ii> dq;
            for(int i=n;i>=1;i--){
               if (!ok[i][j]){
                  dq.clear();
                  continue;
               }
               while(dq.size() && dq.front().se - d > i) dq.pop_front();
               while(dq.size() && dq.back().fi + (dq.back().se - i) <= dp[i][j][id]) dq.pop_back();
               dq.push_back(ii(dp[i][j][id], i));
               dp[i][j][id+1] = dq.front().fi + (dq.front().se - i);
            }
         }
      }
      else if (d == 2){
         d = t - s + 1;
         for(int j=1;j<=m;j++){
            deque <ii> dq;
            for(int i=1;i<=n;i++){
               if (!ok[i][j]){
                  dq.clear();
                  continue;
               }
               while(dq.size() && dq.front().se + d < i) dq.pop_front();
               while(dq.size() && dq.back().fi + (i - dq.back().se) <= dp[i][j][id]) dq.pop_back();
               dq.push_back(ii(dp[i][j][id], i));
               dp[i][j][id+1] = dq.front().fi + (i - dq.front().se);
            }
         }
      }
      else if (d == 3){
         d = t - s + 1;
         for(int i=1;i<=n;i++){
            deque <ii> dq;
            for(int j=m;j>=1;j--){
               if (!ok[i][j]){
                  dq.clear();
                  continue;
               }
               while(dq.size() && dq.front().se - d > j) dq.pop_front();
               while(dq.size() && dq.back().fi + (dq.back().se - j) <= dp[i][j][id]) dq.pop_back();
               dq.push_back(ii(dp[i][j][id], j));
               dp[i][j][id+1] = dq.front().fi + (dq.front().se - j);
            }
         }
      }
      else{
         d = t - s + 1;
         for(int i=1;i<=n;i++){
            deque <ii> dq;
            for(int j=1;j<=m;j++){
               if (!ok[i][j]){
                  dq.clear();
                  continue;
               }
               while(dq.size() && dq.front().se + d < j) dq.pop_front();
               while(dq.size() && dq.back().fi + (j - dq.back().se) <= dp[i][j][id]) dq.pop_back();
               dq.push_back(ii(dp[i][j][id], j));
               dp[i][j][id+1] = dq.front().fi + (j - dq.front().se);
            }
         }
      }
   }
   int ans = 0;
   for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
         ans = max(ans, dp[i][j][k]);
   cout << ans;
}
/*
4 5 4 1 1
..xx.
.....
...x.
.....
1 3 4
*/
