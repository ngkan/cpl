#include <bits/stdc++.h>
using namespace std;
int n,m;
int deg_in[105];
vector <int> G[105], ans;
queue <int> q;
int main(){
    while(scanf("%d %d",&n,&m) == 2){
        if (n == 0 && m == 0) break;
        ans.clear();
        for(int i=1;i<=n;i++) G[i].clear(), deg_in[i] = 0;
        for(int i=1;i<=m;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            G[x].push_back(y);
            deg_in[y] ++;
        }
        for(int i=1;i<=n;i++)
            if (!deg_in[i]) q.push(i);
        while(q.size()){
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for(int i=0;i<G[u].size();i++){
                int v = G[u][i];
                deg_in[v] --;
                if (!deg_in[v]) q.push(v);
            }
        }
        for(int i=0;i<n;i++) printf("%d ",ans[i]);
        printf("\n");
    }
}
