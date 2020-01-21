#include <stdio.h>
#define ll long long
using namespace std;
const int N = (int) 1e5+5;
const ll mod = (ll) 1e9+7;
ll n,q,a,b,f[N],x[N],up[N],down[N];
int main(){
    scanf("%lld %lld",&n,&q);
    scanf("%lld %lld %lld %lld",&f[1],&f[2],&a,&b);
    for(int i=3;i<=N-5;i++)
        f[i] = (a * f[i-2] % mod + b * f[i-1] % mod);
    for(int i=1;i<=n;i++)
        scanf("%lld",&x[i]);
    while(q--){
        ll l,r;
        scanf("%lld %lld",&l,&r);
        up[l] = (up[l] + f[1]) % mod;
        up[l+1] = (up[l+1] + f[2] - b * f[1] % mod + mod) % mod;
        down[r+1] = (down[r+1] + f[r-l+2]) % mod;
        down[r+2] = (down[r+2] + f[r-l+3] - b * f[r-l+2] % mod + mod) % mod;
    }
    for(int i=1;i<=n;i++){
        if (i > 1){
            up[i] = (up[i] + a * up[i-2] % mod + b * up[i-1] % mod) % mod;
            down[i] = (down[i] + a * down[i-2] % mod + b * down[i-1] % mod) % mod;
        }
        printf("%lld ",(x[i] + up[i] - down[i] + mod) % mod);
    }
}
