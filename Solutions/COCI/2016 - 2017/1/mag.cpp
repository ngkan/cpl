#include <bits/stdc++.h>
#define ll long long
using namespace std;
int cnt,n,fi[1000005],se[1000005],up[1000005];
ll res1 = (ll)1e18,res2 = 1ll, val[1000005];
vector <int> G[1000005];
void dfs(int u,int p){
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i];
        if (v == p) continue;
        dfs(v,u);
        if (fi[v]+1 >= fi[u])
            se[u] = fi[u],
            fi[u] = fi[v] + 1;
        else if (fi[v]+1 >= se[u])
            se[u] = fi[v] + 1;
        if (se[v]+1 >= fi[u])
            se[u] = fi[u],
            fi[u] = se[v] + 1;
        else if (se[v]+1 >= se[u])
            se[u] = se[v] + 1;
    }
    if (val[u] != 1) fi[u] = se[u] = -(1<<30);
    else{
        if (0 >= fi[u])
            se[u] = fi[u],
            fi[u] = 0;
    }
}
void dfs2(int u,int p){
    ll cnt1 = 0;
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i];
        if (v == p) continue;
        if (fi[v]+1 != fi[u]) up[v] = max(up[u] + 1, fi[u] + 2);
        else up[v] = max(up[u] + 1,se[u] + 2);
        if (val[u] != 1) up[v] = -(1<<30);
        cnt = max(cnt,  max(fi[v] + se[v], fi[v] + up[v]));
        dfs2(v,u);
        cnt1 += max(0ll,(ll)fi[v] + 1);
    }
    cnt1 += max(0ll,(ll)up[u] + 1);
    if (cnt1 >= 1 && (double) log(val[u]) + log(res2) < (double) log(res1) + log(cnt1+1)){
        res1 = val[u];
        res2 = cnt1 + 1;
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
        scanf("%lld",&val[i]);
    for(int u=1;u<=n;u++){
        if (val[u] * res2 < res1)
            res1 = val[u],
            res2 = 1;
        for(int j=0;j<G[u].size();j++){
            int v = G[u][j];
            if (val[u] * val[v] * res2 < res1 * 2)
                res1 = val[u] * val[v],
                res2 = 2;
        }
    }
    for(int i=0;i<=n;i++) up[i] = fi[i] = se[i] = -(1<<30);
    dfs(1,1);
    dfs2(1,1);

    if (val[1] == 1) cnt = max(cnt,fi[1] + se[1]);
    if (cnt > 0){
        res1 = 1;
        res2 = cnt+1;
    }
    ll gcD = __gcd(res1,res2);
    res1/=gcD, res2/=gcD;
    cout << res1 << "/" << res2;
}
