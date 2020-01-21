#include <bits/stdc++.h>
using namespace std;
struct edge{
    int u,v,w;
    edge(int u=0,int v=0,int w=0): u(u), v(v), w(w) {}
};
bool cmp(edge x,edge y){
    return x.w < y.w;
}
int dsup[10005];
int dsu_p(int x){
    return x == dsup[x] ? x : dsup[x] = dsu_p(dsup[x]);
}
void dsu_union(int x,int y){
    if (dsu_p(x) == dsu_p(y)) return;
    dsup[dsu_p(y)] = dsu_p(x);
}
int n,m,ans;
edge e[15005];
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        dsup[i] = i;
    for(int i=1;i<=m;i++)
        scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].w);
    sort(e+1,e+m+1,cmp);
    for(int i=1;i<=m;i++){
        if (dsu_p(e[i].u) == dsu_p(e[i].v)) continue;
        ans += e[i].w;
        dsu_union(e[i].u,e[i].v);
    }
    printf("%d",ans);
}
