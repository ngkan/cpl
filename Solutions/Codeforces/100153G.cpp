#include <bits/stdc++.h>
using namespace std;
const int mod = 10003;
int m,n,k,dp[55][55][55];
void add(int &x,int val){
   x = (x + val)%mod;
}
int main(){
   freopen("rooks.in","r",stdin);
   freopen("rooks.out","w",stdout);
   dp[0][0][0] = 1;
   cin >> m >> n >> k;
   for(int row=0;row<=m;row++){
      for(int col1=0;col1<=n;col1++){
         for(int col2=0;col2<=n-col1;col2++){
            if (col1 + 2*col2 <= k)
               add(dp[row+1][col1][col2], dp[row][col1][col2]);
            if (col1 + 2*col2 + 1 <= k){
               add(dp[row+1][col1+1][col2],(n-col1-col2)*dp[row][col1][col2]);
               if (col1>=1)
               add(dp[row+1][col1-1][col2+1],col1*dp[row][col1][col2]);
            }
            if (col1 + 2*col2 + 2 <= k){
               add(dp[row+1][col1+2][col2], (n-col1-col2) * (n-col1-col2-1) / 2 * dp[row][col1][col2]);
               if (col1 >= 1)
               add(dp[row+1][col1][col2+1], (n-col1-col2) * col1 * dp[row][col1][col2]);
               if (col1>=2)
               add(dp[row+1][col1-2][col2+2], col1 * (col1-1) / 2* dp[row][col1][col2]);
            }
         }
      }
   }
   int ans = 0;
   for(int i=0;i<=n;i++)
      for(int j=0;j<=n;j++)
         if (i + 2*j == k)
            add(ans, dp[m][i][j]);

   cout << ans;
}
