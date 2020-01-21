/*
https://www.hackerrank.com/contests/moodysuniversityhackathon/challenges/presidential-gala
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct edge{
    int u,v;
    edge(int u=0,int v=0): u(u), v(v) {}
    bool operator == (edge x){
        return u == x.u && v == x.v;
    }
};
int n,m;
ll ans,val[100005], pow3[10];
vector <int> G[100005];
vector <edge> backtrack;
bool visited[100005];
bool donot(edge x){
    for(int i=0;i<backtrack.size();i++)
        if (backtrack[i] == x) return 0;
    return 1;
}
void dfs(int u,int p){
    visited[u] = 1;
    sort(G[u].begin(),G[u].end());
    G[u].resize(distance(G[u].begin(),unique(G[u].begin(),G[u].end())));
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i];
        if (v == p) continue;
        else if (visited[v]){
            if (donot(edge(min(u,v),max(u,v))))
                backtrack.push_back(edge(min(u,v),max(u,v)));
        }
        else
            dfs(v,u);
    }
}
bool in_back[100005], mask_back[100005];
ll dp[100005][5]; // 0 = !visit 1 = visit
void dfs2(int u,int p){
    if (!in_back[u]){
        dp[u][1] += val[u];
        for(int i=0;i<G[u].size();i++){
            int v = G[u][i];
            if (v == p || !donot(edge(min(u,v),max(u,v)))) continue;
            dfs2(v,u);
            dp[u][0] += max(0ll,max(dp[v][0],dp[v][1]));
            dp[u][1] += max(0ll,dp[v][0]);
        }
    }
    else{
        if (!mask_back[u]){
            dp[u][1] = -(1<<30);
            for(int i=0;i<G[u].size();i++){
                int v = G[u][i];
                if (v == p || !donot(edge(min(u,v),max(u,v)))) continue;
                dfs2(v,u);
                dp[u][0] += max(0ll,max(dp[v][0],dp[v][1]));
                //dp[u][1] += max(0,dp[v][0]);
            }
        }
        else{
            dp[u][0] = -(1<<30);
            dp[u][1] += val[u];
            for(int i=0;i<G[u].size();i++){
                int v = G[u][i];
                if (v == p || !donot(edge(min(u,v),max(u,v)))) continue;
                dfs2(v,u);
                //dp[u][0] += max(0,max(dp[v][0],dp[v][1]));
                dp[u][1] += max(0ll,dp[v][0]);
            }
        }
    }
}
bool check_mask(int mask){
    for(int i=0;i<backtrack.size();i++)
        in_back[backtrack[i].u] = in_back[backtrack[i].v] = mask_back[backtrack[i].u] = mask_back[backtrack[i].v] = 0;
    for(int i=backtrack.size()-1;i>=0;i--){
        int cnt = 0;
        while(mask > pow3[i]) cnt++, mask -= pow3[i];
        int u = backtrack[i].u, v = backtrack[i].v;
        if (!cnt){
            if (in_back[u] && mask_back[u]) return 0;
            in_back[u] = 1, mask_back[u] = 0;
            if (in_back[v] && mask_back[v]) return 0;
            in_back[v] = 1, mask_back[v] = 0;
        }
        if (cnt == 1){
            if (in_back[u] && !mask_back[u]) return 0;
            in_back[u] = 1, mask_back[u] = 1;
            if (in_back[v] && mask_back[v]) return 0;
            in_back[v] = 1, mask_back[v] = 0;
        }
        else if (cnt == 2){
            if (in_back[u] && mask_back[u]) return 0;
            in_back[u] = 1, mask_back[u] = 0;
            if (in_back[v] && !mask_back[v]) return 0;
            in_back[v] = 1, mask_back[v] = 1;
        }
    }
    return 1;
}
int main(){
    //freopen("desktoptest.inp","r",stdin);
    pow3[0] = 1;
    for(int i=1;i<=7;i++)
        pow3[i] = pow3[i-1] * 3;
    scanf("%d %d",&n,&m);
    for(ll i=1;i<=n;i++)
        scanf("%lld",&val[i]);
    for(ll i=1;i<=m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(1,1);
    for(ll i=0;i<pow3[backtrack.size()];i++){
        if (check_mask(i)){
            for(int i=0;i<=n;i++) dp[i][0] = dp[i][1] = 0;
            dfs2(1,1);
            ans = max(ans,max(dp[1][0],dp[1][1]));
        }
    }
    printf("%lld",ans);
}
