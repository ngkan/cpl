#include <bits/stdc++.h>
using namespace std;
int n,m,x,y;
vector <int> G[1005];
int f[1005][1005];
map<int,double> chance[1005][1005];
map<int,bool> oked[1005][1005];
struct cmp{
   bool operator ()(int a,int b){
      return (f[a/1500000][(a%1500000)/1005] < f[b/1500000][(b%1500000)/1005]);
   }
};
priority_queue <int,vector<int>,cmp> pq;
void dijkstra(int root){
   queue <int> q;
   q.push(root);
   while(q.size()){
      int u = q.front();
      q.pop();
      for(int i=0;i<G[u].size();i++){
         int v = G[u][i];
         if (v == root) continue;
         if (!f[root][v])
            f[root][v] = f[root][u] + 1,
            q.push(v);
      }
   }
}
int main(){
   scanf("%d %d",&n,&m);
   scanf("%d %d",&x,&y);
   for(int i=1;i<=m;i++){
      int u,v;
      scanf("%d %d",&u,&v);
      G[u].push_back(v);
      G[v].push_back(u);
   }
   for(int i=1;i<=n;i++)
      dijkstra(i);

   chance[x][y][0] = 1.0;
   oked[x][y][0] = 1;
   pq.push(x * 1500000 + y * 1005);
   double ans = 0;
   while(pq.size()){
      int u = pq.top();
      pq.pop();
      int x = u/1500000;
      int y = (u%1500000 / 1005);
      int t = (u%1500000) % 1005;
      if (x == y)
         ans += 1.0 * chance[x][y][t] * t;
      else if (f[x][y] <= 2)
         ans += 1.0 * chance[x][y][t] * (1 + t);
      else{
         int nlv = t + 1, xx = 1000000;
         double nc = chance[x][y][t];
         for(int i=0;i<G[x].size();i++)
            if (f[x][y] == f[G[x][i]][y] + 1) xx = min(xx, G[x][i]);
         x = xx;
         xx = 1000000;
         for(int i=0;i<G[x].size();i++)
            if (f[x][y] == f[G[x][i]][y] + 1) xx = min(xx, G[x][i]);
         x = xx;

         for(int i=0;i<G[y].size();i++){
            chance[x][G[y][i]][t+1] += nc / (1.0 * (G[y].size() + 1));
            if (!oked[x][G[y][i]][t+1])
               oked[x][G[y][i]][t+1] = 1,
               pq.push(x * 1500000 + G[y][i] * 1005 + t + 1);
         }
         chance[x][y][t+1] += nc / (1.0 * (G[y].size() + 1));
         if (!oked[x][y][t+1])
            oked[x][y][t+1] = 1,
            pq.push(x * 1500000 + y * 1005 + t + 1);
      }
   }
   cout << fixed << setprecision(3) << ans;
}
