#include <bits/stdc++.h>
using namespace std;
int l,s,d,k;
int ban[200005], fitick[200005];
int tick[200005];
int dp[200005];
int main(){
   cin >> l >> s >> d;
   cin >> k;
   while(k--){
      int x,y;
      cin >> x >> y;
      if (y == 1) tick[x] = 1;
      else
         ban[x]++,
         ban[x+s]--;
   }
   fitick[0] = -10000000;
   for(int i=1;i<=l;i++)  ban[i] += ban[i-1];
   for(int i=1;i<=l;i++)  if (tick[i]) fitick[i] = i; else fitick[i] = fitick[i-1];
   deque <int> dq;
   for(int i=1;i<=l;i++){
      if (i >= s+d){
         while(dq.size() && dp[dq.back()] <= dp[i-s-d]) dq.pop_back();
         dq.push_back(i-s-d);
      }
      if (ban[i]){
         dp[i] = -1000000;
      }
      else{
         int pos = (i>=s ? fitick[i-s] : -1000000);
         //cout << i << ' ' << pos << endl;
         if (i - pos < s + d){
            dp[i] = -1000000;
         }
         else{
            while(dq.size() && dq.front() < fitick[i-s]) dq.pop_front();
            if (dq.size())
               dp[i] = dp[dq.front()] + 1;
            else{
               if (i >= s)
                  dp[i] = 1;
               else
                  dp[i] = -1000000;
            }
            //cout << i << ' ' << dp[i] << endl;
         }
      }
   }
   //for(int i=1;i<=l;i++) cout << ban[i] << ' '; cout << endl;
   int ans = -100000;
   for(int i=max(1,fitick[l]);i<=l;i++) ans = max(ans, dp[i]);
   if (ans > 0) cout << ans;
   else cout << -1;
}
