#include <bits/stdc++.h>
using namespace std;
int n, dsup[200005], a[200005], sum,mark[200005];
int dsu_p(int x){
   return x == dsup[x] ? x : dsup[x] = dsu_p(dsup[x]);
}
void dsu_union(int x,int y){
   x = dsu_p(x);
   y = dsu_p(y);
   dsup[y] = x;
}
int main(){
   scanf("%d",&n);
   for(int i=1;i<=n;i++){
      dsup[i] = i;
      scanf("%d",&a[i]);
      mark[a[i]] = 1;
   }
   sum = 1;
   for(int i=1;i<=n;i++){
      dsu_union(i,a[i]);
      scanf("%d",&a[0]);
      sum ^= a[0];
   }
   int tplt = 0;
   for(int i=1;i<=n;i++)
      tplt += (i == dsu_p(i));
   if (tplt == 1) tplt = 0;
   for(int i=1;i<=n;i++) tplt += (!mark[i]);
   printf("%d",tplt + sum);
}
