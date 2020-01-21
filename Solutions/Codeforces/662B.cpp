#include <bits/stdc++.h>
using namespace std;
struct edge{
    int v, color;
    edge(int v,int color): v(v), color(color) {}
};
vector <edge> G[100005], Gtmp[100005];
int n,m,ans;
vector <int> res;
bool visited[100005],flip[100005];
vector <int> graph, change;
bool dfs(int u,int p,int type){
    visited[u] = 1;
    graph.push_back(u);
    for(int i=0;i<Gtmp[u].size();i++){
        edge e = Gtmp[u][i];
        if (e.v == p) continue;
        if (visited[e.v]){
            if (flip[e.v]) Gtmp[u][i].color = 1 - Gtmp[u][i].color, e = Gtmp[u][i];
            if (e.color != type)    return 0;
        }
        else if (!visited[e.v]) {
            if (e.color != type){
                if (flip[e.v]) return 0;
                change.push_back(e.v);
                flip[e.v] = 1;
                for(int j=0;j<Gtmp[e.v].size();j++)
                    Gtmp[e.v][j].color = 1 - Gtmp[e.v][j].color;
            }
            dfs(e.v,u,type);
        }
    }
    return 1;
}
vector <int> res_tmp;
bool check[100005];
void solve(int type){
    memset(visited,0,sizeof(visited));
    memset(flip,0,sizeof(flip));
    res_tmp.clear();
    for(int i=1;i<=n;i++) Gtmp[i] = G[i];
    for(int i=1;i<=n;i++)
        if (!visited[i]){
            graph.clear();
            change.clear();
            if (!dfs(i,i,type)) return;
            for(int j=0;j<change.size();j++)
                check[change[j]] = 1;
            if (change.size() < graph.size() - change.size())
                for(int j=0;j<change.size();j++)
                    res_tmp.push_back(change[j]);
            else
                for(int j=0;j<graph.size();j++)
                    if (!check[graph[j]]) res_tmp.push_back(graph[j]);
            for(int j=0;j<change.size();j++)
                check[change[j]] = 0;
        }
    if (ans == -1 || res.size() > res_tmp.size()) res = res_tmp, ans = res.size();
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        int x,y;
        char c;
        scanf("\n%d %d %c",&x,&y,&c);
        if (c == 'B')
            G[x].push_back(edge(y,0)),
            G[y].push_back(edge(x,0));
        else
            G[x].push_back(edge(y,1)),
            G[y].push_back(edge(x,1));
    }
    ans = -1;
    solve(0);
    solve(1);
    printf("%d\n",ans);
    for(int i=0;i<res.size();i++) printf("%d ",res[i]);
}
