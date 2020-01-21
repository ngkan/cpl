#include <bits/stdc++.h>
using namespace std;
int n,c,k,a[100005];
int main(){
   scanf("%d %d %d",&n,&c,&k);
   for(int i=1;i<=n;i++)
      scanf("%d",&a[i]);
   sort(a+1,a+n+1);
   int last = 1;
   int ans = 1;
   for(int i=1;i<=n;i++){
      if (a[last] + k < a[i]){
         last = i;
         ans++;
         continue;
      }
      if (i - last >= c){
         last = i;
         ans++;
      }
   }
   printf("%d",ans);
}
