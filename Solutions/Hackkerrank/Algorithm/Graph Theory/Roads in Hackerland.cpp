#include <bits/stdc++.h>
using namespace std;
struct edge{
   int u,v,w;
   edge(int u=0,int v=0,int w=0) : u(u),v(v),w(w) {}
};
bool cmp(edge x,edge y){
   return x.w < y.w;
}
int dsup[100005];
int dsu_p(int x){
   return x == dsup[x] ? x : dsup[x] = dsu_p(dsup[x]);
}
void dsu_union(int x,int y){
   if (dsu_p(x) == dsu_p(y)) return;
   dsup[dsu_p(y)] = dsu_p(x);
}
int n,m;
vector <edge> lst,G[100005];
#define ll unsigned long long
ll arr[500005],child[100005];
string s;
void dfs(int u,int p){
   child[u]++;
   for(int i=0;i<G[u].size();i++){
      int v = G[u][i].v;
      int w = G[u][i].w;
      if (v == p) continue;
      dfs(v,u);
      ll tmp = child[v] * (n - child[v]);
      while(tmp){
         arr[w++] += tmp%2;
         tmp/=2;
      }
      child[u] += child[v];
   }
}
int main(){
   scanf("%d %d",&n,&m);
   for(int i=1;i<=n;i++) dsup[i] = i;
   while(m--){
      int x,y,w;
      scanf("%d %d %d",&x,&y,&w);
      lst.push_back(edge(x,y,w));
   }
   sort(lst.begin(),lst.end(),cmp);
   for(int i=0;i<lst.size();i++){
      int u = lst[i].u, v = lst[i].v, w = lst[i].w;
      if (dsu_p(u) == dsu_p(v)) continue;
      G[u].push_back(edge(0,v,w));
      G[v].push_back(edge(0,u,w));
      dsu_union(u,v);
   }
   dfs(1,1);
   for(int i=0;i<500000;i++){
      s.push_back('0' + arr[i]%2);
      arr[i+1] += arr[i]/2;
   }
   while(s.back() == '0') s.pop_back();
   reverse(s.begin(),s.end());
   cout << s;
}
