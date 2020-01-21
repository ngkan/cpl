#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = (ll) 1e9+7;
string a,b;
ll n, pow10[60005];
ll cnt[60005][10], sumb[60005], suma[60005];
void add(ll &x, ll val){
   x = ((x + val) % mod + mod) % mod;
}
void prep(){
   pow10[0] = 1;
   for(int i=1;i<=60000;i++) pow10[i] = pow10[i-1] * 10 % mod;
}
void calb(ll prefix, ll pos){
   if (pos == 0) return;
   //cout << pos << endl;
   for(int i=0;i<10;i++)
      add(cnt[pos][i], prefix * pow10[pos-1]);

   for(int i=0;i<b[pos]-'0';i++)
      add(cnt[pos][i], pow10[pos-1]);

   add(cnt[pos][b[pos]-'0'], sumb[pos-1] + 1);

   prefix = (prefix * 10 + b[pos] - '0') % mod;
   calb(prefix, pos-1);
}
void dob(){
   for(int i=1;i<=n;i++)
      sumb[i] = (sumb[i-1] + pow10[i-1] * (b[i] - '0')) % mod;
   calb(0, n);
}
void cala(ll prefix, ll pos){
   if (pos == 0) return;

   for(int i=0;i<10;i++)
      add(cnt[pos][i], -prefix * pow10[pos-1]);

   for(int i=0;i<a[pos]-'0';i++)
      add(cnt[pos][i], -pow10[pos-1]);

   add(cnt[pos][a[pos]-'0'], -suma[pos-1] - 1);

   prefix = (prefix * 10 + a[pos] - '0') % mod;
   cala(prefix, pos-1);
}
void doa(){
   for(int i=1;i<=n;i++)
      suma[i] = (suma[i-1] + pow10[i-1] * (a[i] - '0')) % mod;
   cala(0, n);
}
int main(){
   freopen("parovi.in.10c","r",stdin);
   //freopen("out.txt","w",stdout);
   prep();
   cin >> a >> b;
   reverse(a.begin(),a.end());
   reverse(b.begin(),b.end());
   while(a.size() < b.size()) a.push_back('0');
   while(b.size() < a.size()) b.push_back('0');
   for(int i=0;i<a.size();i++){
      if (a[i] != '0') {a[i]--; break;}
      a[i] = '9';
   }
   n = a.size();
   a.insert(a.begin(),'0');
   b.insert(b.begin(),'0');
   dob();
   doa();
   //for(int i=0;i<10;i++) cout << cnt[3][i] << ' '; cout << endl;
   ll ans = 0;
   for(int i=1;i<=60000;i++){
      for(int n1=0;n1<10;n1++)
         for(int n2=0;n2<10;n2++)
            add(ans, abs(n2-n1) * cnt[i][n2] % mod * cnt[i][n1] % mod);
   }
   cout << ans;
}
