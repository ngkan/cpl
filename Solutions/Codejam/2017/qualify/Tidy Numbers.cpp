#include <bits/stdc++.h>
using namespace std;
#define ll long long
int test;
ll n;
ll mjk[20];
int main(){
   freopen("B-large.in","r",stdin);
   freopen("BB.txt","w",stdout);
   mjk[1] = 1;
   for(int i=2;i<=18;i++)
      mjk[i] = mjk[i-1] * 10 + 1;
   cin >> test;
   for(int t=1;t<=test;t++){
      cin >> n;
      ll ans = 0;
      for(int i=18;i>=1;i--)
         while(ans + mjk[i] <= n && ans%10 < 9)
            ans += mjk[i];
      cout << "Case #" << t << ": " << ans << endl;
   }
}
