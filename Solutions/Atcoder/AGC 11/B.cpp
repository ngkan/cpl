#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[100005],b[100005];
int main(){
   scanf("%lld",&n);
   for(int i=1;i<=n;i++)
      scanf("%lld",&a[i]);
   sort(a+1,a+n+1);
   for(int i=1;i<=n;i++)
      b[i] = b[i-1] + a[i];
   int ans = 0;
   for(int i=n;i>=1;i--)
      if (2 * b[i] >= a[i+1]) ans++;
      else break;
   printf("%d",ans);
}
