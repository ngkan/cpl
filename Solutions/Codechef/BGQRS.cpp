/*
https://www.codechef.com/OCT16/problems/BGQRS
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = (ll) 1e5+5;
ll test,n,m,a[N],ans;
ll seg[6][4*N], lazy[6][4*N], lazy2l[4*N], lazy2r[4*N], lazy2val2[4*N], lazy2val5[4*N];
ll num2[N], num5[N];
void build(int node,int l,int r){
    if (l == r){
        while(a[l]%2 == 0) seg[2][node] ++, a[l]/=2;
        while(a[l]%5 == 0) seg[5][node] ++, a[l]/=5;
        return;
    }
    build(2*node,l,(l+r)/2);
    build(2*node+1,(l+r)/2+1,r);
    seg[2][node] = seg[2][2*node] + seg[2][2*node+1];
    seg[5][node] = seg[5][2*node] + seg[5][2*node+1];
}
void _lazy(int node,int l,int r){
    if (lazy2val2[node] != -1){
        seg[2][node] = (num2[r-lazy2l[node]+1] - num2[l-lazy2l[node]]) + lazy2val2[node] * (r-l+1);
        seg[5][node] = (num5[r-lazy2l[node]+1] - num5[l-lazy2l[node]]) + lazy2val5[node] * (r-l+1);
        seg[2][node] += lazy[2][node] * (r-l+1);
        seg[5][node] += lazy[5][node] * (r-l+1);
        if (l != r){
            lazy2val2[2*node] = lazy2val2[2*node+1] = lazy2val2[node];
            lazy2val5[2*node] = lazy2val5[2*node+1] = lazy2val5[node];
            lazy2l[2*node] = lazy2l[2*node+1] = lazy2l[node];
            lazy2r[2*node] = lazy2r[2*node+1] = lazy2r[node];
            lazy[2][2*node]   = lazy[2][node];
            lazy[2][2*node+1] = lazy[2][node];
            lazy[5][2*node]   = lazy[5][node];
            lazy[5][2*node+1] = lazy[5][node];
        }
        lazy2l[node] = lazy2r[node] = lazy2val2[node] = lazy2val5[node] = -1;
        lazy[2][node] = lazy[5][node] = 0;
    }
    else{
        seg[2][node] += lazy[2][node] * (r-l+1);
        seg[5][node] += lazy[5][node] * (r-l+1);
        if (l != r){
            lazy[2][2*node]   += lazy[2][node];
            lazy[2][2*node+1] += lazy[2][node];
            lazy[5][2*node]   += lazy[5][node];
            lazy[5][2*node+1] += lazy[5][node];
        }
        lazy[2][node] = lazy[5][node] = 0;
    }
}
void upd(int node,int l,int r,int u,int v,ll val2,ll val5){
    _lazy(node,l,r);
    if (r < u || v < l) return;
    if (u <= l && r <= v){
        seg[2][node] += (r-l+1) * val2,
        seg[5][node] += (r-l+1) * val5;
        //cout <<  l << ' ' << r << ' ' << seg[2][node] << ' ' << seg[5][node] << endl;
        if (l != r){
            lazy[2][2*node] += val2,  lazy[2][2*node+1] += val2,
            lazy[5][2*node] += val5,  lazy[5][2*node+1] += val5;
        }
        return;
    }
    upd(2*node  ,l         ,(l+r)/2,u,v,val2,val5);
    upd(2*node+1,(l+r)/2+1,r       ,u,v,val2,val5);
    seg[2][node] = seg[2][2*node] + seg[2][2*node+1];
    seg[5][node] = seg[5][2*node] + seg[5][2*node+1];
}
void upd2(int node,int l,int r,int u,int v,ll val2,ll val5){
    _lazy(node,l,r);
    if (r < u || v < l) return;
    if (u <= l && r <= v){
        seg[2][node] = (num2[r-u+1] - num2[l-u]) + val2 * (r-l+1);
        seg[5][node] = (num5[r-u+1] - num5[l-u]) + val5 * (r-l+1);
        //cout << l << ' ' << r << ' ' << seg[2][node] << ' ' << seg[5][node] << endl;
        if (l != r){
            //_lazy(2*node,l,(l+r)/2);
            //_lazy(2*node+1,(l+r)/2+1,r);
            lazy2val2[2*node] = lazy2val2[2*node+1] = val2;
            lazy2val5[2*node] = lazy2val5[2*node+1] = val5;
            lazy2l[2*node] = lazy2l[2*node+1] = u;
            lazy2r[2*node] = lazy2r[2*node+1] = v;
            lazy[2][2*node] = lazy[2][2*node+1] = 0;
            lazy[5][2*node] = lazy[5][2*node+1] = 0;
        }
        return;
    }
    upd2(2*node,l,(l+r)/2,u,v,val2,val5);
    upd2(2*node+1,(l+r)/2+1,r,u,v,val2,val5);
    seg[2][node] = seg[2][2*node] + seg[2][2*node+1];
    seg[5][node] = seg[5][2*node] + seg[5][2*node+1];
}
int get(int type,int node,int l,int r,int u,int v){
    _lazy(node,l,r);
    if (r < u || v < l) return 0;
    if (u <= l && r <= v)
        return seg[type][node];
    return get(type,2*node,l,(l+r)/2,u,v) + get(type,2*node+1,(l+r)/2+1,r,u,v);
}
int main(){
    //freopen("test.inp","r",stdin);
    //freopen("out2.txt","w",stdout);
    for(int i=1;i<=(int)1e5+1;i++){
        if (i%2==0) num2[i] = num2[i/2] + 1;
        if (i%5==0) num5[i] = num5[i/5] + 1;
    }
    for(int i=1;i<=(int)1e5+1;i++)
        num2[i] += num2[i-1], num5[i] += num5[i-1];
    scanf("%lld",&test);
    while(test--){
        scanf("%lld %lld",&n,&m);
        for(int i=1;i<=n;i++)   scanf("%lld",&a[i]);
        for(int i=1;i<4*N;i++) lazy2l[i] = lazy2r[i] = lazy2val2[i] = lazy2val5[i] = -1, lazy[2][i] = lazy[5][i] = seg[2][i] = seg[5][i] = 0;
        build(1,1,n);   ans = 0;
        while(m--){
            int type,y,l,r;
            scanf("%d",&type);
            if (type == 3){
                scanf("%d %d",&l,&r);
                ans += min(get(2,1,1,n,l,r),get(5,1,1,n,l,r));
                //printf("%d\n",min(get(2,1,1,n,l,r),get(5,1,1,n,l,r)));
            }
            else{
                scanf("%d %d %d",&l,&r,&y);
                int cnt2 = 0, cnt5 = 0;
                while(y%2 == 0) cnt2++, y/=2;
                while(y%5 == 0) cnt5++, y/=5;
                if (type == 1)
                    upd (1,1,n,l,r,cnt2,cnt5);
                else
                    upd2(1,1,n,l,r,cnt2,cnt5);
            }
            //cout << "all " << seg[2][1] << ' ' << seg[5][1] << endl;
        }
        printf("%lld\n",ans);
    }
}
