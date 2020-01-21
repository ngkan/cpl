#include <bits/stdc++.h>
using namespace std;
const int M = 6005;
int n,r[M],ans = 1;
const int oo = (1<<30);
vector <int> G[M];
int p[M], depth[M];
vector <int> dp1[M], dp2[M];
void dfs_tmp(int u){
    depth[u] = 1;
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i];
        if (v == p[u]) continue;
        p[v] = u;
        dfs_tmp(v);
        depth[u] = max(depth[u], depth[v] + 1);
    }
}
void dfs(int u){
    dp1[u][1] = dp2[u][1] = r[u];
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i];
        if (v == p[u]) continue;
        dfs(v);
        for(int cnt = 1;cnt <= depth[v] + 1;cnt ++){
            dp1[u][cnt] = min(dp1[u][cnt], dp1[v][cnt]);
            if (r[u] > dp1[v][cnt-1]) dp1[u][cnt] = min(dp1[u][cnt], r[u]);
            dp2[u][cnt] = max(dp2[u][cnt], dp2[v][cnt]);
            if (r[u] < dp2[v][cnt-1]) dp2[u][cnt] = max(dp2[u][cnt], r[u]);
            if (dp1[u][cnt] != oo)  ans = max(ans, cnt);
            if (dp2[u][cnt] != -oo) ans = max(ans, cnt);
        }
    }
}
vector < vector<int> > table1_left, table1_right;
vector <int> v;
void solve(int u){
    v.clear();
    v.push_back(0);
    for(int i=0;i<G[u].size();i++)
        if (G[u][i] != p[u]) v.push_back(G[u][i]);

    table1_left.clear();
    table1_right.clear();
    table1_left.assign(v.size() + 5, vector<int>(depth[u] + 5));
    table1_right.assign(v.size() + 5, vector<int>(depth[u] + 5));

    for(int i=0;i<=v.size()+1;i++)
        for(int cnt=0;cnt<=depth[u] + 3;cnt++)
            table1_left [i][cnt] = oo,
            table1_right[i][cnt] = oo;


    for(int i=1;i<v.size();i++)
        for(int cnt=1;cnt<=depth[u] + 1;cnt++){
            table1_left[i][cnt] = table1_left[i-1][cnt];
            if (cnt <= depth[v[i]] + 1) table1_left[i][cnt] = min(table1_left[i-1][cnt],  dp1[v[i]][cnt]);
        }


    for(int i=v.size()-1;i>=1;i--)
        for(int cnt=1;cnt<=depth[u] + 1;cnt++){
            table1_right[i][cnt] = table1_right[i+1][cnt];
            if (cnt <= depth[v[i]] + 1)table1_right[i][cnt] = min(table1_right[i+1][cnt], dp1[v[i]][cnt]);
        }

    for(int i=1;i<v.size();i++){
        for(int cnt=1;cnt<=depth[v[i]] + 2;cnt++){
            int tmp = dp2[v[i]][cnt];
            if (r[u] < dp2[v[i]][cnt-1])    tmp = max(tmp, r[u]);
            if (tmp == -oo) break;
            int l=1,r=depth[u] + 1;
            while(l != r){
                if (r-l<=1){
                    if (table1_left[i-1][r] < tmp) l = r;
                    break;
                }
                int mid = (l+r)/2;
                if (table1_left[i-1][mid] < tmp) l = mid;
                else r = mid;
            }
            if (tmp > table1_left[i-1][l]) ans = max(ans, cnt + l);

            l=1,r=depth[u] + 1;
            while(l != r){
                if (r-l<=1){
                    if (table1_right[i+1][r] < tmp) l = r;
                    break;
                }
                int mid = (l+r)/2;
                if (table1_right[i+1][mid] < tmp) l = mid;
                else r = mid;
            }
            if (tmp > table1_right[i+1][l]) ans = max(ans, cnt + l);
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&r[i]);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs_tmp(1);
    for(int i=1;i<=n;i++)   dp1[i].assign(depth[i]+5,oo), dp2[i].assign(depth[i]+5,-oo);
    dfs(1);
    for(int i=1;i<=n;i++)
        solve(i);
    printf("%d",ans);
}

