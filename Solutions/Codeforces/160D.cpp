#include <bits/stdc++.h>
using namespace std;
struct edge{
    int u,v,w,id;
    edge (int u=0,int v=0,int w=0,int id=0): u(u), v(v), w(w), id(id) {}
};
bool cmp_edge1(edge x,edge y){
    return x.w < y.w;
}
int dsup[100005];
int dsu_p(int x){
    return dsup[x] == x? x: dsup[x] = dsu_p(dsup[x]);
}
void dsu_union(int x,int y){
    if (dsu_p(x) == dsu_p(y)) return;
    dsup[dsu_p(y)] = dsu_p(x);
}
int n,m;
edge e[100005];
vector <edge> G[100005];
vector <int> mst;
vector <edge> Gmst[100005];
int ans[100005];
vector <int> vertices;
int num[100005], low[100005], _time;
void dfs(int u,int p){
    num[u] = low[u] = ++_time;
    int cnt_meet = 0;
    for(int i=0;i<Gmst[u].size();i++){
        edge tmp = Gmst[u][i];
        if (tmp.v == p){
            cnt_meet ++;
            if (cnt_meet == 1) continue;
        }
        if (num[tmp.v]){
            low[u] = min(low[u],num[tmp.v]);
            ans[tmp.id] = 1;
        }
        else{
            dfs(tmp.v, u);
            if (low[tmp.v] > num[u]) ans[tmp.id] = 2;
            else ans[tmp.id] = 1;
            low[u] = min(low[u], low[tmp.v]);
        }
    }
}
void solve(){
    sort(e+1,e+m+1,cmp_edge1);
    for(int i=1;i<=n;i++) dsup[i] = i;

    for(int i=1;i<=m;i++){
        int last;
        for(last=i;last<=m;last++)
            if (e[last].w != e[i].w) break;
        last --;
        for(int j=i;j<=last;j++){
            int u = dsu_p(e[j].u), v = dsu_p(e[j].v);
            if (u == v) continue;
            vertices.push_back(u);
            vertices.push_back(v);
            Gmst[u].push_back(edge(u,v,e[j].w,e[j].id));
            Gmst[v].push_back(edge(v,u,e[j].w,e[j].id));
        }
        for(int j=0;j<vertices.size();j++)
            if (!num[vertices[j]])
                dfs(vertices[j],vertices[j]);

        for(int j=0;j<vertices.size();j++)
            num[vertices[j]] = low[vertices[j]] = 0,
            Gmst[vertices[j]].clear();
        vertices.clear();

        for(int j=i;j<=last;j++) dsu_union(dsu_p(e[j].u),dsu_p(e[j].v));
        i = last;
    }
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].w);
        e[i].id = i;
        G[e[i].u].push_back(e[i]);
        G[e[i].v].push_back(edge(e[i].v,e[i].u,e[i].w,e[i].id));
    }
    solve();
    for(int i=1;i<=m;i++)
        if (ans[i] == 0) printf("none\n");
        else if (ans[i] == 1) printf("at least one\n");
        else printf("any\n");
}
