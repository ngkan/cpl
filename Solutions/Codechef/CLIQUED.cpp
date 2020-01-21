#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
typedef pair<ll,int> ii;
struct edge{
   int v; ll w;
   edge(int v=0,ll w=0ll): v(v), w(w) {}
};
int t,n,k;
ll x,m,s;
vector <edge> G[100005];
ll d[100005];
priority_queue <ii,vector<ii>,greater<ii> > pq;
void dijkstra(){
   for(int i=1;i<=n;i++) d[i] = (ll) 1e18;
   d[s] = 0;
   pq.push(ii(0,s));
   bool ahi = 0;
   while(pq.size()){
      int u = pq.top().se;
      ll du = pq.top().fi;
      pq.pop();
      if (du != d[u]) continue;
      if (u <= k && !ahi){
         ahi = 1;
         for(int i=1;i<=k;i++)
            if (d[i] > d[u] + x)
               d[i] = d[u] + x,
               pq.push(ii(d[i],i));
      }
      for(int i=0;i<G[u].size();i++){
         int v = G[u][i].v;
         if (d[v] > d[u] + G[u][i].w)
            d[v] = d[u] + G[u][i].w,
            pq.push(ii(d[v], v));
      }
   }

}
int main(){
   cin >> t;
   while(t--){
      cin >> n >> k >> x >> m >> s;
      for(int i=1;i<=n;i++) G[i].clear();
      while(m--){
         int x,y; ll w;
         cin >> x >> y >> w;
         G[x].push_back(edge(y,w));
         G[y].push_back(edge(x,w));
      }
      dijkstra();
      for(int i=1;i<=n;i++) cout << d[i] << ' '; cout << '\n';
   }
}
