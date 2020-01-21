#include <bits/stdc++.h>
using namespace std;
int a[100005], dp[100005];
int n;
int main(){
   scanf("%d",&n);
   for(int i=1;i<=n;i++){
      scanf("%d",&a[i]);
      dp[i] = dp[i-1] + 20;
      int pos = upper_bound(a,a+i+1,a[i]-90) - a;
      if (pos>0) pos--;
      dp[i] = min(dp[i], dp[pos] + 50);
      pos = upper_bound(a,a+i+1,a[i]-1440) - a;
      if (pos>0) pos--;
      dp[i] = min(dp[i], dp[pos] + 120);
      printf("%d\n",dp[i] - dp[i-1]);
   }
}
