#include <bits/stdc++.h>
using namespace std;
struct edge{
    int v,w;
    edge (int v=0,int w=0): v(v), w(w) {}
};
struct cmp{
    bool operator() (edge x,edge y){
        return x.w > y.w;
    }
};
priority_queue <edge,vector<edge>,cmp> pq;
int n,m,ans,d[10005];
vector <edge> G[10005];
bool in[10005];
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        int x,y,w;
        scanf("%d %d %d",&x,&y,&w);
        G[x].push_back(edge(y,w));
        G[y].push_back(edge(x,w));
    }
    for(int i=2;i<=n;i++) d[i] = (1<<30);
    pq.push(edge(1));
    while(pq.size()){
        int u   = pq.top().v;
        int dis = pq.top().w;
        pq.pop();
        if (dis != d[u]) continue;
        ans += dis;
        in[u] = 1;
        for(int i=0;i<G[u].size();i++){
            int v = G[u][i].v;
            int w = G[u][i].w;
            if (in[v]) continue;
            if (w < d[v]){
                d[v] = w;
                pq.push(edge(v,d[v]));
            }
        }
    }
    printf("%d",ans);
}
