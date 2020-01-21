#include <bits/stdc++.h>
using namespace std;
const long long mod = (long long) 1e9 + 7;
long long t,a,b;
long long zzpow(long long x,long long p){
    if (!p) return 1ll;
    long long t = zzpow(x,p/2);
    if (p%2) return t * t % mod * x % mod;
    return t * t % mod;
}
int main(){
    cin >> a >> b >> t;
    cout << zzpow(a+b,t) * zzpow(zzpow(2,t),mod-2) % mod;
}
