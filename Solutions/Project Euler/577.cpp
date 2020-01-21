#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll n;
    scanf("%lld",&n);
    ll truesum = 0, sum = 0, now = 0, cnt = 0;
    for(ll i=1;i<=n;i++){
        if (i % 3 == 0) cnt += i / 3;
        now += cnt;
        sum += now;
        truesum += sum;
    }
    cout << truesum;
}
