#include <bits/stdc++.h>
using namespace std;
long long ans;
long long n,cnt[100005];
bool have[100005];
int main(){
   freopen("guma.in.10","r",stdin);
   freopen("out.txt","w",stdout);
   scanf("%lld",&n);
   for(int i=1;i<=n+1;i++){
      int x;
      scanf("%lld",&x);
      have[x] = 1;
   }
   for(int i=1;i<=100000;i++){
      for(int j=i;j<=100000;j+=i)
         if (have[j]) have[i] = 1;
   }
   for(int i=2;i<=100000;i++){
      if (!have[i]) continue;
      cnt[i] += i-1;
      ans += cnt[i];
      for(int j=2*i;j<=100000;j+=i)
         cnt[j] -= cnt[i];
   }
   printf("%lld",ans);
}
