#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
const int N = (int) 1e5+5;
int test,n,val[N],lv[N], index_edge[N];
int hld_chain[N], hld_segpos[N], hld_headchain[N], seginx[N], nchain, nsegpos;
vector <int> G[N];
int p[N][21];
void predfs(int u){
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i];
        if (v == p[u][0]) continue;
        lv[v] = lv[u] + 1;
        p[v][0] = u;
        for(int k=1;k<=20;k++)  p[v][k] = p[p[v][k-1]][k-1];
        predfs(v);
    }
}
int lca(int x,int y){
    for(int k=20;k>=0;k--) if (lv[p[x][k]] >= lv[y]) x = p[x][k];
    for(int k=20;k>=0;k--) if (lv[p[y][k]] >= lv[x]) y = p[y][k];
    if (x == y) return x;
    for(int k=20;k>=0;k--) if (p[x][k] != p[y][k]) x = p[x][k], y = p[y][k];
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
        int v = G[u][i];
        if (v == p[u][0]) continue;
        if (G[v].size() > G[vmx].size())
            vmx = v;
    }
    if (vmx)
        hld_build(vmx);

    for(int i=0;i<G[u].size();i++){
        int v = G[u][i];
        if (v == p[u][0] || v == vmx) continue;
        nchain ++;
        hld_build(v);
    }
}
int seg[8*N][2], lazy[8*N]; // 1 = max, 0 = min
void seg_change(int id,int l,int r,int pos,int val){
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

int seg_get(int id,int l,int r,int u,int v){
    if (r < u || v < l) return (int) -1e9-5;
    if (u <= l && r <= v)
        return max(seg[id][1],seg[id][0]);
    return max(seg_get(2*id,l,(l+r)/2,u,v),seg_get(2*id+1,(l+r)/2+1,r,u,v));
}
int seg_query(int x,int y){
    int LCA = lca(x,y), res = seg_get(1,1,n,hld_segpos[LCA],hld_segpos[LCA]);
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

int main(){
    iostream::sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<n;i++){
        int u,v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    predfs(1);
    hld_build(1);
    string s;
    int x,y,q;
    cin >> q;
    while(q-- && cin >> s){
        if (s == "G"){
            cin >> x >> y;
            printf("%d\n",seg_query(x,y));
        }
        else{
            cin >> x >> y;
            seg_change(1,1,n,hld_segpos[x],seg_get(1,1,n,hld_segpos[x],hld_segpos[x]) + y);
        }
    }
}
