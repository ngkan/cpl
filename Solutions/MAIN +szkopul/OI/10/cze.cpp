#include <bits/stdc++.h>
using namespace std;
int m,n,x[1000],y[1000],dp[1000][1000];
int main(){
   scanf("%d %d",&n,&m);
   n--,m--;
   for(int i=1;i<=n;i++)   scanf("%d",&x[i]);   sort(x+1,x+n+1,greater<int>());
   for(int i=1;i<=m;i++)   scanf("%d",&y[i]);   sort(y+1,y+m+1,greater<int>());
   for(int i=0;i<=n;i++) for(int j=0;j<=m;j++) dp[i][j] = (int) 1e9;
   dp[0][0] = 0;
   for(int i=0;i<=n;i++){
      for(int j=0;j<=m;j++){
         if (i)
            dp[i][j] = min(dp[i][j], dp[i-1][j] + (j+1) * x[i]);
         if (j)
            dp[i][j] = min(dp[i][j], dp[i][j-1] + (i+1) * y[j]);
      }
   }
   printf("%d",dp[n][m]);
}
