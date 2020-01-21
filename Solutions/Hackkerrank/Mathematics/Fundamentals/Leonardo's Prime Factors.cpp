#include <bits/stdc++.h>
#define ll long long
using namespace std;
int q;
ll n;
bool prime(ll x){
    if (x < 2) return 0;
    for(int i=2;i<x-1;i++)
        if (x%i==0) return 0;
    return 1;
}
int main(){
    iostream::sync_with_stdio(0);
    cin >> q;
    while(q--){
        cin >> n;
        ll cnt=0,pro=1;
        for(ll i=2;;i++){
            if (!prime(i)) continue;
            if (n/i < pro) break;
            cnt++;
            pro *= i;
        }
        cout << cnt << '\n';
    }
}
