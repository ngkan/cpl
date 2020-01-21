#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int,int> ii;
int test;
int n, a[100005];
bool mark[100005];
vector <ii> lst;
int main(){
   scanf("%d",&test);
   while(test--){
      scanf("%d",&n);
      fill(mark,mark+n+3,0);
      lst.clear();
      for(int i=1;i<=n;i++)
         scanf("%d",&a[i]), mark[a[i]] = 1;
      int ans = n;
      for(int i=1;i<=n;i++)
         if (!mark[i]){
            int beg = i, en = i;
            while(a[en]) en = a[en];
            lst.push_back(ii(beg,en));
         }
      for(int i=0;i<lst.size();i++)
         a[lst[i].se] = lst[(i+1)%lst.size()].fi;
      fill(mark,mark+n+3,0);
      for(int i=1;i<=n;i++){
         if (mark[i]) continue;
         ans--;
         int x = i;
         while(!mark[x]){
            mark[x] = 1;
            x = a[x];
         }
      }
      printf("%d\n",ans);
      for(int i=1;i<=n;i++)
         printf("%d ",a[i]); printf("\n");
   }
}
