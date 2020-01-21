#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
typedef pair<ll,ll> ii;
int n;
ii a[100005];
priority_queue <ll,vector<ll>,greater<ll> > pq;
int main(){
   scanf("%d",&n);
   for(int i=1;i<=n;i++) scanf("%lld",&a[i].fi);
   for(int i=1;i<=n;i++) scanf("%lld",&a[i].se);
   sort(a+1,a+n+1,greater<ii>());
   int sum = 0;
   ll res = 0;
   for(int i=1;i<=n;i++){
      sum--;
      res += a[i].se;
      pq.push(a[i].se);
      if (sum < 0){
         sum += 2;
         res -= pq.top();
         pq.pop();
      }
   }
   printf("%lld",res);
}
