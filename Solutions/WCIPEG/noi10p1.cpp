#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll total[100005];
int main(){
    int n,m;
    cin >> n >> m;
    long long res = 0;
    for(int i = 100000; i >= 1; i--){
        total[i] = 1ll * (n / i) * (m / i);
        for(int j = 2*i;j <= 100000;j += i)
            total[i] -= total[j];
        res += total[i] * (2*i-1);
    }
    cout << res;
}
