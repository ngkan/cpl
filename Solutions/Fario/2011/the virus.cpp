#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
typedef pair<ll,ll> ii;
struct edge{
    ll v,w;
    edge (ll v=0,ll w=0): v(v), w(w) {}
};
const int N = (int) 1e5 + 5;
ll n,val[N], cnt[N], t[N], ans;
vector <edge> G[N];
bool cmp(ii x,ii y){
    return 1.0 * x.fi / x.se > 1.0 * y.fi / y.se;
}
void dfs(ll u,ll p){
    vector <ii> ahi;
    for(int i=0;i<G[u].size();i++){
        ll v = G[u][i].v, w = G[u][i].w;
        if (v == p) continue;
        dfs(v,u);
        ans += cnt[v] * w;
        ahi.push_back(ii(cnt[v], t[v] + 2 * w));
    }
    sort(ahi.begin(),ahi.end(),cmp);
    ll ax = 0;
    for(int i=0;i<ahi.size();i++)
        ans += ax * ahi[i].fi,
        ax += ahi[i].se,
        cnt[u] += ahi[i].fi,
        t[u] += ahi[i].se;

    cnt[u] += val[u];
    //cout << u << ' ' << t[u] << endl;
}
int main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&val[i]);
    for(int i=1;i<n;i++){
        ll x,y,w;
        scanf("%lld %lld %lld",&x,&y,&w);;
        G[x].push_back(edge(y,w));
        G[y].push_back(edge(x,w));
    }
    dfs(1,1);
    printf("%lld",ans);
}
