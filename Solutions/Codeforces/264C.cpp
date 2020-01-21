#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,q,a,b,v[100005],c[100005];
ll ahi[100005];
int main(){
   scanf("%lld %lld",&n,&q);
   for(int i=1;i<=n;i++)   scanf("%lld",&v[i]);
   for(int i=1;i<=n;i++)   scanf("%lld",&c[i]);
   while(q--){
      fill(ahi+1,ahi+n+2,(ll)-1e18);
      ll ln1 = 0, ln2 = n+1;
      scanf("%lld %lld",&a,&b);
      for(int i=1;i<=n;i++){
         assert(ln1 != ln2);
         if (ln1 != c[i])
            ahi[c[i]] = max(ahi[c[i]], max(ahi[c[i]] + v[i] * a, ahi[ln1] + v[i] * b));
         else
            ahi[c[i]] = max(ahi[c[i]], max(ahi[c[i]] + v[i] * a, ahi[ln2] + v[i] * b));
         if (c[i] == ln1) ;
         else if (c[i] == ln2){
            if (ahi[ln2] > ahi[ln1]) swap(ln2, ln1);
         }
         else{
            if (ahi[c[i]] >= ahi[ln1])
               ln2 = ln1,
               ln1 = c[i];
            else if (ahi[c[i]] >= ahi[ln2])
               ln2 = c[i];
         }
      }
      printf("%lld\n",ahi[ln1]);
   }
}
