#include <bits/stdc++.h>
using namespace std;
int n,m,p,ans;
vector <int> Gn[50005];
int pair_n[50005], pair_m[50005];
bool visited[50005];
bool dfs(int u){
    if (!u) return 1;
    for(int i=0;i<Gn[u].size();i++){
        int v = Gn[u][i];
        if (!visited[v]){
            visited[v] = 1;
            if (dfs(pair_m[v])){
                pair_n[u] = v;
                pair_m[v] = u;
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    scanf("%d %d %d",&n,&m,&p);
    while(p--){
        int x,y;
        scanf("%d %d",&x,&y);
        Gn[x].push_back(y);
    }
    int ahi = -1;
    while(ans < n && ans != ahi){
        ahi = ans;
        fill(visited+1,visited+n+1,0);
        for(int i=1;i<=n;i++){
            if (!pair_n[i] && dfs(i))
                ans++;
        }
    }
    printf("%d",ans);
}
