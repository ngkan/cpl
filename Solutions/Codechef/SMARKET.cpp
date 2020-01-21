#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int,int> ii;
struct query{
   int l,r,k,id;
   query(int l=0,int r=0,int k=0,int id=0): l(l), r(r), k(k), id(id) {}
};
bool cmp(query x, query y){
   return x.k > y.k;
}
vector <ii> block;
int test;
int beg[100005], fin[100005];
int n, q, a[100005];
int fw[100005];
int ans[100005];
vector <query> qq;
void upd(int pos,int val){
   for(;pos<=100000;pos+=pos&-pos) fw[pos] += val;
}
int get(int pos){
   int res = 0;
   for(;pos;pos-=pos&-pos) res += fw[pos]; return res;
}
void reset(){
   memset(fw,0,sizeof(fw));
   block.clear();
   qq.clear();
}
int main(){
   scanf("%d",&test);
   while(test--){
      reset();
      scanf("%d %d",&n,&q);
      for(int i=1;i<=n;i++)
         scanf("%d",&a[i]);
      for(int i=1;i<=n;i++)
         if (a[i] == a[i-1]) beg[i] = beg[i-1];
         else beg[i] = i;
      for(int i=n;i>=1;i--)
         if (a[i] == a[i+1]) fin[i] = fin[i+1];
         else fin[i] = i;

      for(int i=1;i<=n;i++)
         block.push_back(ii(fin[i]-i+1, i)),
         i = fin[i];

      sort(block.begin(),block.end(),greater<ii>());
      for(int i=1;i<=q;i++){
         int l,r,k;
         scanf("%d %d %d",&l,&r,&k);
         qq.push_back(query(l,r,k,i));
      }
      int ctrl = 0;
      sort(qq.begin(),qq.end(),cmp);

      for(int i=0;i<q;i++){
         while(ctrl < block.size() && block[ctrl].fi >= qq[i].k){
            upd(block[ctrl].se, 1);
            ctrl++;
         }
         int l = qq[i].l, r = qq[i].r;
         int res = 0;
         if (fin[l] - l + 1 >= qq[i].k) res++;
         if (r - beg[r] + 1 >= qq[i].k) res++;
         if (fin[l] >= r && res) res--;
         l = fin[l] + 1;
         r = beg[r] - 1;
         if (l <= r)
         res += get(r) - get(l-1);
         ans[qq[i].id] = res;
      }
      for(int i=1;i<=q;i++)
         printf("%d\n",ans[i]);
   }
}
/*
1
8 5
20 10 10 10 7 7 7 10
2 6 2
3 6 2
3 6 3
3 8 3
3 8 1
*/
