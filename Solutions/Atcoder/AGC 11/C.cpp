#include <bits/stdc++.h>
using namespace std;
int n,m;
vector <int> G[100005];
bool ok;
int color[100005], cnt, edge, CA, CB;
void dfs(int u){
   cnt++;
   for(int i=0;i<G[u].size();i++){
      int v = G[u][i];
      if (color[v]){
         if (color[u] == color[v]) ok = 0;
         continue;
      }
      else{
         edge++;
         color[v] = 3 - color[u];
         dfs(v);
      }
   }
}
int main(){
   scanf("%d %d",&n,&m);
   while(m--){
      int x,y;
      scanf("%d %d",&x,&y);
      G[x].push_back(y);
      G[y].push_back(x);
   }
   long long ans = 1ll * n * n;
   long long totalv = 0, totale = 0;
   for(int i=1;i<=n;i++){
      if (color[i]) continue;
      if (G[i].empty()) continue;
      ok = 1;
      cnt = 0;
      edge = 0;
      color[i] = 1;
      dfs(i);
      if (ok) ans -= (1ll * cnt * cnt - 2);
      else ans -= (1ll * cnt * cnt - 1);
      if (ok) ans -= 2ll * (totalv * cnt - 2ll * CA - 1ll * CB);
      else ans -= 2ll * (totalv * cnt - CA - CB);
      totalv += cnt;
      if (ok) CA++;
      else CB++;
   }
   printf("%lld",ans);
}
