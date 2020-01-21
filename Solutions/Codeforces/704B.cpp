#include <bits/stdc++.h>
using namespace std;
long long n,s,e,x[5001],a[5001],b[5001],c[5001],d[5001];
long long dp[5001][5001];
int main(){
    for(int i=0;i<=5000;i++) for(int j=0;j<=5000;j++) dp[i][j] = (1ll << 50);
    dp[0][0] = 0;
    scanf("%lld %lld %lld",&n,&s,&e);
    for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++) scanf("%lld",&b[i]);
    for(int i=1;i<=n;i++) scanf("%lld",&c[i]);
    for(int i=1;i<=n;i++) scanf("%lld",&d[i]);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if (i == s){
                if (i > 1) dp[i][j] = min(dp[i][j], dp[i-1][j] + c[i] + x[i]);
                if (j < n) dp[i][j] = min(dp[i][j], dp[i-1][j-1] + d[i] - x[i]);
            }
            else if (i == e){
                if (i < n) dp[i][j] = min(dp[i][j], dp[i-1][j-1] + b[i] - x[i]);
                if (j < n) dp[i][j] = min(dp[i][j], dp[i-1][j] + a[i] + x[i]);
            }
            else{
                if (j > 1 || i < e)                 dp[i][j] = min(dp[i][j], dp[i-1][j] + a[i] + d[i]);
                if (j > 1 || i < s)                 dp[i][j] = min(dp[i][j], dp[i-1][j] + b[i] + c[i]);
                if (j < n)                          dp[i][j] = min(dp[i][j], dp[i-1][j+1] + a[i] + c[i] + 2 * x[i]);
                if (!(i > s && i > e && j == 2))    dp[i][j] = min(dp[i][j], dp[i-1][j-1] + b[i] + d[i] - 2 * x[i]);
            }
        }
    }
    printf("%lld",dp[n][1]);
}
