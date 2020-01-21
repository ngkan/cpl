#include <bits/stdc++.h>
using namespace std;
int test;
int n,g,k,sum,res;
vector <int> G[100005];
map <int,bool> guess[100005];
void prep(int u,int p){
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i];
        if (v == p) continue;
        sum += guess[u][v];
        prep(v,u);
    }
}
void dfs(int u,int p){
    res += (sum >= k);
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i];
        if (v == p) continue;
        sum -= guess[u][v];
        sum += guess[v][u];
        dfs(v,u);
        sum += guess[u][v];
        sum -= guess[v][u];
    }
}
int main(){
    scanf("%d",&test);
    while(test--){
        res = sum = 0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            G[i].clear(),
            guess[i].clear();
        for(int i=1;i<n;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            G[x].push_back(y);
            G[y].push_back(x);
        }
        scanf("%d %d",&g,&k);
        for(int i=1;i<=g;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            guess[x][y] = 1;
        }
        prep(1,1);
        dfs(1,1);
        if (res == 0) printf("0/1\n");
        else printf("%d/%d\n",res/__gcd(res,n),n/__gcd(res,n));
    }
}
