#include <bits/stdc++.h>
#define x first
#define y second
#define ll long long
using namespace std;
typedef pair<ll,ll> ii;
vector <ii> lst[1000005];
int n,m;
int a[1005][1005], mark[1005][1005];
ll dp[1005][1005];
int main(){
   scanf("%d %d",&n,&m);
   for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
         scanf("%d",&a[i][j]),
         lst[a[i][j]].push_back(ii(i,j));
   for(int i=0;i<=n;i++)
      fill(mark[i],mark[i]+m+5,99999999);
   for(int i=0;i<=1000000;i++)
      for(int j=0;j<lst[i].size();j++)
         mark[lst[i][j].x][lst[i][j].y] = i;
   for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
         mark[i][j] = min(mark[i][j], min(mark[i-1][j], mark[i][j-1]));
   for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
            dp[i][j] = max(dp[i-1][j] + mark[i][j] * j,
                           dp[i][j-1] + mark[i][j] * i);
   printf("%lld",dp[n][m]);
}
