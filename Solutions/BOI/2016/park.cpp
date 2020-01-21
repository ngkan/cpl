#include <bits/stdc++.h>
#define int long long
using namespace std;
const double eps = 1e-5;
struct event{
   int x,y,id; double w;
   event(int x=0,int y=0,int id=0,double w = 0.0): x(x), y(y), id(id), w(w) {}
};
bool cmp(event a,event b){
   return a.w < b.w;
}
int dsup[2005];
int dsu_p(int x){
   return x == dsup[x] ? x : dsup[x] = dsu_p(dsup[x]);
}
void dsu_union(int x,int y){
   dsup[dsu_p(y)] = dsu_p(x);
}
bool dsu_same(int x,int y){
   return dsu_p(x) == dsu_p(y);
}
int n,m;
int w,h;
int treex[2005], treey[2005], treer[2005];
int radi[100005], type[100005];
int res[100005][5];
double dis(int x,int y){
   return sqrt((treex[x] - treex[y]) * (treex[x] - treex[y])
               + (treey[x] - treey[y]) * (treey[x] - treey[y]));
}
int mov(int gate, int mov){
   int res = gate + mov + 8;
   while(res > 4) res -= 4;
   return res;
}
vector <event> lst;
signed main(){
   for(int i=1;i<2005;i++) dsup[i] = i;

   scanf("%lld %lld",&n,&m);
   scanf("%lld %lld",&w,&h);
   for(int i=1;i<=n;i++)
      scanf("%lld %lld %lld",&treex[i],&treey[i],&treer[i]),
      lst.push_back(event(i,n+1,0,1.0*(treey[i] - treer[i])/2 + eps)),
      lst.push_back(event(i,n+2,0,1.0*(w-treex[i]-treer[i])/2 + eps)),
      lst.push_back(event(i,n+3,0,1.0*(h-treey[i]-treer[i])/2 + eps)),
      lst.push_back(event(i,n+4,0,1.0*(treex[i] - treer[i])/2 + eps));
   for(int i=1;i<=m;i++)
      scanf("%lld %lld",&radi[i], &type[i]),
      lst.push_back(event(type[i],0,i,radi[i]));
   for(int i=1;i<=n;i++)
      for(int j=i+1;j<=n;j++)
         lst.push_back(event(i,j,0,(dis(i,j) - 1.0*treer[i] - 1.0*treer[j])/2+eps));
   sort(lst.begin(),lst.end(),cmp);
   for(int i=0;i<lst.size();i++){
      if (lst[i].id == 0)
         dsu_union(lst[i].x, lst[i].y);
      else{
         int id = lst[i].id;
         int gate = lst[i].x;
         res[id][gate] = 1;
         //if (dsu_same(n + gate,n + mov(gate,3))) continue;
         if (!dsu_same(n + gate,n + mov(gate,1)) && !dsu_same(n + gate,n + mov(gate,2)) && !dsu_same(n + gate, n + mov(gate,3)))
            res[id][mov(gate,1)] = 1;
         if (!dsu_same(n + gate,n + mov(gate,2)) && !dsu_same(n + mov(gate,1), n + mov(gate,3)) && !dsu_same(n + mov(gate,1), n + mov(gate,2)) && !dsu_same(n + gate, n + mov(gate,3)))
            res[id][mov(gate,2)] = 1;
         if (!dsu_same(n + mov(gate,3), n + gate) && !dsu_same(n + mov(gate,3), n + mov(gate,1)) && !dsu_same(n + mov(gate,3), n + mov(gate,2)))
            res[id][mov(gate,3)] = 1;
      }
   }
   for(int i=1;i<=m;i++){
      for(int j=1;j<=4;j++)
         if(res[i][j]) printf("%lld",j); printf("\n");
   }
}
