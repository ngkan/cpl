#include <bits/stdc++.h>
using namespace std;
struct edge{
   int v,id;
   edge(int v=0,int id=0): v(v), id(id) {}
};
int n,m,sum;
vector <edge> G[205];
int w[205][205];
void checkdegree(){
   for(int i=1;i<=n;i++){
      if (G[i].size()%2)
         printf("-1"),
         exit(0);
   }
}
bool ahi[205];
void checkconnectandsum(){
   queue <int> q;
   q.push(1);
   ahi[1] = 1;
   while(q.size()){
      int u = q.front();
      q.pop();
      for(int i=0;i<G[u].size();i++)
         if (!ahi[G[u][i].v])
            ahi[G[u][i].v] = 1,
            q.push(G[u][i].v);
   }
   for(int i=1;i<=n;i++)
      if (!ahi[i])
         printf("-1"),
         exit(0);
   if (sum < 0)
      printf("-1"),
      exit(0);
}
int ctrl[205];
vector <int> mjk;
stack <int> st;
bool marked[40005];
void make_path(int u){
   st.push(u);
   for(;ctrl[u]<G[u].size();ctrl[u]++){
      if (marked[G[u][ctrl[u]].id]) continue;
      marked[G[u][ctrl[u]].id] = 1;
      make_path(G[u][ctrl[u]].v);
   }
   mjk.push_back(st.top());
   st.pop();
}
int val[40005];
int main(){
   scanf("%d %d",&n,&m);
   for(int i=1;i<=m;i++){
      int x,y,ww;
      scanf("%d %d %d",&x,&y,&ww);
      G[x].push_back(edge(y,i));
      G[y].push_back(edge(x,i));
      sum+=ww;
      w[x][y] = w[y][x] = ww;
   }
   checkdegree();
   checkconnectandsum();
   make_path(1);
   int dis = 0;
   for(int i=1;i<mjk.size()-1;i++){
      val[i] = val[i-1] + w[mjk[i-1]][mjk[i]];
      if (val[dis] > val[i]) dis = i;
   }
   for(int i=0;i<mjk.size();i++)
      cout << mjk[(dis+i)%(mjk.size()-1)] << ' ';
}
