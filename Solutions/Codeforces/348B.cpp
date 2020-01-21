#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
vector <ll> G[100005];
ll ans, w[100005], sum, key[100005];
ll lcm(ll x,ll y){
    return x / __gcd(x,y) * y;
}
void gg(void){
    printf("%lld",sum);
    exit(0);
}
void dfs(int u,int p){
    key[u] = 1;
    if (u != 1 && G[u].size() == 1)
        return;
    ll _min = (1ll << 60);
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i];
        if (v == p) continue;
        dfs(v,u);
        if (__gcd(key[u],key[v]) > ((ll) 1e18 / key[v])) gg();
        key[u] = lcm(key[u], key[v]);
        _min = min(_min, w[v]);
    }
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i];
        if (v == p) continue;
        ans += w[v] - (_min / key[u]) * key[u];
        w[v] = (_min / key[u]) * key[u];
        w[u] += w[v];
    }
    if (u != 1)
        key[u] *= (G[u].size() - 1);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&w[i]),
        sum += w[i];
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(1,1);
    printf("%lld",ans);
}
