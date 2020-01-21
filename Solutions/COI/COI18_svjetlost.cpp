#include <bits/stdc++.h>
using namespace std;
int dsup[100005];
int dsu_p(int x){
    return dsup[x] == x ? x : dsup[x] = dsu_p(dsup[x]);
}
void dsu_union(int x,int y){
    x = dsu_p(x);
    y = dsu_p(y);
    dsup[y] = x;
}
struct point{
    int x, y;
    point(int x=0,int y=0): x(x), y(y) {}
    point operator - (const point& v){
        return {x - v.x, y - v.y};
    }
};
double dist(point a,point b){
    return sqrt(1.0 * (a.x - b.x) * (a.x - b.x) + 1.0 * (a.y - b.y) * (a.y - b.y));
}
int ccw(point a,point b){
    long long val = 1ll * a.x * b.y - 1ll * a.y * b.x;
    if (val > 0)
        return 1;
    if (val == 0)
        return 0;
    return -1;
}
struct segTreeMAX{
    double node[400005];
    double lazy[400005];
    void doLazy(int id,int l,int r){
        node[id] += lazy[id];
        if (l != r){
            lazy[2*id] += lazy[id];
            lazy[2*id+1] += lazy[id];
        }
        lazy[id] = 0;
    }
    void upd(int id,int l,int r,int u,int v,double val){
        doLazy(id, l, r);
        if (r < u || v < l)
            return;
        if (u <= l && r <= v){
            lazy[id] += val;
            doLazy(id,l,r);
            return;
        }
        upd(2*id, l, (l+r)/2, u, v, val);
        upd(2*id+1, (l+r)/2+1, r, u, v ,val);
        node[id] = max(node[2*id], node[2*id+1]);
    }
    double get(int id,int l,int r,int u,int v){
        doLazy(id,l,r);
        if (r < u || v < l)
            return -1;
        if (u <= l && r <= v)
            return node[id];
        return max(get(2*id, l, (l+r)/2, u, v), get(2*id+1, (l+r)/2+1, r, u, v));
    }
    void updQuery(int l,int r,int n,double val){
        if (l <= r)
            upd(1, 1, n, l, r, val);
        else
            upd(1, 1, n, 1, r, val),
            upd(1, 1, n, l, n, val);
    }
}   seg;
struct segTreeSum{
    double node[400005];
    void upd(int id,int l,int r,int pos,double val){
        if (r < pos || pos < l)
            return;
        if (l == r){
            node[id] += val;
            return;
        }
        upd(2*id, l, (l+r)/2, pos, val);
        upd(2*id+1, (l+r)/2+1, r, pos ,val);
        node[id] = node[2*id] + node[2*id+1];
    }
    double get(int id,int l,int r,int u,int v){
        if (r < u || v < l)
            return 0;
        if (u <= l && r <= v)
            return node[id];
        return get(2*id, l, (l+r)/2, u, v) + get(2*id+1, (l+r)/2+1, r, u, v);
    }
    double getQuery(int l,int r,int n){
        if (l <= r)
            return get(1, 1, n, l, r);
        else
            return get(1, 1, n, 1, r) + get(1, 1, n, l, n);
    }
}   segConsecutive;
int n, q;
int prv[100005], nxt[100005], antipodal[100005], antipodalMAX[100005];
point a[100005];
void re(int x){
    // check
    int l = (nxt[x] - x + n) % n, r=n;
    while(l+1<r){
        int mid = (l+r)/2;
        int val = (x+mid+n-1) % n + 1;
        val = dsu_p(val);
        if (ccw(a[nxt[x]] - a[x], a[nxt[val]] - a[val]) > 0)
            l = mid;
        else
            r = mid;
    }
    antipodal[x]  = nxt[dsu_p((x+l+n-1)%n+1)];
    
    r = n;
    while(l+1<r){
        int mid = (l+r)/2;
        int val = (x+mid+n-1) % n + 1;
        val = dsu_p(val);
        if (ccw(a[nxt[x]] - a[x], a[nxt[val]] - a[val]) >= 0)
            l = mid;
        else
            r = mid;
    }
    antipodalMAX[x] = nxt[dsu_p((x+l+n-1)%n+1)];
}
int main(){
    for(int i=1;i<=100000;i++)
        dsup[i] = i;
    iostream::sync_with_stdio(0);
    cout << fixed << setprecision(9);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i].x >> a[i].y;
        prv[i] = i-1;
        nxt[i] = i+1;
    }   prv[1] = n; nxt[n] = 1;
    
    double curval = dist(a[1], a[2]);
    
    a[0] = a[1];    // temp
    antipodal[0] = 2;// temp
    antipodalMAX[0]=2;//temp
    
    for(int i=1;i<=n;i++){
        curval -= dist(a[i-1], a[i]);
        antipodal[i] = antipodal[i-1];
        antipodalMAX[i] = antipodalMAX[i-1];
    
        while(ccw(a[nxt[i]] - a[i], a[nxt[antipodal[i]]] - a[antipodal[i]]) > 0)
            curval += dist(a[antipodal[i]], a[nxt[antipodal[i]]]),
            antipodal[i] = nxt[antipodal[i]];
        while(ccw(a[nxt[i]] - a[i], a[nxt[antipodalMAX[i]]] - a[antipodalMAX[i]]) >= 0)
            antipodalMAX[i] = nxt[antipodalMAX[i]];
    
        seg.upd(1,1,n,i,i,curval);
        segConsecutive.upd(1,1,n,i, dist(a[i], a[nxt[i]]));
    }
    for(int i=1;i<=n;i++)   re(i);
    cout << seg.get(1,1,n,1,n) << '\n';
    
    cin >> q;
    while(q--){
        int pos;
        cin >> pos;
    
        re(pos);
        re(prv[pos]);
    
        // upd
        seg.updQuery(antipodalMAX[pos], prv[pos], n, -dist(a[nxt[pos]], a[pos]));
        seg.updQuery(antipodalMAX[prv[pos]], prv[pos], n, - dist(a[pos], a[prv[pos]]));
    
        segConsecutive.upd(1,1,n,prv[pos], -dist(a[prv[pos]], a[pos]));
        segConsecutive.upd(1,1,n,pos,  - dist(a[pos], a[nxt[pos]]));
    
        // erase
        seg.upd(1, 1, n, pos, pos, -1e18);
        nxt[prv[pos]] = nxt[pos];
        prv[nxt[pos]] = prv[pos];
        dsu_union(prv[pos], pos);
    
        // fix pos val
        pos = prv[pos];
        re(pos);
        segConsecutive.upd(1,1,n,pos, dist(a[pos], a[nxt[pos]]));
        seg.updQuery(antipodalMAX[pos], pos, n, dist(a[pos], a[nxt[pos]]));
    
        double curval = segConsecutive.getQuery(pos,prv[antipodal[pos]],n);
        seg.upd(1,1,n,pos,pos, curval - seg.get(1,1,n,pos,pos));
    
        cout << seg.get(1,1,n,1,n) << '\n';
    }
}