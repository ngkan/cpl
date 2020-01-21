#include <bits/stdc++.h>
using namespace std;
int ans,n,m,a[100005];
string op[100005];
int cal[30][2];
int main(){
   iostream::sync_with_stdio(0);
   cin >> n >> m;
   for(int i=1;i<=n;i++)
      cin >> op[i] >> a[i];
   for(int bit=0;bit<30;bit++){
      cal[bit][1] = 1;
      for(int i=1;i<=n;i++)
         if (op[i] == "OR")
            cal[bit][0] = (cal[bit][0] | ((a[i] >> bit) & 1)),
            cal[bit][1] = (cal[bit][1] | ((a[i] >> bit) & 1));
         else if (op[i] == "XOR")
            cal[bit][0] = (cal[bit][0] ^ ((a[i] >> bit) & 1)),
            cal[bit][1] = (cal[bit][1] ^ ((a[i] >> bit) & 1));
         else
            cal[bit][0] = (cal[bit][0] & ((a[i] >> bit) & 1)),
            cal[bit][1] = (cal[bit][1] & ((a[i] >> bit) & 1));
   }
   bool ok = 0;
   int res = 0;
   for(int bit=29;bit>=0;bit--){
      if (((m>>bit)&1) == 1) ok = 1;
      if (ok){
         int tmp = res + (cal[bit][0] << bit);
         for(int i=bit-1;i>=0;i--)
            tmp += (max(cal[i][0], cal[i][1]) << i);
         ans = max(ans, tmp);
      }
      if (((m>>bit)&1) == 1) res += (cal[bit][1] << bit);
      else res += (cal[bit][0] << bit);
   }
   cout << max(ans, res);
}
