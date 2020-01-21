#include <bits/stdc++.h>
using namespace std;
int n,m,k,ans;
vector <int> G[2005];
bool disliek[2005][2005], visited[2005];
vector <int> liek;
void dfs(int u,int p){
    visited[u] = 1;
    liek.push_back(u);
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i];
        if (visited[v]) continue;
        dfs(v,u);
    }
}
int solve(int s){
    liek.clear();
    dfs(s,s);
    for(int i=0;i<liek.size();i++)
        for(int j=i+1;j<liek.size();j++)
            if (disliek[liek[i]][liek[j]]) return 0;
    return liek.size();
}
int main(){
    scanf("%d",&n);
    scanf("%d",&k);
    for(int i=1;i<=k;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        disliek[x][y] = 1;
        disliek[y][x] = 1;
    }
    for(int i=1;i<=n;i++)
        if (!visited[i])
            ans = max(ans, solve(i));
    printf("%d",ans);
}
