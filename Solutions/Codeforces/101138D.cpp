#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct query{
   int type,id, l, r;
   query(int type=0,int id=0,int l=0,int r=0): type(type), id(id), l(l), r(r) {}
};
bool cmp(query x,query y){
   if (x.l/220 != y.l/220) return x.l/220 < y.l/220;
   if (x.r/220 != y.r/220) return x.r/220 < y.r/220;
   if (x.type < y.type) return x.type < y.type;
   return x.id < y.id;
}
int n,q,a[50005],ctrl,ctrr;
vector <query> ez;
ll cnt[50005];
ll sum,sum2,res[50005];
void add(int pos){
   sum += cnt[a[pos]];
   sum2 -= cnt[a[pos]] * cnt[a[pos]];
   ++cnt[a[pos]];
   sum2 += cnt[a[pos]] * cnt[a[pos]];
}
void minu(int pos){
   sum -= cnt[a[pos]]-1;
   sum2 -= cnt[a[pos]] * cnt[a[pos]];
   --cnt[a[pos]];
   sum2 += cnt[a[pos]] * cnt[a[pos]];
}
void addtype1(int id, int l1,int r1,int l2,int r2){
   // ko giao nhau aka r1 < l2
   ez.push_back(query(1,4*id, l1, r2));
   if (l1 <= l2-1)
   ez.push_back(query(1,4*id+1, l1, l2-1));
   if (r1+1 <= r2)
   ez.push_back(query(1,4*id+2, r1+1, r2));
   if (r1+1 <= l2-1)
   ez.push_back(query(1,4*id+3, r1+1, l2-1));
}
void addtype2(int id, int l1,int r1){
   ez.push_back(query(2,4*id,l1,r1));
}
signed main(){
   scanf("%d",&n);
   for(int i=1;i<=n;i++) scanf("%d",&a[i]);
   scanf("%d",&q);
   bool ax = 0;
   for(int i=1;i<=q;i++){
      int l1,r1,l2,r2;
      scanf("%d %d %d %d",&l1,&r1,&l2,&r2);
      if ((l1 > l2) || (l1 == l2 && r1 < r2))
         swap(l1,l2),
         swap(r1,r2);
      if (r1 < l2){
         // roi nhau
         addtype1(i,l1,r1,l2,r2);
      }
      else if (r2 <= r1){
         // l1 <= l2 <= r2 <= r1
         addtype2(i,l2,r2);
         if (l1 <= l2-1);
         addtype1(i,l1,l2-1,l2,r2);
         if (r2+1 <= r1)
         addtype1(i,l2,r2,r2+1,r1);
      }
      else{
         // l1 <= l2 <= r1 <= r2
         if (l1 <= l2-1)
         addtype1(i,l1,l2-1,l2,r2);
         if (r1+1 <= r2)
         addtype1(i,l2,r1,r1+1,r2);
         addtype2(i,l2,r1);
      }

   }
   sort(ez.begin(),ez.end(),cmp);
   cnt[0] = 1;
   sum2 = 1;
   for(int i=0;i<ez.size();i++){
      int L = ez[i].l, R = ez[i].r, ID = ez[i].id;
      while(ctrr < R)   ++ctrr, add(ctrr);
      while(ctrl < L)   minu(ctrl), ++ctrl;
      while(L < ctrl)   --ctrl, add(ctrl);
      while(R < ctrr)   minu(ctrr), --ctrr;
      if (ez[i].type == 1){
         if (ID%4==0 || ID%4 == 3)  res[ID/4] += sum;
         else res[ID/4] -= sum;
      }
      else{
         if (ID%4==0 || ID%4 == 3)  res[ID/4] += sum2;
         else res[ID/4] -= sum2;
      }
   }
   for(int i=1;i<=q;i++)
      printf("%lld\n",res[i]);
}
/*
7
1 5 2 1 7 2 2
1
2 6 4 7

*/
