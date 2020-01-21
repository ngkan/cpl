#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a,b,n,val[100005];
priority_queue<ll> mjk[100005];
ll ahi[100005];
int main(){
   cin >> a >> b;
   n = b-a+1;
   for(int i=1;i<=n;i++)
      val[i] = a-1+i,
      ahi[i] = 1;
   for(int i=2;i<=1000000;i++){
      int x = a % i;
      int ctrl = 1 + (i-x)%i;
      for(;ctrl<=n;ctrl+=i){
         ll cnt = 1;
         while(val[ctrl] % i == 0)
            cnt++,
            val[ctrl] /= i;
         if (cnt == 1) continue;
         mjk[ctrl].push(cnt);
         ahi[ctrl] *= cnt;
      }
   }
   for(int i=1;i<=n;i++)
      if (val[i] != 1) ahi[i] *= 2, mjk[i].push(2);
   ll ans = 0;
   for(int i=1;i<=n;i++){
      while(mjk[i].size()){
         ans += ahi[i];
         ahi[i] = ahi[i] / mjk[i].top() * (mjk[i].top()-1);
         if (mjk[i].top() > 2) mjk[i].push(mjk[i].top()-1);
         mjk[i].pop();
      }
   }
   cout << ans;
}
