#include <bits/stdc++.h>
using namespace std;
int test,n,m,res;
int depth[50001], p[50001], dsup[50001], dsuline[50001];
bool used[50001];
vector <int> xlist, ylist;
vector <int> X,Y;
vector <int> G[50001];
int dsu_p(int x){
    return dsup[x] == x ? x : dsup[x] = dsu_p(dsup[x]);
}
void dsu_union(int x,int y){
    if (dsu_p(x) == dsu_p(y)) return;
    dsup[dsu_p(y)] = dsu_p(x);
}
int dsu_line(int x){
    return dsuline[x] == x ? x : dsuline[x] = dsu_line(dsuline[x]);
}
void dsu_union_line(int x,int y){
    if (dsu_line(x) == dsu_line(y)) return;
    dsuline[dsu_line(y)] = dsu_line(x);
}
void dfs(int u,int P){
    used[u] = 1;
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i];
        if (v == P || used[v]) continue;
        depth[v] = depth[u] + 1;
        p[v] = u;
        dfs(v,u);
    }
}
void reset(int N){
    for(int i=0;i<N;i++)
        depth[i] = 1,   p[i] = i,   used[i] = 0,    dsup[i] = i,    dsuline[i] = i;
    res = 0;
    X.clear();
    Y.clear();
    for(int i=0;i<N;i++) G[i].clear();
}
void update(int x,int y){
    xlist.clear(),  ylist.clear();
    x = dsu_p(x), y = dsu_p(y);
    while(x != y){
        if (depth[x] > depth[y]){
            res --;
            xlist.push_back(x);
            x = dsu_p(p[x]);
        }
        else if (depth[x] < depth[y]){
            res --;
            ylist.push_back(y);
            y = dsu_p(p[y]);
        }
        else{
            res -= 2;
            xlist.push_back(x);
            ylist.push_back(y);
            x = dsu_p(p[x]);
            y = dsu_p(p[y]);
        }
    }
    xlist.push_back(x);
    ylist.push_back(y);
    for(int i = (int) xlist.size() - 1 ; i ; i -- )
        dsu_union(xlist[i],xlist[i-1]);
    for(int i = (int) ylist.size() - 1 ; i ; i --)
        dsu_union(ylist[i],ylist[i-1]);
}
void add(int u,int v){
    if (dsu_line(u) != dsu_line(v)){
        res ++;
        dsu_union_line(u,v);
    }
    else{
        if (dsu_p(u) == dsu_p(v)) return;
        update(u,v);
    }
}
int main(){
    scanf("%d",&test);
    while(test--){
        scanf("%d %d",&n,&m);
        reset(n);
        for(int i=0;i<m;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            if (dsu_p(x) != dsu_p(y))
                G[x].push_back(y), G[y].push_back(x), dsu_union(x,y);
            X.push_back(x);
            Y.push_back(y);
        }
        for(int i=0;i<n;i++)    dsup[i] = i;
        for(int i=0;i<n;i++)    if (!used[i]) dfs(i,i);
        for(int i=0;i<n;i++)    used[i] = 0;
        for(int i=0;i<m;i++){
            add(X[i],Y[i]);
            printf("%d\n",res);
        }
    }
}
