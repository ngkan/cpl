#include <bits/stdc++.h>
using namespace std;
struct edge{
   int v,w;
   edge(int v=0,int w=0): v(v), w(w) {}
};
int n,m,k,numchild[305];
int dp[305][305][2];
vector <edge> G[305];
void dfs(int u,int p){
   numchild[u] = 1;
   dp[u][0][0] = 0;
   dp[u][1][1] = 0;
   for(int z=0;z<G[u].size();z++){
      int v = G[u][z].v;
      int w = G[u][z].w;
      if (v == p) continue;
      dfs(v,u);
      int f[numchild[u] + numchild[v]][2];
      for(int i=0;i<=numchild[u]+numchild[v];i++)
         f[i][0] = f[i][1] = (int) 1e9;
      for(int i=0;i<=numchild[u];i++){
         for(int j=0;j<=numchild[v];j++){
            f[i+j][0] = min(f[i+j][0], dp[u][i][0] + dp[v][j][0] + (m == 2) * w);
            f[i+j][0] = min(f[i+j][0], dp[u][i][0] + dp[v][j][1]);
            f[i+j][1] = min(f[i+j][1], dp[u][i][1] + dp[v][j][0]);
            f[i+j][1] = min(f[i+j][1], dp[u][i][1] + dp[v][j][1] + w);
         }
      }
      numchild[u] += numchild[v];
      for(int i=0;i<=numchild[u];i++)
         dp[u][i][0] = f[i][0],
         dp[u][i][1] = f[i][1];
   }
}
int main(){
   for(int i=0;i<=300;i++) for(int j=0;j<=300;j++)
      dp[i][j][0] = dp[i][j][1] = (int) 1e9;
   scanf("%d %d %d",&n,&m,&k);
   for(int i=1;i<n;i++){
      int x,y,w;
      scanf("%d %d %d",&x,&y,&w);
      G[x].push_back(edge(y,w));
      G[y].push_back(edge(x,w));
   }
   if (m+k-1>n) return printf("-1"),0;
   dfs(1,1);
   printf("%d",dp[1][k][1]);
}
