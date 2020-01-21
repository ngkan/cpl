#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int,int> ii;
int n,m,k,val[200005];
bool visited[200005];
vector <ii> G[200005];
void gg(void){
    printf("-1");
    exit(0);
}
void resetvisit(void){
    for(int i=1;i<=n;i++) visited[i] = 0;
}
void dfs(int u,int p){
    visited[u] = 1;
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i].fi, w = G[u][i].se;
        if (v == p) continue;
        if (visited[v]){
            if (val[v] != (val[u]^w)) gg();
        }
        else
            val[v] = (val[u]^w),
            dfs(v,u);
    }
}
void minidfs(int u,int p){
    visited[u] = 1;
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i].fi;
        if (v == p || visited[v]) continue;
        minidfs(v,u);
    }
}
vector <int> spot;
int main(){
    scanf("%d %d %d",&n,&m,&k);
    while(m--){
        int x,y,v;
        scanf("%d %d %d",&x,&y,&v);
        G[x].push_back(ii(y,v));
        G[y].push_back(ii(x,v));
    }
    for(int i=1;i<=n;i++){
        if (visited[i]) continue;
        spot.push_back(i);
        minidfs(i,i);
    }
    resetvisit();
    for(int i=0;i<spot.size()-1;i++)
        dfs(spot[i],spot[i]);
    val[spot[spot.size()-1]] = k-1;
    dfs(spot[spot.size()-1],spot[spot.size()-1]);
    for(int i=1;i<=n;i++)
        printf("%d ",val[i]);
}
