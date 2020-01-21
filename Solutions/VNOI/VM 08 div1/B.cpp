#include <bits/stdc++.h>
using namespace std;
int n,q;
vector <int> G[100005];
int p[100005];
int hld_id[100005], hld_pos[100005], hld_head[100005], hld_segpos[100005], segindex[100005], hld_cnt, segposcnt, revindex[100005];
void build_hld(int u){
   int maxkid = 0;
   for(int i=0;i<G[u].size();i++){
      if (G[u][i] == p[u]) continue;
      if (G[G[u][i]].size() > G[maxkid].size()) maxkid = G[u][i];
   }

   if (!maxkid) return;
   hld_id[maxkid] = hld_id[u];
   hld_segpos[maxkid] = ++segposcnt;
   revindex[segposcnt] = maxkid;
   hld_head[maxkid] = hld_head[u];
   p[maxkid] = u;
   build_hld(maxkid);

   for(int i=0;i<G[u].size();i++){
      int v = G[u][i];
      if (v == p[u] || v == maxkid) continue;
      hld_id[v] = ++hld_cnt;
      hld_segpos[v] = ++segposcnt;
      hld_head[v] = v;
      revindex[segposcnt] = v;
      p[v] = u;
      build_hld(v);
   }
}
int seg[400005];
void upd(int id,int l,int r,int pos,int val){
   if (r < pos || pos < l) return;
   if (l == r){
      seg[id] += val;
      return;
   }
   upd(2*id,l,(l+r)/2,pos,val);
   upd(2*id+1,(l+r)/2+1,r,pos,val);
   seg[id] = seg[2*id] + seg[2*id+1];
}
int get(int id,int l,int r,int u,int v){
   if (r < u || v < l) return 0;
   if (u <= l && r <= v) return seg[id];
   return get(2*id,l,(l+r)/2,u,v) + get(2*id+1,(l+r)/2+1,r,u,v);
}
int find(int id,int l,int r,int u,int v){
   if (r < u || v < l) return -1;
   if (u <= l && r <= v){
      if (seg[id] == 0) return -1;
      if (l == r) return l;
      if (seg[2*id]) return find(2*id,l,(l+r)/2,u,v);
      return find(2*id+1,(l+r)/2+1,r,u,v);
   }
   int x = find(2*id,l,(l+r)/2,u,v);
   if (x > -1) return x;
   return find(2*id+1,(l+r)/2+1,r,u,v);
}
int query(int x){
   int res = -1;
   while(x){
      int pp = hld_head[x];
      int mjk = find(1,1,n,hld_segpos[pp],hld_segpos[x]);
      if (mjk > -1) res = mjk;
      x = p[pp];
   }
   if (res == -1) return -1;
   return revindex[res];
}
int main(){
   scanf("%d %d",&n,&q);
   for(int i=1;i<n;i++){
      int x,y;
      scanf("%d %d",&x,&y);
      G[x].push_back(y);
      G[y].push_back(x);
   }
   hld_cnt = 1;
   segposcnt = 1;
   hld_id[1] = 1;
   hld_segpos[1] = 1;
   revindex[1] = 1;
   hld_head[1] = 1;
   build_hld(1);
   while(q--){
      int type, x;
      scanf("%d %d",&type,&x);
      if (type == 0)
         upd(1,1,n,hld_segpos[x], (get(1,1,n,hld_segpos[x],hld_segpos[x]) ? -1 : 1));
      else
         printf("%d\n",query(x));
   }
}
