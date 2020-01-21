#include <stdio.h>
#include <vector>
using namespace std;
struct edge{
    int v,w;
    edge (int v=0,int w=0): v(v), w(w) {}
};
int n,x,ans,sum,fi[100005],se[100005];
vector <edge> G[100005];
void dfs(int u,int p){
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i].v;
        if (v == p) continue;
        dfs(v,u);
        if (fi[v] + G[u][i].w >= fi[u])
            se[u] = fi[u],
            fi[u] = fi[v] + G[u][i].w;
        else if (fi[v] + G[u][i].w >= se[u])
            se[u] = fi[v] + G[u][i].w;
    }
    ans = max(ans, fi[u] + se[u]);
}
int main(){
    scanf("%d %d",&n,&x);
    for(int i=1;i<n;i++){
        int x,y,w;
        scanf("%d %d %d",&x,&y,&w);
        G[x].push_back(edge(y,w));
        G[y].push_back(edge(x,w));
        sum += 2*w;
    }
    dfs(x,x);
    printf("%d",sum-ans);
}
