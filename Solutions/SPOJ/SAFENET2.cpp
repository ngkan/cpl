#include <bits/stdc++.h>
using namespace std;
int n,m,low[30005],num[30005],_time,ans;
vector <int> G[30005];
stack <int> st;
void dfs(int u){
    num[u] = low[u] = ++_time;
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i];
        if (num[v]) low[u] = min(low[u], num[v]);
        else{
            st.push(u);
            dfs(v);
            low[u] = min(low[u],low[v]);
            if (low[v] >= num[u]){
                set <int> s;
                int x;
                do{
                    x = st.top(); st.pop();
                    s.insert(x);
                } while(x != u);
                ans = max(ans, (int)s.size());
            }
        }
    }
    st.push(u);
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
        if (!num[i]) dfs(i);
    printf("%d",max(ans,1));
}
