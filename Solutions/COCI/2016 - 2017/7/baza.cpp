#include <bits/stdc++.h>
using namespace std;
int n,m,a[1005][1005],q,x[1005];
int main(){
   scanf("%d %d",&n,&m);
   for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
         scanf("%d",&a[i][j]);
   scanf("%d",&q);
   while(q--){
      int cnt = 0;
      for(int i=1;i<=m;i++)
         scanf("%d",&x[i]);
      for(int i=1;i<=n;i++){
         bool ok = 1;
         for(int j=1;j<=m;j++)
            if (x[j] != -1 && a[i][j] != x[j]) ok = 0;
         cnt += ok;
      }
      printf("%d\n",cnt);
   }
}
