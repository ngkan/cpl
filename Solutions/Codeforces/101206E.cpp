#include <bits/stdc++.h>
using namespace std;
int rig[100005];
struct point{
   int x, type, id;
   point(int x=0,int type=0,int id=0): x(x), type(type), id(id) {}
};
bool cmp(point a,point b){
   if (a.x != b.x) return a.x < b.x;
   return a.type < b.type;
}
vector <point> a;
int test, n, m;
multiset <int> tiemnang;
int main(){
   scanf("%d",&test);
   for(int t=1;t<=test;t++){
      a.clear();
      tiemnang.clear();
      scanf("%d %d",&n,&m);
      for(int i=1;i<=n;i++){
         int x,y;
         scanf("%d %d",&x,&y);
         a.push_back(point(x,0,i));
         rig[i] = y;
      }
      for(int i=1;i<=m;i++){
         int x;
         scanf("%d",&x);
         a.push_back(point(x,1,-1));
      }
      sort(a.begin(),a.end(),cmp);
      int ans = 0;
      bool dell = 0;
      for(int i=0;i<a.size();i++){
         while(tiemnang.size() && *tiemnang.begin() < a[i].x) tiemnang.erase(tiemnang.begin());
         if (a[i].type == 0)  tiemnang.insert(rig[a[i].id]);
         else if (a[i].type == 1){
            multiset<int>::iterator it = tiemnang.lower_bound(a[i].x);
            if (it == tiemnang.end()) {dell=1;break;}
            ans = max(ans, n - (int)tiemnang.size());
            tiemnang.erase(it);
         }
      }
      if (dell){
         printf("Case #%d: IMPOSSIBLE!\n", t);
         continue;
      }
      printf("Case #%d: %d\n", t, ans+1);
   }
}
/*
1
3 2
1 10
3 4
7 9
4 8
*/
