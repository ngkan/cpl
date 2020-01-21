#include <bits/stdc++.h>
using namespace std;
int n,m,color[205];
vector <int> G[205];
bool dfs(int u,int p){
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i];
        if (v == p) continue;
        if (!color[v]){
            color[v] = 3 - color[u];
            dfs(v,u);
        }
        else if (color[v] == color[u]) return 0;
    }
    return 1;
}
int main(){
    while(scanf("%d",&n) == 1){
        if (!n) break;
        scanf("%d",&m);
        for(int i=0;i<n;i++)
            color[i] = 0,
            G[i].clear();
        for(int i=1;i<=m;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            G[x].push_back(y);
            G[y].push_back(x);
        }
        color[0] = 1;
        if (dfs(0,0)) printf("BICOLORABLE.\n");
        else printf("NOT BICOLORABLE.\n");
    }
}
