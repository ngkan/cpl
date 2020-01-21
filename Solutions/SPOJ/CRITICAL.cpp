#include <bits/stdc++.h>
using namespace std;
int n,m;
long long ans;
int num[20005], low[20005], num_des[20005], root_dfs[20005], _time;
bool khop[20005];
vector <int> G[20005];
vector <int> G_dfs[20005];
int dfs(int u,int p,int root){
    num[u] = low[u] = ++_time;
    num_des[u] = 1;     root_dfs[u] = root;
    int cnt_real_des = 0;
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i];
        if (v == p) continue;
        if (num[v]) low[u] = min(low[u], num[v]);
        else{
            cnt_real_des ++;
            dfs(v,u,root);
            G_dfs[u].push_back(v);
            low[u] = min(low[u], low[v]);
            num_des[u] += num_des[v];
            if (u != root && low[v] >= num[u]) khop[u] = 1;
        }
    }
    return cnt_real_des;
}
void dfs2(int u){
    long long res = 0, total = 0;
    for(int i=0;i<G_dfs[u].size();i++){
        int v = G_dfs[u][i];    dfs2(v);
        if (low[v] < num[u]) continue;
        res += 1ll * total * (num_des[v]);
        total += 1ll * num_des[v];
    }
    res += 1ll * total * (num_des[root_dfs[u]] - total - 1);
    if (khop[u]) ans += res;
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        if (num[i]) continue;
        if (dfs(i,i,i) >= 2) khop[i] = 1;
        dfs2(i);
    }
    cout << fixed << setprecision(2) << (double)ans/n;
}
