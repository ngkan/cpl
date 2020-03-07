#include <bits/stdc++.h>
using namespace std;
struct node{
    int u,dis;
};
node mk(int a,int b){
    node t;
    t.u = a;
    t.dis = b;
    return t;
}
bool operator > (node x,node y){
    return x.dis > y.dis;
}
int n,m,d[100005];
vector <node> G[100005];
int inq[100005];
void ford_bellman(int s,int t){
    // inq : ktra xem trong q co node i hay chua
    for(int i=1;i<=n;i++) d[i] = INT_MAX;
    queue <node> q;
    q.push(mk(s,0));
    inq[s] = 1;
    while(q.size()){
        int u = q.front().u;
        int disu = q.front().dis;
        q.pop();
        inq[u] = 0;

        for(int i=0;i<G[u].size();i++){
            int v = G[u][i].u;
            int l = G[u][i].dis;
            if (disu + l < d[v]){
                d[v] = disu + l;
                if (!inq[v]){
                    inq[v] = 1;
                    q.push(mk(v,d[v]));
                }
            }
        }
    }
    printf("%d\n",d[t]);
}
void dijkstra(int s,int t){
    priority_queue< node,vector<node>,greater<node> > pq;
    for(int i=1;i<=n;i++) d[i] = INT_MAX;
    d[s] = 0;
    pq.push(mk(s,0));
    while(pq.size()){
        int u = pq.top().u;
        int du = pq.top().dis;
        pq.pop();
        if (du != d[u]) continue;
        for(int i=0;i<G[u].size();i++){
            int v = G[u][i].u;
            int l = G[u][i].dis;
            if (du + l < d[v]){
                d[v] = du + l;
                pq.push(mk(v,d[v]));
            }
        }
    }
    printf("%d\n",d[t]);
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        int x,y,w;
        scanf("%d %d %d",&x,&y,&w);
        G[x].push_back(mk(y,w));
    }
    ford_bellman(1,n);
    dijkstra(1,n);
}
