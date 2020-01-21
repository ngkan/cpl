#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,x,a,b,m;
ll arr[100005];
int main(){
    cin >> n >> x >> a >> b >> m;
    m -= x * n;
    ll l = -1, r = n * (n-1)/2;
    while(l+1<r){
        ll mid = (l+r)/2;
        if (a * mid - b * (n * (n-1) / 2 - mid) >= m)    r = mid;
        else l = mid;
    }
    for(int i=n-1;i>=1;i--){
        if (r >= i)
            arr[i] = a,
            r -= i;
        else
            arr[i] = -b;
    }
    cout << x << ' ';
    for(int i=1;i<=n-1;i++){
        x += arr[n-i];
        cout << x << ' ';
    }
}
