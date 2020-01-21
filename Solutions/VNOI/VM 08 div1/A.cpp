#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef pair<int,int> ii;
int n,m,s,cnt;
vector <ii> a;
int main(){
   cin >> n >> m >> s;
   for(int i=0;i<=n;i++)
      for(int j=0;j<=m;j++)
         a.push_back(ii(i,j));
   for(int i=0;i<a.size();i++)
      for(int j=i+1;j<a.size();j++)
         for(int k=j+1;k<a.size();k++){
            int val = (a[i].x - a[j].x) * (a[i].y + a[j].y)
                     +(a[j].x - a[k].x) * (a[j].y + a[k].y)
                     +(a[k].x - a[i].x) * (a[k].y + a[i].y);
            val = max(val,-val);
            if (val == 2*s) cnt++;
         }
   cout << cnt;
}
