#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
ll test,n;
ll zzpow(ll x,ll p){
    if (!p) return 1ll;
    ll t = zzpow(x,p/2);
    if (p%2) return t*t*x;
    return t*t;
}
int main(){
    //freopen("dm.txt","r",stdin);
    //freopen("ax.txt","w",stdout);
    cin >> test;
    while(test--){
        cin >> n;
        //cout << n << endl;
        if (n == 0) {cout << 0 << endl; continue;}
        if (n == 1) {cout << "INFINITY" << endl; continue;}
        if (n == 2) {cout << 1 << endl; continue;}
        ll ans = 0;
        for(int i=1;i<=40;i++){
            if (i <= 21){
                double bound = pow(1.0*n/2.0,1.0/i);
                bound = floor(bound);
                ll x = bound;
                x--;
                while(!(2*zzpow(x,i) > n)) x++;
                double up = pow(1.0*n,1.0/i);
                ll y =  ceil(up);
                y++;
                while(!(n >= zzpow(y,i))) y--;
                ans += max(0ull,y-x+1);
            }
            else{
                ll x;
                for(x=2;x<=3;x++)  if ((2*zzpow(x,i) > n && n >= zzpow(x,i))) ans++;
            }
        }
        cout << ans << endl;
    }
}
