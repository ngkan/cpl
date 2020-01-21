#include <bits/stdc++.h>
using namespace std;
const int MAX = (int) 1e9;
int n,N,m;
vector <int> G[100005];
int pairL[100005], pairR[100005], d[100005];
bool bfs_match(){
   queue <int> q;
   for(int i=1;i<=n;i++)
      if (!pairL[i]) q.push(i), d[i] = 0;
      else d[i] = MAX;
   d[0] = MAX;
   while(q.size()){
      int u = q.front();
      q.pop();
      if (d[u] >= d[0]) continue;
      for(int i=0;i<G[u].size();i++){
         int v = G[u][i];
         if (d[pairR[v]] == MAX)
            d[pairR[v]] = d[u] + 1,
            q.push(pairR[v]);
      }
   }
   return d[0] != MAX;
}
bool dfs(int u){
   if (u == 0) return 1;
   for(int i=0;i<G[u].size();i++){
      int v = G[u][i];
      if (d[pairR[v]] == d[u] + 1 && dfs(pairR[v])){
         pairR[v] = u;
         pairL[u] = v;
         return 1;
      }
   }
   d[u] = MAX;
   return 0;
}
int main(){
   scanf("%d %d %d",&n,&N,&m);
   while(m--){
      int x,y;
      scanf("%d %d",&x,&y);
      G[x].push_back(y+n);
   }
   int match = 0;
   while(bfs_match()){
      for(int i=1;i<=n;i++)
         if (!pairL[i])
            match += dfs(i);
   }
   printf("%d",match);
}
