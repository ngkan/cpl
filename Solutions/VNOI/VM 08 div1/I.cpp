#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int,int> ii;
int n,k;
int a[105][105], x[105], y[105], c[105], p[505];
void init(){
   scanf("%d %d",&n,&k);
   for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
         scanf("%d",&a[i][j]);
      }
   }
   for(int i=1;i<=k;i++)
      scanf("%d %d %d",&x[i],&y[i],&c[i]),
      x[i]--,
      y[i]--;
   for(int i=0;i<4*n;i++)
      scanf("%d",&p[i]);
}
int d[105][105];
bool inqq[105][105];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
const int source = 250;
const int sink = 251;
vector <int> G[300];
int cap[300][300], wei[300][300], f[300][300];
vector <ii> dismjk[10005];
void prep(){
   for(int id=1;id<=k;id++){
      for(int i=0;i<n;i++) for(int j=0;j<n;j++) d[i][j] = (int) 1e9;
      for(int i=0;i<=10000;i++) dismjk[i].clear();
      d[x[id]][y[id]] = a[x[id]][y[id]];
      dismjk[a[x[id]][y[id]]].push_back(ii(x[id], y[id]));
      for(int mjk=0;mjk<=10000;mjk++){
         for(int i2=0;i2<dismjk[mjk].size();i2++){
            int X = dismjk[mjk][i2].fi;
            int Y = dismjk[mjk][i2].se;
            if (d[X][Y] != mjk) continue;

            for(int i=0;i<4;i++){
               int XX = X + dx[i];
               int YY = Y + dy[i];
               if (XX < 0 || XX >= n || YY < 0 || YY >= n) continue;
               if (d[XX][YY] > d[X][Y] + a[XX][YY]){
                  d[XX][YY] = d[X][Y] + a[XX][YY];
                  dismjk[d[XX][YY]].push_back(ii(XX,YY));
               }
            }
         }
      }

      for(int t=0;t<k;t++){
         wei[id][t+1+k] = (int) 1e9;
         for(int i=0;i<4*n;i++){
            if (p[(i-t+4*n)%(4*n)] == c[id]){
               if (i < n)
                  wei[id][t+1+k] = min(wei[id][t+1+k], d[0][i]);
               else if (i < 2*n)
                  wei[id][t+1+k] = min(wei[id][t+1+k], d[i-n][n-1]);
               else if (i < 3*n)
                  wei[id][t+1+k] = min(wei[id][t+1+k], d[n-1][3*n-1-i]);
               else
                  wei[id][t+1+k] = min(wei[id][t+1+k], d[4*n-1-i][0]);
            }
         }
      }
   }
}
void build_flow(){
   for(int i=1;i<=k;i++)
      G[source].push_back(i),
      G[i].push_back(source),
      cap[source][i] = 1;
   for(int i=1;i<=k;i++)
      for(int j=k+1;j<=2*k;j++)
         G[i].push_back(j),
         G[j].push_back(i),
         cap[i][j] = 1,
         wei[j][i] = -wei[i][j];
   for(int i=k+1;i<=2*k;i++)
      G[i].push_back(sink),
      G[sink].push_back(i),
      cap[i][sink] = 1;
}
int inq[300], dd[300], pp[300];
int ans;
bool find_edmond(){
   fill(pp,pp+300,-1);
   fill(dd,dd+300,(int) 1e9);
   queue <int> q;
   q.push(source);
   inq[source] = 1;
   dd[source] = 0;
   while(q.size()){
      int u = q.front();
      q.pop();
      inq[u] = 0;
      for(int i=0;i<G[u].size();i++){
         int v = G[u][i];
         if (f[u][v] == cap[u][v]) continue;
         if (dd[v] > dd[u] + wei[u][v]){
             dd[v] = dd[u] + wei[u][v];
             pp[v] = u;
             if (!inq[v])
                 inq[v] = 1,
                 q.push(v);
         }
      }
   }
   return dd[sink] != (int) 1e9;
}
void inc(){
    int ff = (int) 1e9;
    for(int x=sink;x!=source;x=pp[x])
        ff = min(ff, cap[pp[x]][x] - f[pp[x]][x]);
    for(int x=sink;x!=source;x=pp[x])
        f[pp[x]][x] += ff,
        f[x][pp[x]] -= ff;
    ans += dd[sink] * ff;
}
int main(){
   init();
   prep();
   build_flow();
   while(find_edmond())
      inc();
   cout << ans;
}
