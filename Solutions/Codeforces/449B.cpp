#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#define ll long long
using namespace std;
struct edge{
    ll v,w;
    edge(ll v=0,ll w=0): v(v), w(w) {}
};
struct cmp{
    bool operator ()(edge x,edge y){
        return x.w > y.w;
    }
};
bool operator < (edge x,edge y){
    return x.w < y.w;
}
ll n,m,k,d[100005];
vector <edge> G[100005];
priority_queue <edge,vector<edge>,cmp> pq;
int main(){
    scanf("%lld %lld %lld",&n,&m,&k);
    for(int i=1;i<=m;i++){
        ll u,v,w;
        scanf("%lld %lld %lld",&u,&v,&w);
        G[u].push_back(edge(v,2*w));
        G[v].push_back(edge(u,2*w));
    }
    for(int i=1;i<=k;i++){
        ll x,w;
        scanf("%lld %lld",&x,&w);
        G[1].push_back(edge(x,2*w+1));
    }
    for(int i=1;i<=n;i++) d[i] = (1ll<<60),sort(G[i].begin(),G[i].end());
    d[1] = 0;
    pq.push(edge(1,0));
    ll ans = 0;
    while(pq.size()){
        ll u = pq.top().v;
        ll du = pq.top().w;
        pq.pop();
        if (du != d[u]) continue;
        for(int i=0;i<G[u].size();i++){
            ll v = G[u][i].v;
            ll w = G[u][i].w;
            if (d[v] > du - du%2 + w)
                d[v] = du - du%2 + w,
                pq.push(edge(v,du - du%2 + w));
        }
    }
    for(int i=1;i<=n;i++) ans += d[i]%2;
    printf("%lld",k - ans);
}
