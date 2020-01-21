#include <bits/stdc++.h>
using namespace std;
int test;
int main(){
   cin >> test;
   while(test--){
      vector <string> a,b;
      string s;
      for(int i=0;i<4;i++) cin >> s, a.push_back(s);
      for(int i=0;i<4;i++) cin >> s, b.push_back(s);
      int cnt=0;
      for(int i=0;i<a.size();i++)
         for(int j=0;j<b.size();j++)
            if (a[i] == b[j]) cnt++;
      if (cnt>1) cout << "similar\n";
      else cout << "dissimilar\n";
   }
}
