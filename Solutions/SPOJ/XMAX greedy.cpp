#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, a[100005];
int main(){
   scanf("%lld",&n);
   for(int i=1;i<=n;i++)
      scanf("%lld",&a[i]);
   int index = 1;
   for(int bit=60;bit>=0;bit--){
      for(int i=index;i<=n;i++){
         if ((a[i]>>bit)&1) swap(a[index], a[i]);
      }
      if (!((a[index]>>bit)&1)) continue;
      for(int i=1;i<=n;i++)
         if (i!=index && (a[i]>>bit)&1) a[i] ^= a[index];
      index++;
   }
   ll ans = 0;
   for(int i=1;i<=n;i++) ans ^= a[i];
   cout << ans;
}
