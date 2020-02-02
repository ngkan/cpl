#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int,int> ii;
priority_queue<ii,vector<ii>,greater<ii> > pq;
int n,a[5005],d[50005];
int main(){
   scanf("%d",&n);
   for(int i=0;i<n;i++)
      scanf("%d",&a[i]);
   for(int i=0;i<a[0];i++)
      d[i] = (int) 1e9+5;
   for(int i=0;i<n;i++)
      pq.push(ii(a[i], a[i]%a[0])),
      d[a[i]%a[0]] = min(d[a[i]%a[0]], a[i]);
   d[0] = 0;
   pq.push(ii(0,0));

   while(pq.size()){
      int u = pq.top().se;
      int du = pq.top().fi;
      pq.pop();
      if (du != d[u]) continue;
      for(int i=0;i<n;i++){
         int v = (u+a[i])%a[0];
         if (d[v] > du + a[i])
            d[v] = du + a[i],
            pq.push(ii(d[v],v));
      }
   }
   int q,x;
   scanf("%d",&q);
   while(q--){
      scanf("%d",&x);
      if (x >= d[x%a[0]]) printf("TAK\n");
      else printf("NIE\n");
   }
}
