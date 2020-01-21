#include <bits/stdc++.h>
using namespace std;
int n,m,ans,CNT,num[400005],low[400005],_time,mark;
vector <int> G[400005];
vector <int> Gnew[400005];
bool check[400005], visited[400005], down[400005];
map <int,int> mp[400005];
map <int,int> noi[400005];
map <int,int> edge[400005];
int dsu[400005];
int dsup(int x){
    return x == dsu[x] ? x : dsu[x] = dsup(dsu[x]);
}
void dsuunion(int x,int y){
    if (dsup(x) == dsup(y)) return;
    dsu[dsup(y)] = dsup(x);
}
vector <int> inp1,inp2;
void dfs(int u,int p){
    num[u] = low[u] = ++_time;
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i];
        if (v == p) continue;
        if (!num[v]){
            dfs(v,u);
            low[u] = min(low[u],low[v]);
            if (num[u] >= low[v]) dsuunion(u,v);
        }
        else
            low[u] = min(low[u],num[v]);
    }
}
void dfs2(int u,int p){
    CNT++;
    visited[u] = 1;
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i];
        if (v == p || dsup(u) != dsup(v)) continue;
        if (!edge[u][v]){
            edge[u][v] = 2; edge[v][u] = 1;
        }
        if (visited[v]) continue;
        dfs2(v,u);
    }
}
void dfsnew(int u,int p){
    for(int i=0;i<Gnew[u].size();i++){
        int v = Gnew[u][i];
        if (v == p) continue;
        dfsnew(v,u);
        int ax = noi[u][v], ax2 = noi[v][u];
        if (down[v]){
            edge[ax][ax2] = 2, edge[ax2][ax] = 1;
            down[u] = 1;
        }
        else
            edge[ax][ax2] = 1, edge[ax2][ax] = 2;
    }
    if (u == mark) down[u] = 1;
}
int main(){
    for(int i=1;i<=400000;i++)
        dsu[i] = i;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
        inp1.push_back(x), inp2.push_back(y);
    }
    dfs(1,1);
    for(int i=1;i<=n;i++)
        if (!check[dsup(i)]){
            CNT = 0;
            check[dsup(i)] = 1;
            dfs2(i,i);
            if (ans < CNT)
                mark = dsup(i),
                ans = max(ans,CNT);
        }
    for(int u=1;u<=n;u++){
        for(int j=0;j<G[u].size();j++){
            int v = G[u][j];
            if (!mp[dsup(u)][dsup(v)] && dsup(u) != dsup(v))
                mp[dsup(u)][dsup(v)] = mp[dsup(v)][dsup(u)] = 1,
                Gnew[dsup(u)].push_back(dsup(v)),
                Gnew[dsup(v)].push_back(dsup(u)),
                noi[dsup(u)][dsup(v)] = u,
                noi[dsup(v)][dsup(u)] = v;
        }
    }
    dfsnew(dsup(1),dsup(1));
    printf("%d\n",ans);
    for(int i=0;i<inp1.size();i++){
        if (edge[inp1[i]][inp2[i]] == 2)
            printf("%d %d\n",inp1[i],inp2[i]);
        else
            printf("%d %d\n",inp2[i],inp1[i]);
    }
}
