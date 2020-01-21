#include <bits/stdc++.h>
using namespace std;
long long n,k,x,ans,a[200005],l[200005],r[200005],b[200005];
int main(){
    scanf("%lld %lld %lld",&n,&k,&x);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]),
        b[i] = a[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=k;j++)
            b[i] *= x;
    for(int i=1;i<=n;i++)
        l[i] = (l[i-1] | a[i]);
    for(int i=n;i>=1;i--)
        r[i] = (r[i+1] | a[i]);
    for(int i=1;i<=n;i++)
        ans = max(ans,(b[i] | l[i-1] | r[i+1]));
    printf("%lld",ans);
}
