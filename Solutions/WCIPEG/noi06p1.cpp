#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int,int> ii;
int n, c[1024], f[1024][1024], g[1024][2][1024], plan[1024];
map <ii,int> dp[2048];
int DP(int id,int l,int r,int lv,int kid1,int mask){
   //cout << id << ' ' << l << ' ' << r << ' ' << lv << ' ' << kid1 << ' ' << mask << endl;
   if (l == r)
      return g[l][kid1][mask] + (plan[l] ^ kid1) * c[l];
   if (dp[id].count(ii(kid1,mask)))
      return dp[id][ii(kid1,mask)];
   int res = 2000000000;
   for(int i=0;i<=kid1;i++){
      int k1l = i, k1r = kid1 - i;
      if (k1l > (1<<(n-lv-1)) || k1r > (1<<(n-lv-1))) continue;
      res = min(res, DP(2*id,l,(l+r)/2,lv+1,k1l,mask + ((kid1 > (1<<(n-lv-1))) << lv))
                     + DP(2*id+1,(l+r)/2+1,r,lv+1,k1r,mask + ((kid1 > (1<<(n-lv-1))) << lv)));
   }
   return dp[id][ii(kid1,mask)] = res;
}
void init(void){
   scanf("%d",&n);
   for(int i=0;i<(1<<n);i++)
      scanf("%d",&plan[i]);
   for(int i=0;i<(1<<n);i++)
      scanf("%d",&c[i]);
   for(int i=0;i<(1<<n);i++)
      for(int j=i+1;j<(1<<n);j++)
         scanf("%d",&f[i][j]),
         f[j][i] = f[i][j];
}
void prep(void){
   for(int i=0;i<(1<<n);i++)
      for(int j=1;j<(1<<n);j++)
         f[i][j] += f[i][j-1];

   for(int i=0;i<(1<<n);i++){
      for(int t=0;t<2;t++){
         for(int mask=0;mask<(1<<n);mask++){
            int l = 0, r = (1<<n) - 1;
            for(int bit=0;bit<n;bit++){
               int mid = (l+r)/2;
               if (((mask>>bit)&1)^t){
                  if (i <= mid)
                     g[i][t][mask] += f[i][r] - f[i][mid];
                  else
                     g[i][t][mask] += f[i][mid] - (l ? f[i][l-1] : 0);
               }
               if (i <= mid) r = mid;
               else l = mid + 1;
            }
         }
      }
   }
}
int main(){
   init();
   prep();
   int ans = 2000000000;
   for(int i=0;i<=(1<<n);i++)
      ans = min(ans, DP(1,0,(1<<n)-1,0,i,0));
   cout << ans;
}
