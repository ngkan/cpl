#include <bits/stdc++.h>
using namespace std;
struct edge{
    int x,y;
};
edge mk_edge(int u,int v){
    edge tmp;
    tmp.x = u;
    tmp.y = v;
    return tmp;
}
int dsu_p[100005],dsu_size[100005];
int dsu_P(int x){
    return dsu_p[x] == x ? x : dsu_p[x] = dsu_P(dsu_p[x]);
}
bool dsu_same(int x,int y){
    return dsu_P(x) == dsu_P(y);
}
void dsu_union(int x,int y){
    if (dsu_same(dsu_P(x),dsu_P(y))) return;
    dsu_p[dsu_P(y)] = dsu_P(x);
}
int n,m,cnt,cntedge,cntver;
int res[100005];
bool visited[100005],tplt[100005];
bool check_e[200005],ktra[100005];
vector <edge> lst;
vector <int> G[100005],Gtmp[100005],root;
void dfs_dem(int u,int p){
    tplt[u] = 1;
    cntver++;
    for(int i=0;i<Gtmp[u].size();i++){
        cntedge++;
        int v = Gtmp[u][i];
        if (tplt[v]) continue;
        dfs_dem(v,u);
    }
}
void dfs(int u,int p,int pos){
    visited[u] = 1;
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i];
        if (v == p) continue;
        if (v == root[pos]){
            if (!res[v]) res[v] = u;
        }
        else{
            if (visited[v]) continue;
            res[v] = u;
            dfs(v,u,pos);
        }
    }
}
int main(){
    for(int i=1;i<=100000;i++) dsu_p[i] = i,dsu_size[i] = 1;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        Gtmp[x].push_back(y);
        Gtmp[y].push_back(x);
        lst.push_back(mk_edge(x,y));
    }
    for(int i=1;i<=n;i++){
        if (!tplt[i]){
            cntedge = 0;
            cntver = 0;
            dfs_dem(i,i);
            if (cntver == cntedge/2 + 1) return printf("NIE"),0;

        }
    }
    for(int i=0;i<lst.size();i++){
        if (dsu_same(lst[i].x,lst[i].y)) continue;
        check_e[i] = 1;
        dsu_union(lst[i].x,lst[i].y);
        G[lst[i].x].push_back(lst[i].y);
        G[lst[i].y].push_back(lst[i].x);
    }
    for(int i=0;i<lst.size();i++){
        if (!check_e[i]){
            if (ktra[dsu_P(lst[i].x)]) continue;
            ktra[dsu_P(lst[i].x)] = 1;
            G[lst[i].x].push_back(lst[i].y);
            G[lst[i].y].push_back(lst[i].x);
            root.push_back(lst[i].x);
        }
    }
    for(int i=0;i<root.size();i++)  dfs(root[i],root[i],i);
    printf("TAK\n");
    for(int i=1;i<=n;i++) printf("%d\n",res[i]);
}
/*
8 8
1 2
2 3
1 4
4 5
5 6
6 7
6 1
1 8
*/
