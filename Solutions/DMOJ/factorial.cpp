#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
ull t,n,ans;
int main(){
    ans = 1;
    cin >> t;
    while(t--){
        ans = 1;
        cin >> n;
        for(ull i=1;i<=min(n,50ull);i++)
            ans *= i;
        ans %= (1ull<<32);
        cout << ans << endl;
    }
}
