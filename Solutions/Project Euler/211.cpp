#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int n = 64000000 - 1;
ll sum[n+5];
int main(){
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j+=i){
            sum[j] += 1ll * i * i;
        }
    }
    ll res = 0;
    for(int i=1;i<=n;i++){
        if (sum[i] == (ll) sqrt(sum[i]) * (ll) sqrt(sum[i])) res += i;
    }
    cout << res;
}
