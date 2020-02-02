#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int,int> ii;
bool cmp(ii x,ii y){
   if (x.se != y.se) return x.se > y.se;
   return x.fi < y.fi;
}
int ans;
ii solve(){
   int n0;
   scanf("%d",&n0);
   if (n0 == 0){
      int x,y;
      scanf("%d %d",&x,&y);
      return ii(x,y);
   }
   vector<ii> a;
   for(int i=0;i<n0;++i){
      a.push_back(solve());
   }
   sort(a.begin(),a.end(),cmp);
   ii res = ii(0,(int)1e9);
   for(int i=0;i<a.size();i++){
      if (max(res.fi, a[i].fi) > min(res.se, a[i].se)){
         ans += (a.size() - i);
         break;
      }
      res = ii (max(res.fi, a[i].fi), min(res.se, a[i].se));
   }
   return res;
}
int main(){
   printf("%d",ans + (solve().fi != 0));
}
