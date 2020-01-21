#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
ll c[300005];
priority_queue<ll> slope[300005];
vector <ll> G[300005];
ll val[300005];
void dfs(int u){
    if (u > n){
        return;
    }

    for(auto v: G[u]){
        dfs(v);
        val[u] += val[v] + c[v];
        if (v > n){
            slope[v].push(c[v]);
            slope[v].push(c[v]);
        }
        else{
            ll x = slope[v].top();
            slope[v].pop();
            ll y = slope[v].top();
            slope[v].pop();

            slope[v].push(x + c[v]);
            slope[v].push(y + c[v]);
        }
    }

    for(auto v: G[u]){
        if (slope[v].size() > slope[u].size())
            slope[u].swap(slope[v]);
    }

    for(auto v: G[u]){
        while(slope[v].size())
            slope[u].push(slope[v].top()),
            slope[v].pop();
    }

    for(int _=0;_<G[u].size()-1;_++)
        slope[u].pop();

}
int main(){
    iostream::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=2;i<=n+m;i++){
        int p;
        cin >> p >> c[i];
        G[p].push_back(i);
    }
    dfs(1);
    vector <ll> mjk;
    while(!slope[1].empty()){
        mjk.push_back(slope[1].top());
        slope[1].pop();
    }
    mjk.push_back(0);
    reverse(mjk.begin(), mjk.end());
    for(int i=1;i<mjk.size();i++){
        val[1] -= 1ll * (m+1-i) * (mjk[i] - mjk[i-1]);
    }
    cout << val[1];
}
