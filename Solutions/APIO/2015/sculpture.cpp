#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a,b,x[2005];
ll res = 0;
bool dp[2005][2005];
int dp2[2005];
int main(){
   cin >> n >> a >> b;
   for(int i=1;i<=n;i++)
      cin >> x[i];
   if (a > 1){
      for(int bit=40;bit>=0;bit--){
         memset(dp,0,sizeof(dp));
         dp[0][0] = 1;
         for(int i=0;i<=n;i++){
            for(int j=0;j<=i;j++){
               if (!dp[i][j]) continue;
               ll sum = 0;
               for(int k=i+1;k<=n;k++){
                  sum += x[k];
                  if (((sum>>bit)|(res>>bit)) == (res>>bit))
                     dp[k][j+1] = 1;
               }
            }
         }
         bool ok = 0;
         for(int j=a;j<=b;j++)
            if (dp[n][j]) ok = 1;
         if (!ok) res += (1ll<<bit);
      }
   }
   else{
      for(int bit=40;bit>=0;bit--){
         fill(dp2,dp2+n+1,(int)1e9);
         dp2[0] = 0;
         for(int i=0;i<=n;i++){
            if (dp2[i] == (int)1e9) continue;
            ll sum = 0;
            for(int k=i+1;k<=n;k++){
               sum += x[k];
               if (((sum>>bit)|(res>>bit)) == (res>>bit))
                  dp2[k] = min(dp2[k], dp2[i]+1);
            }
         }
         if (dp2[n] > b) res += (1ll<<bit);
      }
   }
   cout << res;
}
