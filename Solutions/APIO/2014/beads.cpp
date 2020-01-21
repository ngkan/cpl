#include <bits/stdc++.h>
using namespace std;
struct edge{
    int v,w;
    edge(int v=0,int w=0): v(v), w(w) {}
};
int n;
vector <edge> G[200005];
int dp[200005][5];
inline int val1(int pos,int w){
    return dp[pos][0] + w;
}
inline int val02(int pos,int w){
    return max(dp[pos][0], dp[pos][2] + w);
}
void dfs(int u,int p){
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i].v;
        if (v == p) continue;
        dfs(v,u);
    }

    // dp[i][0]

    dp[u][0] = 0;
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i].v;
        if (v == p) continue;
        dp[u][0] += val02(v,G[u][i].w);
    }

    // dp[i][1]

    int fi02=0,se02=0,fiva02=-(int)1e9, seva02=-(int)1e9;
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i].v;
        int w = G[u][i].w;
        if (v == p) continue;
        if (val1(v,w) - val02(v,w) >= val1(fi02,fiva02) - val02(fi02,fiva02))
            se02 = fi02,
            seva02 = fiva02,
            fi02 = v,
            fiva02 = w;
        else if (val1(v,w) - val02(v,w) >= val1(se02,seva02) - val02(se02,seva02))
            se02 = v,
            seva02 = w;
    }
    dp[u][1] = - (int) 1e9;
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i].v;
        int w = G[u][i].w;
        if (v == p) continue;
        dp[u][1] = max(dp[u][1], dp[u][0] - val02(v,w) + dp[v][1]);
        dp[u][1] = max(dp[u][1], dp[u][0] - val02(v,w) + dp[v][3] + w);
        if (v != fi02)
            dp[u][1] = max(dp[u][1], dp[u][0] - val02(v,w) + dp[v][1] + w - val02(fi02,fiva02) + dp[fi02][0] + fiva02);
        else if (se02)
            dp[u][1] = max(dp[u][1], dp[u][0] - val02(v,w) + dp[v][1] + w - val02(se02,seva02) + dp[se02][0] + seva02);
    }
    if (se02)
        dp[u][1] = max(dp[u][1], dp[u][0] - val02(fi02,fiva02) - val02(se02,seva02) + val1(fi02,fiva02) + val1(se02,seva02));

    // dp[i][2]

    dp[u][2] = -(int)1e9;
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i].v;
        int w = G[u][i].w;
        if (v == p) continue;
        dp[u][2] = max(dp[u][2], dp[u][0] - val02(v,w) + dp[v][0] + G[u][i].w);
    }

    // dp[i][3]

    dp[u][3] = -(int)1e9;
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i].v;
        int w = G[u][i].w;
        if (v == p) continue;
        dp[u][3] = max(dp[u][3], dp[u][0] - val02(v,w) + dp[v][1] + G[u][i].w);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int x,y,w;
        scanf("%d %d %d",&x,&y,&w);
        G[x].push_back(edge(y,w));
        G[y].push_back(edge(x,w));
    }
    dfs(1,1);
    cout << max(dp[1][0], dp[1][1]);
}

