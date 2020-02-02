#include <bits/stdc++.h>
using namespace std;
string s;
int n,dp[1005][1005],ans;
int main(){
   cin >> n >> s;
   s = '0' + s;
   ans = n;
   for(int len=1;len<n;len++){
      int pos = len+1;

      for(int i=1;i<=len;i++)
         for(int j=pos;j<=n;j++)
            if (s[i] == s[j])
               dp[i][j] = max(dp[i-1][j], max(dp[i][j-1], dp[i-1][j-1] + 1));
            else
               dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

      ans = min(ans, n - 2 * dp[len][n]);

      for(int i=1;i<=len;i++)
         for(int j=pos;j<=n;j++)
            dp[i][j] = 0;
   }
   cout << ans;
}
