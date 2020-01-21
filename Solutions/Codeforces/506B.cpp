#include <bits/stdc++.h>
using namespace std;
int n,m;
vector <int> G[100005];
int low[100005],num[100005],_time;
bool del[100005];
stack <int> st;
int tplt_cnt, tplt_size[100005], tplt_type[100005];
int ans;

vector <int> Gvh[100005];
int vo_huong_cnt, vo_huong_type[100005], vo_huong_size[100005];
bool visited[100005];
void dfs_vo_huong(int u){
    if (visited[u]) return;
    visited[u] = 1;
    vo_huong_type[u] = vo_huong_cnt;
    vo_huong_size[vo_huong_cnt] ++;
    for(int i=0;i<Gvh[u].size();i++){
        int v = Gvh[u][i];
        dfs_vo_huong(v);
    }
}

bool used_tplt[100005];
bool check[100005];
void dfs(int u){
    low[u] = num[u] = ++_time;
    st.push(u);
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i];
        if      (!num[v])   dfs(v), low[u] = min(low[u], low[v]);
        else if (!del[v])   low[u] = min(low[u], num[v]);
    }
    if (num[u] == low[u]){
        ++tplt_cnt;
        int x;
        do{
            x = st.top();
            tplt_size[tplt_cnt] ++;
            tplt_type[x] = tplt_cnt;
            del[x] = 1;
            st.pop();
        }   while(x != u);
    }
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        G[x].push_back(y);
        Gvh[x].push_back(y);
        Gvh[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
        if (!visited[i] && Gvh[i].size()){
            vo_huong_cnt++;
            dfs_vo_huong(i);
        }
    for(int i=1;i<=n;i++)
        if (!num[i] && G[i].size()) dfs(i);

    for(int i=1;i<=n;i++){
        if (!used_tplt[tplt_type[i]] && G[i].size()){
            used_tplt[tplt_type[i]] = 1;
            if (tplt_size[tplt_type[i]] >= 2)   check[vo_huong_type[i]] = 1;
        }
    }
    for(int i=1;i<=vo_huong_cnt;i++)    ans += vo_huong_size[i] - (1-check[i]);

    printf("%d",ans);
}
