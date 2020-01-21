#include <stdio.h>
#include <algorithm>
using namespace std;
int dp[505][200005];
int n,sum,c[505];
int main(){
    for(int i=0;i<=500;i++) for(int j=0;j<=200000;j++) dp[i][j] = -(1<<30);
    dp[0][100000] = 0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&c[i]);
        sum += c[i];
        for(int j=0;j<=200000;j++)  dp[i][j] = dp[i-1][j];
        for(int val=0;val<=200000-c[i];val++)
            dp[i][val+c[i]] = max(dp[i][val+c[i]], dp[i-1][val] + c[i]);
        for(int val=c[i];val<=200000;val++)
            dp[i][val-c[i]] = max(dp[i][val-c[i]], dp[i-1][val] + c[i]);
    }
    printf("%d",sum - dp[n][100000] + dp[n][100000] / 2);
}
