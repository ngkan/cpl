#include <bits/stdc++.h>
using namespace std;
int n,a[1005],pos[1005],dp[1005][1005];
int fw[1005];
void fw_upd(int pos,int val){
    for(;pos<=n;pos+=pos&-pos) fw[pos] += val;
}
int fw_get(int pos){
    int res = 0;
    for(;pos;pos-=pos&-pos) res += fw[pos];
    return res;
}
int main(){
    for(int i=0;i<=1000;i++) for(int j=0;j<=i;j++) dp[j][i] = (1<<30);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),
        pos[a[i]] = i;

    for(int i=1;i<=n;i++){
        memset(fw,0,sizeof(fw));
        for(int j=1;j<=n;j++)   fw_upd(j,1);
        for(int j=i;j>=1;j--){
            dp[j][i] = min(dp[j][i], dp[j+1][i] + (i-j+1) * fw_get(pos[j]));
            fw_upd(pos[j],-1);
            if (i != n)
                dp[j][i+1] = min(dp[j][i+1], dp[j][i] + (i+1-j+1) * fw_get(pos[i+1]));
        }
    }
    printf("%d",dp[1][n]);
}
