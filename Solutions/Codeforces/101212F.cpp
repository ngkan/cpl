#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = (ll) 1e9+7;
set < vector<int> > s;
set < vector<int> > s2;
ll n,ma,a[66],ans;
ll test;
int main(){
   cin >> test;
   while(test--){
      ans = 0;  s.clear();  s2.clear();
      cin >> n >> ma;
      for(int i=1;i<=n;i++)   cin >> a[i];

      for(int i=1;i<=n;i++){
         vector <int> tmp;
         for(int j=1;j<i;j++) tmp.push_back(a[j]);
         for(int j=i+1;j<=n;j++) tmp.push_back(a[j]);
         s.insert(tmp);
      }

      for(set <vector<int> >::iterator it = s.begin(); it != s.end(); it++){
         vector<int> tmp = *it;

         vector <int> mjk(a+1,a+n+1);
         sort(mjk.begin(),mjk.end());
         mjk.resize(distance(mjk.begin(), unique(mjk.begin(),mjk.end())));

         ans += n * (ma - mjk.size()) % mod;

         for(int i=0;i<=tmp.size();i++){
            vector <int> tmp2;
            for(int j=0;j<i;j++) tmp2.push_back(tmp[j]);
            for(int k=0;k<mjk.size();k++){
               tmp2.push_back(mjk[k]);
               for(int l=i;l<(int)tmp.size();l++) tmp2.push_back(tmp[l]);
               s2.insert(tmp2);
               while(tmp2.size() > i) tmp2.pop_back();
            }
         }
      }

      cout << (ans + s2.size()) % mod << endl;
   }
}
