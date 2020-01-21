/*
http://codeforces.com/problemset/problem/337/D
*/
#include <bits/stdc++.h>
using namespace std;
int n,m,d,ans;
bool mark[100005];
int fi[100005], se[100005], up[100005];
vector <int> G[100005];
int dfs(int u,int p){
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i];
        if (v == p) continue;
        dfs(v,u);
        if      (fi[v]+1 >= fi[u])    se[u] = fi[u], fi[u] = fi[v]+1;
        else if (fi[v]+1 >= se[u])    se[u] = fi[v]+1;
        if      (se[v]+1 >= fi[u])    se[u] = fi[u],  fi[u] = se[v]+1;
        else if (se[v]+1 >= se[u])    se[u] = se[v]+1;
    }
    if (mark[u]){
        if (0 >= fi[u])
            se[u] = fi[u], fi[u] = 0;
        else if (0 >= se[u])
            se[u] = 0;
    }
}
void dfs2(int u,int p){
    if (fi[u] <= d && up[u] <= d)
        ans++;
    //, cout << u << ' ' << up[u] << ' ' << fi[u] << ' ' << se[u] << endl;
    vector <int> l(G[u].size()+5,-(1<<30)), r(G[u].size()+5,-(1<<30));
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i];
        if (i) l[i] = l[i-1];
        if (v != p) l[i] = max(l[i], fi[v]);
        //cout << l[i] << ' ';
    }
    for(int i=G[u].size()-1;i>=0;i--){
        int v = G[u][i];
        r[i] = r[i+1];
        if (v != p) r[i] = max(r[i], fi[v]);
        //cout << r[i] << ' ';
    }
    //cout << endl;
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i];
        if (v == p) continue;
        if (i) up[v] = max(up[v], l[i-1] + 2);
        up[v] = max(up[v], r[i+1] + 2);
        up[v] = max(up[v], up[u] + 1);
        if (mark[u]) up[v] = max(up[v], 1);
        dfs2(v,u);
    }
}
int main(){
    scanf("%d %d %d",&n,&m,&d);
    for(int i=1;i<=m;i++){
        int x;
        scanf("%d",&x);
        mark[x] = 1;
    }
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for(int i=0;i<=n;i++)
        fi[i] = se[i] = up[i] = -(1<<30);
    dfs(1,1);
    dfs2(1,1);
    printf("%d",ans);
}
