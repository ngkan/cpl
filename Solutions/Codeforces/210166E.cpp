#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
typedef pair<ll,int> ii;
ii a[200005];
ll n, tcd[200005];
ll get(int l,int r){
   return tcd[r] - tcd[l-1];
}
bool check(int L,int R){
   if (R - L < 2) return 1;
   int mid = (L+R)/2;
   return get(L,mid) > get(mid+1+((R-L+1)%2==0),R);
}
bool mark[200005];
bool cmp(ii x,ii y){
   return x.se < y.se;
}
int main(){
   scanf("%lld",&n);
   for(int i=1;i<=n;i++)
      scanf("%lld",&a[i].fi),
      a[i].se = i;
   sort(a+1,a+n+1);
   for(int i=1;i<=n;i++)
      tcd[i] = a[i].fi + tcd[i-1];
   int al = 1, ar = 1;
   int l = 1;
   for(int r=1;r<=n;r++){
      while(l <= r && !check(l,r)) ++l;
      if (r - l > ar - al){
         ar = r;
         al = l;
      }
      else if (r - l == ar - al && l == r-1){
         if (a[l] == a[r])
            al = l,
            ar = r;
      }
   }
   ll mjk;
   if (al == ar -1) mjk = a[ar].fi;
   else mjk = a[al + (ar - al + 1)/2].fi;

   for(int i=1;i<al;i++) mark[a[i].se] = 1;
   for(int i=ar+1;i<=n;i++) mark[a[i].se] = 1;
   sort(a+1,a+n+1,cmp);
   for(int i=1;i<n;i++)
      if (mark[i]) printf("%lld ",mjk);
      else printf("%lld ", a[i].fi);
   if (mark[n])printf("%lld",mjk);
      else printf("%lld", a[n].fi);
}
