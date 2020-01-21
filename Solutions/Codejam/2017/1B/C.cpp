#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<double,int> di;
priority_queue <di,vector<di>,greater<di> > pq;
int test,n,q,e[105],s[105];
double d[105][105];
double dis[105];
int main(){
   freopen("C-large.in","r",stdin);
   freopen("Cout.txt","w",stdout);
   cin >> test;
   for(int t=1;t<=test;t++){
      vector <double> res;
      cin >> n >> q;
      for(int i=1;i<=n;i++)
         cin >> e[i] >> s[i];
      for(int i=1;i<=n;i++){
         for(int j=1;j<=n;j++){
            cin >> d[i][j];
            if (d[i][j] == -1) d[i][j] = 1e18;
         }
      }
      for(int k=1;k<=n;k++)
         for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
               d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      while(q--){
         int u,v;
         cin >> u >> v;
         fill(dis,dis+n+3,1e18);
         dis[u] = 0;
         pq.push(di(0,u));
         while(pq.size()){
            int u = pq.top().se;
            double du = pq.top().fi;
            pq.pop();
            if (du > dis[u]) continue;
            for(int v=1;v<=n;v++){
               if (d[u][v] > 1.0 * e[u]) continue;

               if (dis[v] > du + 1.0 * d[u][v] / s[u])
                  dis[v] = du + 1.0 * d[u][v] / s[u],
                  pq.push(di(dis[v], v));
            }
         }
         res.push_back(dis[v]);
      }
      cout << "Case #" << t << ": ";
      for(int i=0;i<res.size();i++) cout << fixed << setprecision(6) << res[i] << ' '; cout << endl;
   }
}
