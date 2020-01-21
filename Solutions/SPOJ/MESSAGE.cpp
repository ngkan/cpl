#include <bits/stdc++.h>
using namespace std;
int n,m,num[805],low[805],_time,tplt[805],cnt;
vector <int> G[805];
stack <int> st;
bool del[805],check[805];
void dfs(int u){
    low[u] = num[u] = ++_time;
    st.push(u);
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i];
        if (!num[v]) dfs(v), low[u] = min(low[u], low[v]);
        else if (!del[v]) low[u] = min(low[u], num[v]);
    }
    if (low[u] == num[u]){
        cnt++;
        while(st.top() != u) tplt[st.top()] = u, del[st.top()] = 1, st.pop();
        tplt[st.top()] = u, del[st.top()] = 1, st.pop();
    }
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        G[x].push_back(y);
    }
    for(int i=1;i<=n;i++) if (!num[i]) dfs(i);
    for(int i=1;i<=n;i++)
        for(int j=0;j<G[i].size();j++)
            if (tplt[i] != tplt[G[i][j]]) cnt -= (1-check[tplt[G[i][j]]]), check[tplt[G[i][j]]] = 1;
    printf("%d",cnt);
}
