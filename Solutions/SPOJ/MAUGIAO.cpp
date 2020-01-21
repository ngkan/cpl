#include <bits/stdc++.h>
using namespace std;
int n,a[21][21];
long long dp[(1<<20)],cnt[(1<<20)];
vector <int> ax[21];
int main(){
    cnt[0] = 1;
    for(int i=0;i<(1<<20);i++)  ax[__builtin_popcount(i)].push_back(i);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++){
        for(int j=0;j<ax[i].size();j++){
            int mask = ax[i][j];
            for(int pos=0;pos<20;pos++){
                if (((1<<pos) & mask)){
                    int mask2 = (mask ^ (1<<pos));
                    if (dp[mask2] + 1ll * a[i][pos+1] == dp[mask]){
                        cnt[mask] += cnt[mask2];
                    }
                    else if (dp[mask2] + 1ll * a[i][pos+1] > dp[mask]){
                        dp[mask] = dp[mask2] + 1ll * a[i][pos+1];
                        cnt[mask] = cnt[mask2];
                    }
                }
            }
        }
    }
    printf("%lld %lld",dp[(1<<n)-1],cnt[(1<<n)-1]);
}
