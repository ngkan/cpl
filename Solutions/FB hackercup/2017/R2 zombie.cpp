#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = (ll) 1e9+7;
ll ans,test,n,m,aw,bw,ad,bd,as,bs,w[1000005],d[1000005],z[1000005],s[1000005];
ll seg[8000005][6];
// 0  1 <- 2 -> 3 all
void init_seg(ll id,ll l,ll r){
    if (l == r){
        seg[id][0] = 1;
        return;
    }
    init_seg(2*id,l,(l+r)/2);
    init_seg(2*id+1,(l+r)/2+1,r);
    seg[id][0] = seg[2*id][0] * seg[2*id+1][0];
}
void upd_seg(ll id,ll l,ll r,ll pos,ll type,ll val){
    if (r < pos || pos < l) return;
    if (l == r){
        if (type == -1)
            seg[id][1] = (seg[id][1] + val) % mod;
        else if (type == 0)
            seg[id][0] = (seg[id][0] + val) % mod;
        else
            seg[id][2] = (seg[id][2] + val) % mod;
        return;
    }
    upd_seg(2*id,l,(l+r)/2,pos,type,val);
    upd_seg(2*id+1,(l+r)/2+1,r,pos,type,val);
    seg[id][0] = (seg[2*id][0] * seg[2*id+1][0] % mod + seg[2*id][2] * seg[2*id+1][1] % mod) % mod;
    seg[id][1] = (seg[2*id][1] * seg[2*id+1][0] % mod + seg[2*id][3] * seg[2*id+1][1] % mod) % mod;
    seg[id][2] = (seg[2*id][0] * seg[2*id+1][2] % mod + seg[2*id][2] * seg[2*id+1][3] % mod) % mod;
    seg[id][3] = (seg[2*id][3] * seg[2*id+1][3] % mod + seg[2*id][1] * seg[2*id+1][2] % mod) % mod;
}
int main(){
    //freopen("fighting_all_the_zombies.txt","r",stdin);
    //freopen("out3.txt","w",stdout);
    test=1;
    for(int did=1;did<=test;did++){
        memset(seg,0,sizeof(seg));
        ans = 0;
        cin >> n >> m;
        cin >> w[1] >> aw >> bw;
        cin >> d[1] >> ad >> bd;
        cin >> s[1] >> as >> bs;
        for(int i=2;i<=m;i++)
            w[i] = (aw * w[i-1] + bw) % n + 1,
            d[i] = (ad * d[i-1] + bd) % 3,
            s[i] = (as * s[i-1] + bs) % 1000000000 + 1;
        for(int i=1;i<=m;i++)
            z[i] = max(1ll,min(n,w[i] + d[i] - 1));
        init_seg(1,1,n);
        for(int i=1;i<=m;i++){
            upd_seg(1,1,n,w[i],-(w[i]-z[i]),s[i]);
            ans = (ans + seg[1][0]) % mod;
        }
        cout << ans << endl;
    }
}
