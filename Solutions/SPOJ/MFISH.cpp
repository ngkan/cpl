#include <bits/stdc++.h>
using namespace std;
int n,m,last=-1,dp[100005];
int b[100005],d[100005],mark[100005],a[100005],sum[100005];
int sUm,lsUm;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),
        sum[i] = sum[i-1] + a[i];
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
        scanf("%d %d",&b[i],&d[i]),
        mark[b[i]] = i;
    for(int i=1;i<=n;i++){
        dp[i] = dp[i-1];
        if (mark[i]) lsUm = sUm,last = mark[i];
        if (last == -1) continue;
        if (i - d[last] >= b[last]) last = -1;
        if (last == -1) continue;
        sUm = max(b[last],lsUm + d[last]);
        if (i >= sUm)
            dp[i] = max(dp[i], dp[i - d[last]] + sum[i] - sum[i - d[last]]);
        //dp[i] = dp[i - d[last]] + sum[i] - sum[i - d[last]];

    }
    printf("%d",dp[n]);
}
