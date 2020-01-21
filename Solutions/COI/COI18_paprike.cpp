#include <bits/stdc++.h>
using namespace std;
int n,cnt,val,w[100005];
vector <int> G[100005];
int dfs(int u,int p){
    int res = w[u];
    vector <int> child;
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i];
        if (v == p) continue;
        child.push_back(dfs(v,u));
    }
    sort(child.begin(),child.end());
    int last = 0;
    for(last = 0;last < child.size();last ++)
        if (res + child[last] > val) break;
        else res += child[last];
    cnt += child.size() - last;
    return res;
}
int solve(){
    cnt = 0;
    dfs(1,1);
    return cnt;
}
int main(){
    scanf("%d %d",&n,&val);
    for(int i=1;i<=n;i++)
        scanf("%d",&w[i]);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    printf("%d",solve());
}