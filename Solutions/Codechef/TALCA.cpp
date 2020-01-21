#include <bits/stdc++.h>
using namespace std;
vector <int> G[200005];
int n, q;
int beg[200005], fin[200005], _time;
int lv[200005], p[200005][19];
void dfs(int u){
    beg[u] = ++ _time;
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i];
        if (v == p[u][0]) continue;
        p[v][0] = u;
        lv[v] = lv[u] + 1;
        dfs(v);
    }
    fin[u] = _time;
}
void pre(){
    lv[1] = 1;
    dfs(1);
    for(int k=1;k<=18;k++)
        for(int i=1;i<=n;i++)
            p[i][k] = p[p[i][k-1]][k-1];
}
int lca(int x,int y){
    for(int k=18;k>=0;k--) if (lv[p[x][k]] >= lv[y]) x = p[x][k];
    for(int k=18;k>=0;k--) if (lv[x] <= lv[p[y][k]]) y = p[y][k];
    if (x == y) return x;
    for(int k=18;k>=0;k--)
        if (p[x][k] != p[y][k])
            x = p[x][k], y = p[y][k];
    return p[x][0];
}
bool is_des(int u,int v){
    return (beg[u] <= beg[v] && fin[v] <= fin[u]);
}
bool check(int a,int b,int c){
    if (!is_des(a,b)) return false;
    if (!is_des(b,c)) return false;
    return true;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    pre();
    scanf("%d",&q);
    while(q--){
        int r,x,y;
        scanf("%d %d %d",&r,&x,&y);
        int top = lca(x,y);
        if (!is_des(top,r)) printf("%d\n",top);
        else{
            int top1 = lca(x,r), top2 = lca(y,r);
            if (top == top1 && top1 == top2) printf("%d\n",top);
            else if (top != top1) printf("%d\n",top1);
            else printf("%d\n",top2);
        }
    }
}
