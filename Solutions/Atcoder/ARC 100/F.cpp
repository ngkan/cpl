#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = (ll) 1e9+7;
ll zzpow(ll x,ll p){
    if (!p) return 1;
    ll t = zzpow(x, p/2);
    if (p%2)    return t * t % mod * x % mod;
    return t * t % mod;
}
int n, k, m;
int a[25005];
ll dp[25005][405];
ll f[25005][405];
void doF(int lim=0){
    for(int i=1;i<=n;i++){
        for(int j=k;j>=1;j--){
            f[i][j] = (f[i][j+1] - dp[i][j+1] * (j+1 >= lim) % mod + mod) % mod;
            if (j != k) f[i][j] = (f[i][j] - f[i-1][j] * (k - j - 1) % mod + mod) % mod;

            f[i][j] = (f[i][j] + f[i-1][j-1] * (k - j + 1) % mod + dp[i][j] * (j >= lim)) % mod;

        }
    }
}
void doDp(int x=0,int y=0,ll val=1){
    if (x == 0) dp[x][y] = val;
    for(int i=1;i<=n;i++){
        for(int j=k;j>=1;j--){
            dp[i][j] = dp[i][j+1];
            if (j != k) dp[i][j] = (dp[i][j] - dp[i-1][j] * (k - j - 1) % mod + mod) % mod;
            dp[i][j] = (dp[i][j] + dp[i-1][j-1] * (k - j + 1)) % mod;
        }
        if (i == x) dp[x][y] = val;
    }
}
int main(){
//    n = 3;
//    k = 3;
//    m = k;
//    doDp();
//    doF(m);
//    ll cnt = 0;
//    for(int i=1;i<k;i++)    cnt += f[n][i];
//    cout << cnt << endl;
//    return 0;

    iostream::sync_with_stdio(0);
    cin >> n >> k >> m;
    for(int i=1;i<=m;i++){
        cin >> a[i];
    }

    // ans = total number of occurrences of A in all sequences of length N
    //     - total number of occurrences of A in all non-colorful sequences of length N

    ll ans = zzpow(k, n-m) * (n - m + 1) % mod;

    // check if A is already colorful
    for(int i=1;i<=m-k+1;i++){
        set <int> s;
        for(int j=i;j<i+k;j++)  s.insert(a[j]);
        if (s.size() == k){
            cout << ans;
            return 0;
        }
    }
    cerr << ans << endl;
    // check if all elements of A are distinct
    set <int> s;
    for(int i=1;i<=m;i++)   s.insert(a[i]);
    if (s.size() == m){
        cerr << "this case\n";
        doDp();

        ll hih = 1;
        for(int i=1;i<=k;i++)   hih = hih * zzpow(i, mod) % mod;
        for(int i=1;i<=k-m;i++) hih = hih * zzpow(i, mod-2) % mod;
        doF(m);

        ll bad = 0;
        for(int i=1;i<k;i++)   bad = (bad + f[n][i]) % mod;
        cerr << bad << endl;
        for(int i=1;i<=k;i++)   bad = bad * zzpow(i, mod-2) % mod;
        for(int i=1;i<=k-m;i++) bad = bad * zzpow(i, 1) % mod;
        bad = bad % mod;
        ans = (ans - bad + mod) % mod;
    }
    else{   // if not
        cerr << "that case\n";
        ll hmm[25005];
        memset(hmm, 0, sizeof(hmm));

        // left
        s.clear();
        for(int i=1;i<=m;i++){
            if (!s.count(a[i]))
                s.insert(a[i]);
            else{
                memset(dp, 0, sizeof (dp));
                doDp(i, i-1);
                for(int j=1;j<=n-m+1;j++){
                    for(int l=1;l<k;l++)
                        hmm[j] = (hmm[j] + dp[i + j-1][l]) % mod;
                }
                break;
            }
        }

        // right
        ll mh[25005];
        memset(mh, 0, sizeof(mh));
        s.clear();
        for(int i=m;i>=1;i--){
            if (!s.count(a[i]))
                s.insert(a[i]);
            else{
                memset(dp, 0, sizeof (dp));
                doDp(m-i+1, m-i);

                for(int j=1;j<=n-m+1;j++){
                    for(int l=1;l<k;l++)
                        mh[j] = (mh[j] + dp[m-i+1 + (n-m-j+1)][l]) % mod;
                }
                break;
            }
        }

        ll bad = 0;
        for(int i=1;i<=n;i++)   bad = (bad + hmm[i] * mh[i]) % mod;
        ans = (ans - bad + mod) % mod;
    }
    cout << ans;
}
