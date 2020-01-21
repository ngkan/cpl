#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int,int> ii;
int n,m,indeg[200005];
vector <int> G[200005],ans;
priority_queue<int> pq;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){ // init
        int x,y;
        scanf("%d %d",&x,&y);
        G[y].push_back(x);
        indeg[x] ++;
    }
    for(int i=1;i<=n;i++) if (!indeg[i]) pq.push(i);
    while(pq.size()){
        int u = pq.top();
        pq.pop();
        ans.push_back(u);
        for(int i=0;i<G[u].size();i++){
            int v = G[u][i];
            indeg[v] --;
            if (!indeg[v]) pq.push(v);
        }
    }
    for(int i=n-1;i>=0;i--) printf("%d ",ans[i]);
}
