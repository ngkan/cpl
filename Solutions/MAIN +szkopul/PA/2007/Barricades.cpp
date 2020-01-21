#include <bits/stdc++.h>
using namespace std;
int n,m,num[3005],temp[3005],ans[3005];
vector <int> G[3005];
vector <int> dp[3005];
void dfs(int u,int p){
    dp[u].push_back(0);
    dp[u].push_back(0);
    num[u]++;
    if (G[u].size() == 1)   return;
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i];
        if (v == p) continue;
        dfs(v,u);

        for(int j=0;j<=num[u] + num[v];j++)
            temp[j] = (1<<30);

        for(int j=1;j<=num[u];j++)
            for(int k=1;k<=num[v];k++)
                temp[j+k] = min(temp[j+k], dp[u][j] + dp[v][k]);

        num[u] += num[v];

        for(int j=1;j<=num[u];j++)
            if (j == dp[u].size())
                dp[u].push_back(temp[j]);
            else
                dp[u][j] = min(dp[u][j] + 1, temp[j]);
    }

    for(int i=1;i<=num[u];i++)
        ans[i] = min(ans[i], dp[u][i] + 1);
}
int main(){
    for(int i=0;i<=3000;i++) ans[i] = (1<<30);
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(1,1);
    ans[1] = min(ans[1],1);
    scanf("%d",&m);
    while(m--){
        int x;
        scanf("%d",&x);
        printf("%d\n",min(dp[1][x], ans[x]));
    }
}
