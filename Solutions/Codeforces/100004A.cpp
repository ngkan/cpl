#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct edge{
    ll v,w;
    edge(ll v=0ll,ll w=0ll): v(v), w(w) {}
};
vector <edge> G[100005];
ll n,c[100005],sum,ans=(ll) 1e18;
void dfs(int u,int p,ll now){
    ans = min(ans, sum - now + c[u]);
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i].v;
        if (v == p) continue;
        dfs(v,u,now+G[u][i].w);
    }
}
int main(){
    cin >> n;
    for(int i=0;i<=n;i++) cin >> c[i];
    for(ll i=1;i<=n;i++){
        ll x,y,z;
        cin >> x >> y >> z;
        G[x].push_back(edge(y,z));
        G[y].push_back(edge(x,z));
        sum += 2ll*z;
    }
    dfs(0,-1,0);
    cout << ans;
}
