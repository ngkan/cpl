#include <bits/stdc++.h>
using namespace std;
int n,a[200005],b[200005],ok;
int main(){
   scanf("%d",&n);
   for(int i=1;i<=n;i++)
      scanf("%d",&a[i]), a[i+n] = a[i];
   n *= 2;
   for(int i=1;i<=n;i++)
      b[i] = a[i-1] >= a[i] ? b[i-1] + 1 : 1,
      ok = b[i] >= n/2 ? 1 : ok;
   reverse(a+1,a+n+1);
   for(int i=1;i<=n;i++)
      b[i] = a[i-1] >= a[i] ? b[i-1] + 1 : 1,
      ok = b[i] >= n/2 ? 1 : ok;
   if (ok) printf("TAK");
   else printf("NIE");
}
