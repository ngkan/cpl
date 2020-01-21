#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
   int test;
   cin >> test;
   while(test--){
      ll a,b,c,d;
      cin >> a >> b >> c >> d;
      cout << a * c / __gcd(a,c) << ' ' << __gcd(b,d) << '\n';
   }
}
