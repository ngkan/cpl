#include <bits/stdc++.h>
using namespace std;
int n,money;
int v[105], c[105];
vector <int> G[105];
int dp[105][2005];

int dfs(int u,int p){
   int cap = c[u];
   dp[u][c[u]] = v[u];
   for(int i=0;i<G[u].size();i++){
      int v = G[u][i];
      if (v == p) continue;
      int tmp[2005];
      fill(tmp,tmp+2005,(int) -1e9);
      int dcap = dfs(v,u);

      for(int j=0;j<=cap;j++)
         for(int k=0;k<=dcap;k++)
            if (j + k <= 2000) tmp[j+k] = max(tmp[j+k], dp[u][j] + dp[v][k]);
      cap += dcap;
      cap = min(cap, 2000);
      for(int j=0;j<=cap;j++)
         dp[u][j] = max(dp[u][j], tmp[j]);
   }
   return cap;
}
int main(){
   scanf("%d %d",&n,&money);
   for(int i=2;i<=n;i++)   scanf("%d",&v[i]);
   for(int i=2;i<=n;i++)   scanf("%d",&c[i]);
   for(int i=1;i<n;i++){
      int x,y;
      scanf("%d %d",&x,&y);
      G[x].push_back(y);
      G[y].push_back(x);
   }
   for(int i=1;i<=100;i++) for(int j=0;j<=2000;j++) dp[i][j] = (int) -1e9;
   dfs(1,1);
   int ans = 0;
   for(int i=0;i<=money;i++) ans = max(ans, dp[1][i]);
   printf("%d",ans);
}
