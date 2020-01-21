#include <bits/stdc++.h>
using namespace std;
int cnt[55][200];
string s;
int n;
int main(){
   cin >> n;
   for(int i=1;i<=n;i++){
      cin >> s;
      for(int j=0;j<s.size();j++)
         cnt[i][s[j]]++;
   }
   string res;
   for(int c='a';c<='z';c++){
      int mi = 1000000;
      for(int i=1;i<=n;i++)
         mi = min(mi, cnt[i][c]);
      while(mi--)
         res.push_back((char)c);
   }
   cout << res;
}
