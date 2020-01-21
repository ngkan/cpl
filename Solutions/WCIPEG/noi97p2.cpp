#include <bits/stdc++.h>
using namespace std;
int m,n;
string s;
int w[505][505], f[505][505];
int main(){
   getline(cin, s);
   int tmp = 0;
   for(int i=0;i<s.size();i++){
      if (s[i] == ' '){
         m = tmp;
         tmp = 0;
         continue;
      }
      tmp = tmp * 10 + s[i] - '0';
   }
   n = tmp;
   tmp = 0;
   while(m--){
      vector <int> mjk;
      getline(cin, s);
      for(int i=0;i<s.size();i++){
         if (s[i] == ' '){
            mjk.push_back(tmp);
            tmp = 0;
            continue;
         }
         tmp = tmp * 10 + s[i] - '0';
      }
      mjk.push_back(tmp);
      tmp = 0;
      for(int i=0;i<mjk.size();i++)
         for(int j=i+1;j<mjk.size();j++)
            w[mjk[i]][mjk[j]] = 1;
   }
   for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
         f[i][j] = w[i][j] ? 1 : 100000;
   for(int k=1;k<=n;k++)
      for(int i=1;i<=n;i++)
         for(int j=1;j<=n;j++)
            f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
   if (f[1][n] == 100000) cout << "NO";
   else cout << f[1][n] - 1;
}
