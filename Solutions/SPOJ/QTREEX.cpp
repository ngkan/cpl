#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
const int N = (int) 1e4+5;
struct edge{
    int v,w,id;
    edge(int v=0,int w=0,int id=0): v(v), w(w), id(id) {}
};
int test,n,val[N],lv[N], index_edge[N];
int hld_chain[N], hld_segpos[N], hld_headchain[N], seginx[N], nchain, nsegpos;
vector <edge> G[N];
int p[N][15];
void predfs(int u){
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i].v, w = G[u][i].w, id = G[u][i].id;
        if (v == p[u][0]) continue;
        val[v] = w;
        lv[v] = lv[u] + 1;
        p[v][0] = u;
        index_edge[id] = v;
        for(int k=1;k<=14;k++)  p[v][k] = p[p[v][k-1]][k-1];
        predfs(v);
    }
}
int lca(int x,int y){
    for(int k=14;k>=0;k--) if (lv[p[x][k]] >= lv[y]) x = p[x][k];
    for(int k=14;k>=0;k--) if (lv[p[y][k]] >= lv[x]) y = p[y][k];
    if (x == y) return x;
    for(int k=14;k>=0;k--) if (p[x][k] != p[y][k]) x = p[x][k], y = p[y][k];
    return p[x][0];
}
void hld_build(int u){
    if (!hld_headchain[nchain])
        hld_headchain[nchain] = u;
    hld_chain[u] = nchain;
    hld_segpos[u] = ++nsegpos;
    seginx[nsegpos] = u;
    int vmx = 0;
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i].v;
        if (v == p[u][0]) continue;
        if (G[v].size() > G[vmx].size())
            vmx = v;
    }
    if (vmx)
        hld_build(vmx);

    for(int i=0;i<G[u].size();i++){
        int v = G[u][i].v;
        if (v == p[u][0] || v == vmx) continue;
        nchain ++;
        hld_build(v);
    }
}
int seg[8*N][2], lazy[8*N]; // 1 = max, 0 = min
void seg_build(int id,int l,int r){
    if (l == r){
        seg[id][1] = seg[id][0] = val[seginx[l]];
        return;
    }
    seg_build(2*id,l,(l+r)/2);
    seg_build(2*id+1,(l+r)/2+1,r);
    seg[id][1] = max(seg[2*id][1],seg[2*id+1][1]);
    seg[id][0] = min(seg[2*id][0],seg[2*id+1][0]);
}
void _lazy(int id,int l,int r){
    lazy[id] %= 2;
    if (!lazy[id]) return;
    int val1 = seg[id][1];
    int val0 = seg[id][0];
    seg[id][1] = - val0;
    seg[id][0] = - val1;
    if (l != r)
        lazy[2*id] += lazy[id],
        lazy[2*id + 1] += lazy[id];
    lazy[id] = 0;
}
void seg_change(int id,int l,int r,int pos,int val){
    _lazy(id,l,r);
    if (r < pos || pos < l) return;
    if (l == r){
        seg[id][1] = seg[id][0] = val;
        return;
    }
    seg_change(2*id,l,(l+r)/2,pos,val);
    seg_change(2*id+1,(l+r)/2+1,r,pos,val);
    seg[id][1] = max(seg[2*id][1],seg[2*id+1][1]);
    seg[id][0] = min(seg[2*id][0],seg[2*id+1][0]);
}
void seg_upd_negate(int id,int l,int r,int u,int v){
    _lazy(id,l,r);
    if (r < u || v < l) return;
    if (u <= l && r <= v){
        int val1 = seg[id][1];
        int val0 = seg[id][0];
        seg[id][1] = - val0;
        seg[id][0] = - val1;
        if (l != r)
            lazy[2*id] ++,
            lazy[2*id + 1] ++;
        return;
    }
    seg_upd_negate(2*id,l,(l+r)/2,u,v);
    seg_upd_negate(2*id+1,(l+r)/2+1,r,u,v);
    seg[id][1] = max(seg[2*id][1],seg[2*id+1][1]);
    seg[id][0] = min(seg[2*id][0],seg[2*id+1][0]);
}
void seg_negate(int x,int y){
    int LCA = lca(x,y);
    while(1){
        if (hld_chain[x] != hld_chain[LCA]){
            seg_upd_negate(1,1,n,hld_segpos[hld_headchain[hld_chain[x]]],hld_segpos[x]);
            x = p[hld_headchain[hld_chain[x]]][0];
        }
        else{
            if (LCA != x)
                seg_upd_negate(1,1,n,hld_segpos[LCA]+1,hld_segpos[x]);
            break;
        }
    }
    while(1){
        if (hld_chain[y] != hld_chain[LCA]){
            seg_upd_negate(1,1,n,hld_segpos[hld_headchain[hld_chain[y]]],hld_segpos[y]);
            y = p[hld_headchain[hld_chain[y]]][0];
        }
        else{
            if (LCA != y)
                seg_upd_negate(1,1,n,hld_segpos[LCA]+1,hld_segpos[y]);
            break;
        }
    }
}
int seg_get(int id,int l,int r,int u,int v){
    _lazy(id,l,r);
    if (r < u || v < l) return (int) -1e9-5;
    if (u <= l && r <= v)
        return max(seg[id][1],seg[id][0]);
    return max(seg_get(2*id,l,(l+r)/2,u,v),seg_get(2*id+1,(l+r)/2+1,r,u,v));
}
int seg_query(int x,int y){
    int LCA = lca(x,y), res = (int) -1e9 - 5;
    while(1){
        if (hld_chain[x] != hld_chain[LCA]){
            res = max(res, seg_get(1,1,n,hld_segpos[hld_headchain[hld_chain[x]]],hld_segpos[x]));
            x = p[hld_headchain[hld_chain[x]]][0];
        }
        else{
            if (LCA != x)
                res = max(res, seg_get(1,1,n,hld_segpos[LCA]+1,hld_segpos[x]));
            break;
        }
    }
    while(1){
        if (hld_chain[y] != hld_chain[LCA]){
            res = max(res, seg_get(1,1,n,hld_segpos[hld_headchain[hld_chain[y]]],hld_segpos[y]));
            y = p[hld_headchain[hld_chain[y]]][0];
        }
        else{
            if (LCA != y)
                res = max(res, seg_get(1,1,n,hld_segpos[LCA]+1,hld_segpos[y]));
            break;
        }
    }
    return res;
}
void reset(int NN){
    for(int i=1;i<=8*NN;i++)
        seg[i][0] = seg[i][1] = lazy[i] = 0;
    for(int i=1;i<=NN;i++)
        G[i].clear(),
        val[i] = 0,
        lv[i] = 0,
        index_edge[i] = 0,
        hld_chain[i] = 0,
        hld_headchain[i] = 0,
        hld_segpos[i]= 0,
        seginx[i] = 0;
    for(int i=1;i<=NN;i++) for(int j=0;j<=14;j++) p[i][j] = 0;
    lv[1] = 1;
    nchain = 1;
    nsegpos = 0;
}
int main(){
    freopen("test.inp","r",stdin);
    freopen("ans.out","w",stdout);
    iostream::sync_with_stdio(0);
    cin >> test;
    while(test--){
        reset(10000);
        cin >> n;
        for(int i=1;i<n;i++){
            int u,v,w;
            cin >> u >> v >> w;
            G[u].push_back(edge(v,w,i));
            G[v].push_back(edge(u,w,i));
        }
        predfs(1);
        hld_build(1);
        seg_build(1,1,n);
        string s;
        int x,y;
        //cout << index_edge[9] << endl;
        while(cin >> s){
            if (s == "DONE") break;
            else if (s == "QUERY"){
                cin >> x >> y;
                if (x != y) printf("%d\n",seg_query(x,y));
                else printf("0\n");
            }
            else if (s == "CHANGE"){
                cin >> x >> y;
                x = index_edge[x];
                seg_change(1,1,n,hld_segpos[x],y);
            }
            else if (s == "NEGATE"){
                cin >> x >> y;
                seg_negate(x,y);
            }
            else ;
            //for(int i=1;i<=n;i++) printf("%d ",seg_get(1,1,n,hld_segpos[i],hld_segpos[i])); printf("\n");
        }
    }
}
