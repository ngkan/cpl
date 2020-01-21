#include <bits/stdc++.h>
#define ll long long
#define x1 qdwesdfs
#define x2 sdfgknjfd
#define y1 svdfgknj
#define y2 fgsdljnfdgs
using namespace std;
string s;
ll n,m,k;
ll r[1005][1005],root[26][1005][1005];
ll x[3][300005],y[3][300005],e[300005];
ll other[26][1005][1005];
ll val[300005],sumval,ans=(ll)1e18;
ll res[300005];
ll sroot(ll type,ll x1,ll y1,ll x2,ll y2){
    return root[type][x2][y2] - root[type][x1-1][y2] - root[type][x2][y1-1] + root[type][x1-1][y1-1];
}
ll sother(ll type,ll x1,ll y1,ll x2,ll y2){
    return other[type][x2][y2] - other[type][x1-1][y2] - other[type][x2][y1-1] + other[type][x1-1][y1-1];
}
ll sdis(ll type,ll x1,ll y1,ll x2,ll y2){
    #define dis root
    return dis[type][x2][y2] - dis[type][x1-1][y2] - dis[type][x2][y1-1] + dis[type][x1-1][y1-1];
    #undef dis
}
ll scnt(ll type,ll x1,ll y1,ll x2,ll y2){
    #define cnt root
    return cnt[type][x2][y2] - cnt[type][x1-1][y2] - cnt[type][x2][y1-1] + cnt[type][x1-1][y1-1];
    #undef cnt
}
void oops(void){
    for(int type=0;type<26;type++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                other[type][i][j] += other[type][i-1][j] + other[type][i][j-1] - other[type][i-1][j-1];
}
int main(){
    iostream::sync_with_stdio(0);
    cin >> n >> m >> k;
    for(int i=0;i<n;i++){
        cin >> s;
        for(int j=0;j<m;j++)
            root[s[j]-'a'][i+1][j+1]++,
            r[i+1][j+1] = s[j] - 'a';
    }
    // build sroot
    for(int type=0;type<26;type++){
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                root[type][i][j] += root[type][i-1][j] + root[type][i][j-1] - root[type][i-1][j-1];
    }
    for(int i=1;i<=k;i++){
        char c;
        cin >> x[1][i] >> y[1][i] >> x[2][i] >> y[2][i] >> c;
        e[i] = c - 'a';
        other[e[i]][x[1][i]][y[1][i]]    ++;
        other[e[i]][x[1][i]][y[2][i]+1]  --;
        other[e[i]][x[2][i]+1][y[1][i]]  --;
        other[e[i]][x[2][i]+1][y[2][i]+1]++;
    }
    // build val
    for(int i=1;i<=k;i++){
        for(int type=0;type<26;type++)
            val[i] += sroot(type,x[1][i],y[1][i],x[2][i],y[2][i]) * abs(type - e[i]);
        sumval += val[i];
    }
    // root useless
    memset (root,0,sizeof(root));
    #define cnt root
    oops();
    // build scnt
    for(int type=0;type<26;type++){
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cnt[r[i][j]][i][j] += other[type][i][j];
    }
    for(int type=0;type<26;type++){
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cnt[type][i][j] += cnt[type][i-1][j] + cnt[type][i][j-1] - cnt[type][i-1][j-1];
    }
    for(int i=1;i<=k;i++)
        for(int type=0;type<26;type++)
            res[i] -= abs(type - e[i]) * scnt(type,x[1][i],y[1][i],x[2][i],y[2][i]);
    // cnt useless
    #undef cnt
    memset(root,0,sizeof(root));
    #define dis root
    // build dis
    for(int type=0;type<26;type++){
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                dis[type][i][j] = abs(type - r[i][j]) * other[type][i][j];
    }
    for(int type=0;type<26;type++){
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                dis[type][i][j] += dis[type][i-1][j] + dis[type][i][j-1] - dis[type][i-1][j-1];
    }
    for(int i=1;i<=k;i++)
        for(int type=0;type<26;type++)
            res[i] -= sdis(type,x[1][i],y[1][i],x[2][i],y[2][i]);
    // dis useless
    #undef dis
    oops();

    for(int i=1;i<=k;i++){
        res[i] += k * val[i] + sumval;
        for(int type=0;type<26;type++)
            res[i] += abs(type - e[i]) * sother(type,x[1][i],y[1][i],x[2][i],y[2][i]);
        ans = min(ans,res[i]);
    }
    cout << ans;
}
