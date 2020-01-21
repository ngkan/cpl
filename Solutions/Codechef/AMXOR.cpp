#include <stdio.h>
#include <iostream>
#define ll long long
using namespace std;
const ll mod = (ll) 1e9+9;
ll t,n,k,a[100005],dp[100005][3],ans;
ll inv2[100005];
long long mod_inverse(long long a,long long mod){
    // gcd(a,m) must equal to 1
    // calucate a^(-1) % mod
    // khung hon fermat
    long long r1 = a, r2 = mod, x1 = 1,x2 = 0, q, tmp;
    while(r2 != 0){
        q = r1 / r2;
        tmp = x1 -  q * x2;
        x1 = x2;
        x2 = tmp;
        tmp = r1 % r2;
        r1 = r2;
        r2 = tmp;
    }
    return (x1+mod+mod)%mod;
}
int main(){
    scanf("%lld",&t);
    ll tmp = 1;
    inv2[0] = 1;
    for(int i=1;i<=100000;i++){
        tmp = (tmp * 2) % mod;
        inv2[i] = mod_inverse(tmp,mod);
    }
    while(scanf("%lld",&n) == 1){
        if (!n && !k) break;
        ans = 0;k=0;
        for(int i=1;i<=n;i++)   scanf("%lld",&a[i]),k^=a[i];
        for(int pos=30;pos>=-1;pos--){
            if (pos == -1){
                ans = (ans + 1) % mod;
                break;
            }
            for(int i=0;i<=n;i++) dp[i][0] = dp[i][1] = 0;
            dp[0][0] = 1;
            for(int i=1;i<=n;i++){
                if (!(a[i] & (1<<pos)))
                    dp[i][0] = dp[i-1][0] * (a[i]+1) % mod,
                    dp[i][1] = dp[i-1][1] * (a[i]+1) % mod;
                else
                    dp[i][0] = (dp[i-1][0] * (1ll<<pos) % mod + dp[i-1][1] * (a[i] - (1ll<<pos)+1) % mod) % mod,
                    dp[i][1] = (dp[i-1][0] * (a[i] - (1ll<<pos)+1) % mod + dp[i-1][1] * (1ll<<pos) % mod) % mod;
            }
            //cout << pos << ' ' << dp[n][0] << ' ' << dp[n][1] << endl;
            int cnt = 0;
            for(int i=1;i<=n;i++)   cnt += ((a[i] & (1ll<<pos)) > 0);
            //cout << cnt << endl;
            if ((k & (1ll<<pos))){    // 1
                if (cnt % 2){
                    ll mul = 1;
                    for(int i=1;i<=n;i++)
                        if ((a[i] & (1<<pos)))
                            mul = mul * (a[i] - (1<<pos) + 1) % mod;
                        else
                            mul = mul * (a[i] + 1) % mod;
                    ans = (ans + (dp[n][1]- mul + mod) % mod * inv2[pos] % mod) % mod;
                }
                else{
                    ans = (ans + dp[n][1] * inv2[pos] % mod) % mod;
                    break;
                }
            }
            else{
                if (cnt % 2 == 0){
                    ll mul = 1;
                    for(int i=1;i<=n;i++)
                        if ((a[i] & (1<<pos)))
                            mul = mul * (a[i] - (1<<pos) + 1) % mod;
                        else
                            mul = mul * (a[i] + 1) % mod;
                    ans = (ans + (dp[n][0] - mul + mod) % mod * inv2[pos] % mod) % mod;
                    //cout << ans << ' ' << mul << ' ' << dp[n][0] - mul << ' ' << (dp[n][0] - mul + mod) % mod * inv2[pos] << endl;
                }
                else{
                    ans = (ans + dp[n][0] * inv2[pos] % mod) % mod;
                    break;
                }
            }
            for(int i=1;i<=n;i++)
                a[i] = (a[i] & (a[i] ^ (1ll<<pos)));
        }

        printf("%lld\n",ans);
    }
}
