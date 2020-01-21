#include <bits/stdc++.h>
#define ll long long
using namespace std;
int t;
string s;
int main(){
   cin >> t;
   while(t--){
      ll ans = 0;
      int cnt = 0;
      cin >> s;
      for(int i=0;i<s.size();i++){
         if (s[i] == '1')
            cnt++,
            ans += (i < (int)s.size()-1 && s[i+1] == '0') * cnt;
      }
      for(int i=0;i<s.size();i++)
         if (s[i] == '1')
            ans += s.size() - i - cnt,
            cnt--;
      cout << ans << endl;
   }
}
