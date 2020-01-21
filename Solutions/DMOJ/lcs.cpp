#include <bits/stdc++.h>
using namespace std;
int n,m,a[1005],b[1005],dp[1005][1005];
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
        scanf("%d",&b[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            if (a[i] == b[j]) dp[i][j] = max(dp[i][j],dp[i-1][j-1] + 1);
        }
    printf("%d",dp[n][m]);
}
