#include <bits/stdc++.h>
using namespace std;
vector <int> adj[100005];
bool visited[100005];
int n,m,ans,num_ver,num_edge;
void dfs(int u){
    if (visited[u]) return;
    num_ver ++;
    visited[u] = 1;
    num_edge += adj[u].size();
    for(int i=0;i<adj[u].size();i++)
        dfs(adj[u][i]);
}
int main(){
    scanf("%d %d",&n,&m);
    while(m--){
        int x,y;
        scanf("%d %d",&x,&y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        if (visited[i]) continue;
        num_ver = 0, num_edge = 0;
        dfs(i);
        if (num_ver - 1 == num_edge/2) ans ++;
    }
    printf("%d",ans);
}
