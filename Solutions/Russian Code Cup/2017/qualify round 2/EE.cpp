#include <bits/stdc++.h>
using namespace std;
const int C = 400;
struct query{
   int l, r;
   query(int l=0,int r=0): l(l), r(r) {}
};
bool cmp(query x,query y){
   if (x.l/C == y.l/C) return x.r/C < y.r/C;
   return x.l/C < y.l/C;
}
int test,n,q,a[100005];
int res[250005], cnt[800];
deque <int> dq[250005];
vector <query> lst;
void add(int pos){
   if (pos == -1){
      #define val 100000
      if (dq[val].size())
         cnt[(dq[val].back() - dq[val].front())/C] --,
         res[(dq[val].back() - dq[val].front())] --;

      if (dq[val].size() && dq[val].back() < pos)
         dq[val].push_back(pos);
      else
         dq[val].push_front(pos);
      if (dq[val].size()){
         cnt[(dq[val].back() - dq[val].front())/C] ++;
         res[(dq[val].back() - dq[val].front())] ++;
      }
      #undef val
      return;
   }
   #define val a[pos] + 100000
   if (dq[val].size())
      cnt[(dq[val].back() - dq[val].front())/C] --,
      res[(dq[val].back() - dq[val].front())] --;

   if (dq[val].size() && dq[val].back() < pos)
      dq[val].push_back(pos);
   else
      dq[val].push_front(pos);
   if (dq[val].size()){
      cnt[(dq[val].back() - dq[val].front())/C] ++;
      res[(dq[val].back() - dq[val].front())] ++;
   }
   #undef val
}
void dec(int pos){
   if (pos == -1){
      #define val 100000
      if (dq[val].size())
         cnt[(dq[val].back() - dq[val].front())/C] --,
         res[(dq[val].back() - dq[val].front())] --;

      if (dq[val].back() == pos) dq[val].pop_back();
      else dq[val].pop_front();

      if (dq[val].size()){
         cnt[(dq[val].back() - dq[val].front())/C] ++;
         res[(dq[val].back() - dq[val].front())] ++;
      }
      #undef val
      return;
   }
   #define val a[pos] + 100000
   if (dq[val].size())
      cnt[(dq[val].back() - dq[val].front())/C] --,
      res[(dq[val].back() - dq[val].front())] --;

   if (dq[val].back() == pos) dq[val].pop_back();
   else dq[val].pop_front();

   if (dq[val].size()){
      cnt[(dq[val].back() - dq[val].front())/C] ++;
      res[(dq[val].back() - dq[val].front())] ++;
   }
   #undef val
}
int main(){
   scanf("%d",&test);
   while(test--){
      lst.clear();
      scanf("%d",&n);
      memset(cnt,0,sizeof(cnt));
      for(int i=0;i<n;i++){
         scanf("%d",&a[i]);
         if (i) a[i] += a[i-1];
      }
      scanf("%d",&q);
      while(q--){
         int l,r;
         scanf("%d %d",&l,&r);
         lst.push_back(query(l-2,--r));
      }
      sort(lst.begin(),lst.end(),cmp);
      int cl=-1,cr=-1;
      add(-1);
      long long ans = 0;
      for(int i=0;i<lst.size();i++){
         while(cr < lst[i].r) add(++cr);
         while(cl < lst[i].l) dec(cl++);
         while(cl > lst[i].l) add(--cl);
         while(cr > lst[i].r) dec(cr--);
         int ress = 0;
         for(int j=500;j>=0;j--)
            if (cnt[j]){
               for(int k=j*C;k<(j+1)*C;k++)
                  if (res[k]) ress = max(ress , k);
               break;
            }
         ans += ress;
      }
      while(cr < n) add(++cr);
      while(cl <= n) dec(cl++);
      printf("%lld\n",ans);
   }
}
