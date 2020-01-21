#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, a[100005];
int main(){
   scanf("%lld",&n);
   for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
   int index = 1;
   for(int bit=60;bit>=0;bit--){
      for(int i=index;i<=n;i++)
         if ((a[i]>>bit)&1) swap(a[i], a[index]);
      if (!((a[index]>>bit)&1)) continue;
      for(int i=index+1;i<=n;i++)
         if ((a[i]>>bit)&1) a[i] ^= a[index];
      index++;
   }
   ll ans = 0;
   for(int i=1;i<=n;i++)
      if ((ans ^ a[i]) > ans) ans ^= a[i];
   printf("%lld",ans);
}
