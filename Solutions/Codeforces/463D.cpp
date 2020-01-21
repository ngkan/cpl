#include <bits/stdc++.h>
using namespace std;
int ans,n,k,a[1001],cnt[1001][1001];
vector<int> G[1001];
int val[1001];
int dfs(int u){
    if (val[u]) return val[u];
    int res = 0;
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i];
        res = max(res,dfs(v));
    }
    return val[u] = res+1;
}
int main(){
    cin >> n >> k;
    for(int p=1;p<=k;p++){
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                cnt[a[j]][a[i]]++;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if (cnt[i][j] == k) G[i].push_back(j);
    for(int i=1;i<=n;i++) ans = max(ans,dfs(i));
    printf("%d",ans);
}
