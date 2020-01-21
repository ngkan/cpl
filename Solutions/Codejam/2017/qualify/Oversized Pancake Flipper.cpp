#include <bits/stdc++.h>
using namespace std;
int test,k;
string s;
int main(){
   freopen("A-large.in","r",stdin);
   freopen("AA.txt","w",stdout);
   cin >> test;
   for(int t=1;t<=test;t++){
      int cnt = 0;
      cin >> s >> k;
      for(int i=0;i<=(int)s.size()-k;i++){
         cnt += (s[i] != '+');
         if (s[i] != '+')
            for(int j=i;j<i+k;j++)
               s[j] = '+' + '-' - s[j];
      }
      for(int i=s.size()-k+1;i<s.size();i++)
         if (s[i] != '+') cnt = -1;
      if (cnt == -1) cout << "Case #" << t << ": IMPOSSIBLE\n";
      else cout << "Case #" << t << ": " << cnt << '\n';
   }
}
