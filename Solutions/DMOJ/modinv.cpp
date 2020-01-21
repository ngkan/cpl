#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
ull x,y;
ull modinv(ull a,ull mod){
    ull x1 = 1, x2 = 0, r1 = a, r2 = mod, q, rtmp, xtmp;
    while(r2){
        q = r1 / r2;
        rtmp = r1 % r2;
        xtmp = x2;
        x2 = x1 - x2 * q;
        x1 = xtmp;
        r1 = r2;
        r2 = rtmp;
    }
    return (x1 + mod) % mod;
}
int main(){
    cin >> x >> y;
    cout << modinv(x,y);
}
