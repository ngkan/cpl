#include <bits/stdc++.h>
using namespace std;
int n,m;
vector <int> G[10005];
int num[10005], low[10005], _time;
int khop[10005], ans1, ans2;
void dfs(int u,int p, int root){
    num[u] = low[u] = ++_time;
    int num_child = 0;
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i];
        if (v == p) continue;
        if (num[v]) low[u] = min(low[u], num[v]);
        else{
            num_child ++;
            dfs(v,u,root);
            low[u] = min(low[u], low[v]);
            if (num[u] < low[v]) ans2++;
            if (u != root && num[u] <= low[v]) khop[u] = 1;
        }
    }
    if (u == root && num_child >= 2) khop[u] = 1;
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
        if (!num[i])
            dfs(i,i,i);
    for(int i=1;i<=n;i++) ans1 += khop[i];
    printf("%d %d",ans1,ans2);
}
