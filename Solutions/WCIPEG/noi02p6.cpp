#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 10000;
int n, a[1005], p[1005];
int dp[1005][2];
void why(){
   int ans = 1;
   while(--p[1]) ans = ans * 2 % mod;
   printf("0\n0\n%d",ans);
   exit(0);
}
int zzpow(int x,int p){
   int ans = 1;
   int mjk = x;
   for(int bit=0;(1<<bit)<=p;bit++){
      if ((p>>bit)&1) ans = ans * mjk % mod;
      mjk = mjk * mjk % mod;
   }
   return ans;
}
int main(){
   scanf("%d",&n);
   for(int i=1;i<=n;i++)
      scanf("%d %d",&a[i],&p[i]);
   if (n == 1 && a[1] == 2)   why();
   dp[0][0] = 1;
   for(int i=1;i<=n;i++){
      if (a[i] == 2){
         dp[1][0] = 1;
         continue;
      }
      dp[i][0] = (dp[i-1][0] + dp[i-1][1] * (a[i] - 1)) % mod;
      dp[i][1] = (dp[i-1][1] + dp[i-1][0] * (a[i] - 1)) % mod;
   }
   dp[n][0] = (dp[n][0] + mod - 1) % mod;
   //cout << dp[n][0] << ' '<< dp[n][1];
   int r3 = 1;
   for(int i=1;i<=n;i++){
      r3 = r3 * zzpow(a[i], p[i]) % mod;
   }
   printf("%d\n%d\n%d",dp[n][0],dp[n][1],(r3-dp[n][0]-dp[n][1]-1 + 2*mod) % mod);
}
