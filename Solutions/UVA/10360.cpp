#include <bits/stdc++.h>
using namespace std;
int test,n,d,a[1100][1100];
int main(){
   scanf("%d",&test);
   while(test--){
      memset(a,0,sizeof(a));
      scanf("%d",&d);
      scanf("%d",&n);
      while(n--){
         int x,y,w;
         scanf("%d %d %d",&x,&y,&w);
         a[x][y] += w;
      }
      for(int i=0;i<=1099;i++)
         for(int j=0;j<=1099;j++){
            if (i) a[i][j] += a[i-1][j];
            if (j) a[i][j] += a[i][j-1];
            if (i && j) a[i][j] -= a[i-1][j-1];
         }
      int x = 0, y = 0 , ans = 0;
      for(int ii=0;ii<=1024;ii++)
         for(int jj=0;jj<=1024;jj++){
            int i = ii+d, j = jj+d;
            int prep = a[i][j];
            if (i >= 2*d+1) prep -= a[i-2*d-1][j];
            if (j >= 2*d+1) prep -= a[i][j-2*d-1];
            if (i >= 2*d+1 && j >= 2*d+1) prep += a[i-2*d-1][j-2*d-1];
            if (prep > ans)
               x = ii, y = jj, ans = prep;
         }

      printf("%d %d %d\n",x,y,ans);
   }
}
