#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
int num[10004],low[10004],_time;
bool del[10004];
vector <int> adj[10004];
stack <int> st;
void dfs(int u){
    num[u] = low[u] = ++_time;
    st.push(u);
    for(int i=0;i<adj[u].size();i++){
        int v = adj[u][i];
        if      (!num[v]) dfs(v), low[u] = min(low[u], low[v]);
        else if (!del[v]) low[u] = min(low[u],num[v]);
    }
    if (low[u] >= num[u]){
        ans ++;
        while (st.top() != u)
            del[st.top()] = 1, st.pop();
        del[st.top()] = 1, st.pop();
    }
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        adj[x].push_back(y);
    }
    for(int i=1;i<=n;i++)
        if (!num[i]) dfs(i);
    printf("%d",ans);
}
