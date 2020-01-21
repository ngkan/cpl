#include <bits/stdc++.h>
using namespace std;
int n,a[105],ans[105];
vector <int> mjk;
int main(){
   freopen("cokolade.in.3b","r",stdin);
   freopen("out.txt","w",stdout);
   scanf("%d",&n);
   for(int i=1;i<=n;i++){
      ans[i] = (int) 1e9;
      scanf("%d",&a[i]);
      for(int j=1;j<=10000;j++)
         mjk.push_back(a[i]/j + 1);
   }
   for(int i=1;i<=10000;i++) mjk.push_back(i);
   sort(a+1,a+n+1);
   sort(mjk.begin(),mjk.end());
   mjk.resize(distance(mjk.begin(),unique(mjk.begin(),mjk.end())));
   for(int i=0;i<mjk.size();i++){
      for(int j=1;j<=n;j++){
         int last;
         for(last=j;last<=n;last++)
            if (a[j]/mjk[i] != a[last]/mjk[i]) break;
         last--;
         ans[last-j+1] = min(ans[last-j+1], mjk[i]);
         j = last;
      }
   }
   for(int i=1;i<=n;i++)
      if (ans[i] == (int) 1e9) printf("-1\n");
      else printf("%d\n",ans[i]);
}
