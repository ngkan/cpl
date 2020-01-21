#include <iostream>
using namespace std;
#define ll long long
int main(){
    ll n,m,k;
    cin >> n >> m >> k;
    if (k > n+m-2) return cout << -1,0;
    ll ans = 0;
    if (k < m) ans = max(ans, n*(m/(k+1)));
    else ans = max(ans, n/(k-m+2));
    if (k < n) ans = max(ans, m*(n/(k+1)));
    else ans = max(ans, m/(k-n+2));
    cout << ans;
}
