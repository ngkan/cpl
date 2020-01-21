#include <bits/stdc++.h>
#define ll long long
using namespace std;
int sieve[10000005];
const int N = (int) 1e7;
ll ans = 0;
int a,b;
int main(){
    for(int i=1;i<=N;i++)
        for(int j=i;j<=N;j+=i)
            sieve[j] += i;
    cin >> a >> b;
    for(int i=a;i<=b;i++)
        ans += 1ll * abs(2*i - sieve[i]);
    cout << ans;
}
