#include <bits/stdc++.h>
#define ll long long
using namespace std;
int test;
ll n,m,x,a[100005],b[100005];
int main(){
    scanf("%d",&test);
    while(test--){
        scanf("%lld %lld %lld",&n,&m,&x);
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]),
            a[i] += a[i-1];
        for(int i=1;i<=m;i++)
            scanf("%lld",&b[i]),
            b[i] += b[i-1];
        int ans = 0;
        for(int i=0;i<=n;i++){
            if (a[i] > x) break;
            int pos = upper_bound(b+1,b+m+1,x-a[i]) - b - 1;
            ans = max(ans,i + pos);
        }
        printf("%d\n",ans);
    }
}
