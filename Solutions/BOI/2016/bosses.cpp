#include <bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
typedef pair<int,int> ii;
vector <int> G[5001];
bool used[5001];
int n,ans = 999999999,tmp;
int bfs(int root){
    memset(used,0,sizeof(used));
    queue <ii> q;
    q.push(mk(root,1));
    int cnt = n,res = 0;
    used[root] = 1;
    while(q.size()){
        int u = q.front().fi,level=q.front().se;
        q.pop();
        res += level;
        cnt--;
        for(int i=0;i<G[u].size();i++){
            int v = G[u][i];
            if (used[v]) continue;
            used[v] = 1;
            q.push(mk(v,level+1));
        }
    }
    if (cnt > 0) return 999999999;
    return res;
}
void solve(int root){
    ans = min(ans,bfs(root));
}
int main(){
    //freopen("t.in.7","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int k,x;
        scanf("%d",&k);
        for(int j=1;j<=k;j++) scanf("%d",&x),G[x].push_back(i);
    }
    for(int i=1;i<=n;i++) solve(i);
    printf("%d",ans);
}
