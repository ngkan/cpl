#include <bits/stdc++.h>
using namespace std;
string s,t;
int q,a,b,c,d;
int tcd[2][100005];
int main(){
   iostream::sync_with_stdio(0);
   cin >> s >> t;
   s = '0' + s;
   t = '0' + t;
   cin >> q;
   for(int i=1;i<s.size();i++)
      tcd[0][i] = (tcd[0][i-1] + (s[i] == 'A' ? 1 : 2)) % 3;
   for(int i=1;i<t.size();i++)
      tcd[1][i] = (tcd[1][i-1] + (t[i] == 'A' ? 1 : 2)) % 3;
   while(q--){
      cin >> a >> b >> c >> d;
      int v1 = (tcd[0][b] - tcd[0][a-1] + 3)  % 3;
      int v2 = (tcd[1][d] - tcd[1][c-1] + 3)  % 3;
      if (v1 == v2) cout << "YES\n";
      else cout << "NO\n";
   }
}
