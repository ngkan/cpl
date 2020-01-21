#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
int main(){
   cin >> n;
   n*=2ll;
   for(ll i=1;i<=min((ll)sqrt(n), n);i++){
      if (n%i) continue;
      ll sum = n/i;
      ll diff = i;
      if (sum < diff) swap(sum,diff);
      sum--;
      if (sum < diff) continue;
      if ((sum-diff) % 2 != 0) continue;
      if (diff != 1)
      cout << (sum-diff)/2ll + 1 << ' ' << (sum+diff)/2ll << '\n';
   }
}
