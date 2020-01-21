#include <bits/stdc++.h>
using namespace std;
int n,m,cnt;
bool used[100005], visited[100005];
vector <int> G[100005];
vector <int> ax[100005];
vector <int> res1,res2;
void gg(){
    printf("-1");
    exit(0);
}
void dfs(int u,int p){
    cnt ++;
    visited[u] = 1;
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i];
        if (v == p || visited [v]) continue;
        dfs(v,u);
        ax[u].push_back(v);
    }
}
void dfs2(int u){
    int cnt_ = 0;
    for(int i=0;i<ax[u].size();i++){
        int v = ax[u][i];
        dfs2(v);
        if (!used[v])
            cnt_++,
            used[v] = 1,
            res1.push_back(u),
            res2.push_back(v);
    }
    if (cnt_ % 2)
        used[u] = 1;
}
int main(){
    scanf("%d %d",&n,&m);
    while(m--){
        int x,y;
        scanf("%d %d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        if (visited[i]) continue;
        cnt = 0;
        dfs(i,i);
        if (cnt % 2) gg();
        else dfs2(i);
    }
    printf("%d\n",res1.size());
    for(int i=0;i<res1.size();i++)
        printf("%d %d\n",res1[i],res2[i]);
}
