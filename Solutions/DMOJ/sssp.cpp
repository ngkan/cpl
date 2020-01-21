#include <bits/stdc++.h>
using namespace std;
struct edge{
    int v,w;
    edge (int v=0,int w=0): v(v), w(w) {}
};
struct cmp{
    bool operator ()(edge x,edge y){
        return x.w > y.w;
    }
};
int n,m,d[1005];
vector <edge> G[1005];
priority_queue <edge,vector<edge>,cmp> pq;
void solve(){
    for(int i=1;i<=n;i++) d[i] = (1<<30);
    d[1] = 0;
    pq.push(edge(1,0));
    while(pq.size()){
        int u = pq.top().v;
        int du = pq.top().w;
        pq.pop();
        if (d[u] != du) continue;
        for(int i=0;i<G[u].size();i++){
            int v = G[u][i].v, w = G[u][i].w;
            if (d[v] > du + w){
                d[v] = du + w;
                pq.push(edge(v,d[v]));
            }
        }
    }
}
int main(){
    scanf("%d %d",&n,&m);
    while(m--){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        G[u].push_back(edge(v,w));
        G[v].push_back(edge(u,w));
    }
    solve();
    for(int i=1;i<=n;i++)
        if (d[i] == (1<<30)) printf("-1\n");
        else printf("%d\n",d[i]);
}
