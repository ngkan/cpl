#include <bits/stdc++.h>
using namespace std;
int n,m,s,t,flow,f[1005][1005],c[1005][1005],lv[1005],check[1005],_time=1;
vector <int> G[1005];
bool dinic_bfs(){
    queue <int> q;
    memset(lv,0,sizeof(lv));
    lv[s] = 1;
    q.push(s);
    while(q.size()){
        int u = q.front();
        q.pop();
        for(int i=0;i<G[u].size();i++){
            int v = G[u][i];
            if (!lv[v] && f[u][v] < c[u][v])
                lv[v] = lv[u] + 1,
                q.push(v);
        }
    }
    return lv[t] > 0;
}
int dinic_dfs(int u,int mi){
    if (u == t) return mi;
    if (check[u] != _time) check[u] = _time;
    else return 0;

    for(int i=0;i<G[u].size();i++){
        int v = G[u][i];
        if (c[u][v] == f[u][v]) continue;
        if (lv[v] != lv[u] + 1) continue;
        if (int val = dinic_dfs(v,min(mi,c[u][v] - f[u][v]))){
            f[u][v] += val;
            f[v][u] -= val;
            return val;
        }
    }
    return 0;
}
int main(){
    scanf("%d %d %d %d",&n,&m,&s,&t);
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        G[u].push_back(v);
        G[v].push_back(u);
        c[u][v] = w;
    }
    while(dinic_bfs()){
        while(int val = dinic_dfs(s,1000000000))
            flow += val,++_time;++_time;
    }
    printf("%d",flow);
}
