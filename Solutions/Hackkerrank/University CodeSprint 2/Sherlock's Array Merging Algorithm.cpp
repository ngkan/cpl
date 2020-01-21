#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = (ll) 1e9+7;
ll Ckn[1205][1205], revfact[1205][1205];
void prep(){
    for(int i=0;i<=1200;i++)
        Ckn[0][i] = 1ll;
    for(int i=1;i<=1200;i++){
        Ckn[i][i] = 1;
        for(int j=i+1;j<=1200;j++)
            Ckn[i][j] = (Ckn[i][j-1] + Ckn[i-1][j-1]) % mod;
    }
    for(int i=1200;i>=1;i--){
        revfact[i][i+1] = 1;
        for(int j=i;j>=1;j--)
            revfact[i][j] = revfact[i][j+1] * j % mod;
    }
}
ll n,a[1205];
bool ok[1205][1205];
ll dp[1205][1205], cnt[1205][1205];
int main(){
    prep();
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=1;i<=n;i++){
        ok[i][i] = 1;
        for(int j=i+1;j<=n;j++){
            if (a[j-1] > a[j]) break;
            ok[i][j] = 1;
        }
    }
    dp[n+1][0] = 1;
    for(int i=n;i>=1;i--){
        #define len j-i+1
        for(int j=i;j<=n;j++){
            if (!ok[i][j]) break;
            for(int lenl=0;lenl<=len;lenl++)
                dp[i][len] = (dp[i][len] + dp[i+len][lenl] * revfact[len][len-lenl+1])%mod;
           // cout << i << ' ' << j << ' ' << dp[i][len] << endl;
        }
//        for(int j=i;j<=n;j++)
//            cnt[i][len] = (cnt[i][len-1] + dp[i][len]) % mod;
    }
    ll ans = 0;
    for(int i=0;i<=n;i++)
        ans = (ans + dp[1][i]) % mod;
    cout << ans;
}
