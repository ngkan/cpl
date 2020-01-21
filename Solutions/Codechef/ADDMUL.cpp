#include <stdio.h>
#include <iostream>
#define ll long long
using namespace std;
const int N = 100005;
const ll mod = (ll) 1e9 + 7;
ll n,q,a[N];
ll seg[4*N],lazy1[4*N],lazy2[4*N],lazy3[4*N];
void build(int id,int l,int r){
    lazy1[id] = 0;
    lazy2[id] = 1;
    lazy3[id] = -1;
    if (l == r){
        seg[id] = a[l];
        return;
    }
    build(2*id,l,(l+r)/2);
    build(2*id+1,(l+r)/2+1,r);
    seg[id] = (seg[2*id] + seg[2*id+1]) % mod;
}
void _lazy(int id,int l,int r){
    if (lazy3[id] != -1){
        seg[id] = (r-l+1) * lazy3[id] % mod;
        seg[id] = (seg[id] * lazy2[id]) % mod;
        seg[id] = (seg[id] + lazy1[id] * (r-l+1)) % mod;
        if (l != r){
            lazy1[2*id] = lazy1[2*id+1] = lazy1[id],
            lazy2[2*id] = lazy2[2*id+1] = lazy2[id],
            lazy3[2*id] = lazy3[2*id+1] = lazy3[id];
        }
        lazy1[id] = 0;
        lazy2[id] = 1;
        lazy3[id] = -1;
    }
    else{
        seg[id] = (seg[id] * lazy2[id]) % mod;
        seg[id] = (seg[id] + lazy1[id] * (r-l+1)) % mod;
        if (l != r)
            lazy1[2*id]   = (lazy1[2*id] * lazy2[id]) % mod,
            lazy2[2*id]   = (lazy2[2*id] * lazy2[id]) % mod,
            lazy1[2*id+1] = (lazy1[2*id+1] * lazy2[id]) % mod,
            lazy2[2*id+1] = (lazy2[2*id+1] * lazy2[id]) % mod,
            lazy1[2*id]   = (lazy1[2*id] + lazy1[id]) % mod,
            lazy1[2*id+1] = (lazy1[2*id+1] + lazy1[id]) % mod;
        lazy1[id] = 0;
        lazy2[id] = 1;
    }
}
void upd(int type,int id,int l,int r,int u,int v,ll val){
    _lazy(id,l,r);
    if (r < u || v < l) return;
    if (u <= l && r <= v){
        if (type == 1){
            seg[id] = (seg[id] + (r-l+1) * val) % mod;
            if (l != r)
                lazy1[2*id]   = (lazy1[2*id] + val) % mod,
                lazy1[2*id+1] = (lazy1[2*id+1] + val) % mod;
            return;
        }
        else if (type == 2){
            seg[id] = (seg[id] * val) % mod;
            if (l != r)
                lazy1[2*id]   = (lazy1[2*id] * val) % mod,
                lazy2[2*id]   = (lazy2[2*id] * val) % mod,
                lazy1[2*id+1] = (lazy1[2*id+1] * val) % mod,
                lazy2[2*id+1] = (lazy2[2*id+1] * val) % mod;
            return;
        }
        else{
            seg[id] = (r-l+1) * val % mod;
            if (l != r)
                lazy1[2*id] = lazy1[2*id+1] = 0,
                lazy2[2*id] = lazy2[2*id+1] = 1,
                lazy3[2*id] = lazy3[2*id+1] = val;
            return;
        }
    }
    upd(type,2*id,l,(l+r)/2,u,v,val);
    upd(type,2*id+1,(l+r)/2+1,r,u,v,val);
    seg[id] = (seg[2*id] + seg[2*id+1]) % mod;
}
ll get(int id,int l,int r,int u,int v){
    _lazy(id,l,r);
    if (r < u || v < l) return 0;
    if (u <= l && r <= v) return seg[id];
    return (get(2*id,l,(l+r)/2,u,v) + get(2*id+1,(l+r)/2+1,r,u,v))%mod;
}
int main(){
    freopen("test.inp","r",stdin);
    freopen("ans.out","w",stdout);
    scanf("%lld %lld",&n,&q);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    build(1,1,n);
    while(q--){
        ll type,x,y,v;
        scanf("%lld",&type);
        if (type == 4){
            scanf("%lld %lld",&x,&y),
            printf("%lld\n",get(1,1,n,x,y));
        }
        else
            scanf("%lld %lld %lld",&x,&y,&v),
            upd(type,1,1,n,x,y,v);
    }
}
