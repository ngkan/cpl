#include <bits/stdc++.h>
using namespace std;
vector <int> G[101];
int num[101],low[101],num_des[101],num_bridge[101], _time;
int n,m,ans;
int dfs(int u,int p){
    num[u] = low[u] = ++_time;
    num_des[u] = 1;
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i];
        if (v == p) continue;
        if (num[v]) low[u] = min(low[u], num[v]);
        else{
            dfs(v,u);
            num_des[u] += num_des[v];
            low[u] = min(low[u], low[v]);
            if (low[v] == num[v])
                ans += num_des[v] * (n - num_des[v]);
        }
    }
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(1,1);
    printf("%d",ans);
}
