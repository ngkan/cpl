#include <bits/stdc++.h>
using namespace std;
int n,a[100005];
int seg[100005*4], lazy[100005*4];
void _lazy(int id,int l,int r){
   seg[id] += lazy[id];
   if (l != r)
      lazy[2*id] += lazy[id],
      lazy[2*id+1] += lazy[id];
   lazy[id] = 0;
}
void upd(int id,int l,int r,int u,int v,int val){
   _lazy(id,l,r);
   if (r < u || v < l) return;
   if (u <= l && r <= v){
      lazy[id] += val;
      _lazy(id,l,r);
      return;
   }
   upd(2*id,l,(l+r)/2,u,v,val);
   upd(2*id+1,(l+r)/2+1,r,u,v,val);
   seg[id] = max(seg[2*id], seg[2*id+1]);
}
int ffind(int id,int l,int r){
   _lazy(id,l,r);
   if (l != r) _lazy(2*id,l,(l+r)/2), _lazy(2*id+1,(l+r)/2+1,r);
   if (l == r) return l;
   if (seg[2*id+1] < 1) return ffind(2*id,l,(l+r)/2);
   return ffind(2*id+1,(l+r)/2+1,r);
}
int main(){
   scanf("%d",&n);
   for(int i=1;i<=n;i++){
      int pos, type, x;
      scanf("%d %d",&pos,&type);
      if (type == 0){
         upd(1,1,n,1,pos,-1);
      }
      else{
         scanf("%d",&x);
         a[pos] = x;
         upd(1,1,n,1,pos,1);
      }
      if (seg[1] < 1) printf("-1\n");
      else printf("%d\n", a[ffind(1,1,n)]);
   }
}
