#include <stdio.h>
#include <vector>
#include <iostream>
#define int long long
using namespace std;
int n, cnt[5005], cnt2[5005], tmp[5005], ans;
vector <int> G[5005];
int dfs(int u,int p,int lv){
   int mxlv = lv;
   for(int i=0;i<G[u].size();i++){
        int v = G[u][i];
        if (v == p) continue;
        ++tmp[lv];
        mxlv = max(mxlv, dfs(v,u,lv+1));
    }
    return mxlv;
}
signed main(){
    cin >> n;
    for(int i=1;i<n;i++){
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for(int u=1;u<=n;u++){
        for(int i=0;i<=n;i++)   cnt[i] = cnt2[i] = tmp[i] = 0;
        for(int i=0;i<G[u].size();i++){
            ++cnt[0] ;
            int mxlv = dfs(G[u][i],u,1);
            for(int j=0;j<=mxlv;j++){
                ans -= tmp[j] * (tmp[j]-1) * (tmp[j]-2) / 6;
                ans -= cnt2[j] * tmp[j];
                ans -= cnt[j] * tmp[j] * (tmp[j]-1) / 2;
                cnt[j] += tmp[j];
                cnt2[j] += tmp[j] * (tmp[j]-1) / 2;
                tmp[j] = 0;
            }
        }
        for(int i=0;i<=n;i++)   ans += cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6;
    }
    cout << ans;
}
