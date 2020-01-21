#include <bits/stdc++.h>
#define ff(i,a,b) for(int i=(a);i<=(b);i++)
#define fb(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
long long ans;
int n,k,cnt[200005],X;
bool max_hay[200005];
int root_max_hay,do_cao_max_hay[200005];
vector <int> G[200005];
void dfs(int u,int p){
    cnt[u] = max_hay[u];
    ff(i,0,G[u].size()-1){
        int v = G[u][i];
        if (v == p) continue;
        dfs(v,u);
        cnt[u] += cnt[v];
    }
}
int dfs_max_hay(int u,int p){
    ff(i,0,G[u].size()-1){
        int v = G[u][i];
        if (v == p) continue;
        if (cnt[v] >= k) return dfs_max_hay(v,u);
    }
    return u;
}
void dfs_deo_hay(int u,int p){
    ff(i,0,G[u].size()-1){
        if (G[u][i] == p) continue;
        cnt[G[u][i]] = cnt[u] + 1;
        dfs_deo_hay(G[u][i],u);
    }
}
int main(){
    scanf("%d %d",&n,&k);
    ff(i,1,2*k) scanf("%d",&X),max_hay[X]=1;
    ff(i,1,n-1){
        int x,y;
        scanf("%d %d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(1,1);
    root_max_hay = dfs_max_hay(1,1);
    cnt[root_max_hay] = 0;
    dfs_deo_hay(root_max_hay,0);
    ff(i,1,n)
        if (max_hay[i]) ans += 1ll * cnt[i];
    cout << ans;
}
