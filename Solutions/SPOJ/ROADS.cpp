#include <bits/stdc++.h>
using namespace std;
struct node{
    int u,fee,dis;
};
node mk(int a,int b,int c){
    node t;
    t.u = a;
    t.fee = b;
    t.dis = c;
    return t;
}
bool operator > (node x,node y){
    return x.fee > y.fee;
}
priority_queue <node,vector <node>,greater<node> > pq;
int test,n,m,k,d[105];
vector <node> G[105];
void solve(){
    pq.push(mk(1,0,0));
    while(pq.size()){
        int u = pq.top().u;
        int disu = pq.top().dis;
        int feeu = pq.top().fee;
        pq.pop();
        if (d[u] <= disu) continue;
        d[u] = disu;
        for(int i=0;i<G[u].size();i++){
            int v = G[u][i].u;
            int l = G[u][i].dis;
            int c = G[u][i].fee;
            if (feeu + c <= k)
                pq.push(mk(v,feeu+c,d[u] + l));
        }
    }
    if (d[n] == INT_MAX) printf("-1\n");
    else printf("%d\n",d[n]);
}
int main(){
    scanf("%d",&test);
    while(test--){
        scanf("%d %d %d",&k,&n,&m);
        for(int i=1;i<=n;i++) G[i].clear(),d[i] = INT_MAX;
        for(int i=1;i<=m;i++){
            int x,y,w,fee;
            scanf("%d %d %d %d",&x,&y,&w,&fee);
            G[x].push_back(mk(y,fee,w));
        }
        solve();
    }
}
