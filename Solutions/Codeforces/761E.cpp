// code by khanh
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
vector <ll> G[35];
ll x[35],y[35];
ll ez = 35;
void solve(ll u,ll ban,ll time,ll p){
    ll dir = -1;
    for(int i=0;i<G[u].size();i++){
        #define wave time
        ll v = G[u][i];
        if (v == p) continue;
        dir++;
        while(dir == ban) dir++;
        if (dir == 0){
            x[v] = x[u];
            y[v] = y[u] + (1ll << (ez - wave));
            solve(v,2,time+1,u);
        }
        else if (dir == 1){
            x[v] = x[u] + (1ll<<(ez-wave));
            y[v] = y[u];
            solve(v,3,time+1,u);
        }
        else if (dir == 2){
            x[v] = x[u];
            y[v] = y[u] - (1ll<< (ez-wave));
            solve(v,0,time+1,u);
        }
        else {
            x[v] = x[u] - (1ll << (ez-wave));
            y[v] = y[u];
            solve(v,1,time+1,u);
        }
    }
}
int main(){
    ez = 35;
    cin >> n;
    for(int i=1;i<n;i++){
        ll x,y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
        if (G[i].size() > 4) return cout << "NO",0;
    cout << "YES\n";
    solve(1,-1,0,-1);
    for(int i=1;i<=n;i++)
        cout << x[i] << ' ' << y[i] << endl;
}
