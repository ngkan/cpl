#include <bits/stdc++.h>
using namespace std;
int n,m, low[2005], num[2005], _time, tplt[2005], cnt;
bool del[2005];
vector <int> G[2005];
stack <int> st;
bool have_p[2005], have_des[2005];
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
            if (tplt[i] != tplt[G[i][j]]) have_des[tplt[i]] = 1, have_p[tplt[G[i][j]]] = 1;
    printf("YES\n");
    for(int i=1;i<=n;i++) if (tplt[i] == i && !have_des[i]) printf("%d ",i);
    for(int i=1;i<=n;i++) if (tplt[i] == i && !have_p[i]) printf("%d",i);
}
