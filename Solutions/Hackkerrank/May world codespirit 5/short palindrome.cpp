#include <bits/stdc++.h>
#define ll long long
#define ff(i,a,b) for(int i=(a);i<=(b);i++)
#define fb(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const ll _M = (ll) 1e6+5;
const ll mod = (ll) 1e9 + 7;
string s;
long long tcd[_M][30];
long long ans,last[30],sum2[30][30],sum1[30][30],truesum[30][30],cnt[30];
ll zzpow(ll x,ll p){
    if (!p) return 1ll;
    ll t = zzpow(x,p/2);
    if(p%2) return t * t % mod * x % mod;
    return t * t % mod;
}
int main(){
    ff(i,0,25)
        last[i] = -1;
    cin >> s;
    s = "0" + s;
    ff(i,1,s.size()-1){
        ff(j,0,25)
            tcd[i][j] = tcd[i-1][j];
        tcd[i][s[i]-'a'] ++;
    }
    ff(i,1,s.size()-1){
        if (last[s[i]-'a'] == -1)
            last[s[i]-'a'] = i,
            cnt[s[i]-'a']++;
        else{
            ff(j,0,25){
                if (j == s[i]-'a') continue;
                ll tmp = 0;
                ll a = tcd[i-1][j] - tcd[last[s[i]-'a']][j];

                sum2[s[i]-'a'][j] = (sum2[s[i]-'a'][j] + 2 * sum1[s[i]-'a'][j] * a % mod + a * a % mod * cnt[s[i]-'a'] % mod) % mod;
                sum1[s[i]-'a'][j] = (sum1[s[i]-'a'][j] + cnt[s[i]-'a'] * a % mod) % mod;

                truesum[s[i]-'a'][j] = (truesum[s[i]-'a'][j] + sum2[s[i]-'a'][j] - sum1[s[i]-'a'][j] + 3*mod) % mod;
            }
            cnt[s[i]-'a']++;
            last[s[i]-'a'] = i;
        }
    }
    ff(i,0,25) ff(j,0,25) ans = (ans + truesum[i][j])%mod;
    ff(j,0,25){
        ff(i,2,(int)tcd[s.size()-1][j] - 2){
            ans = (ans + 1ll * i * (i - 1) % mod * (tcd[s.size()-1][j]-2 - i + 1) % mod)%mod;
        }
    }
    cout << ans * zzpow(2,mod-2) % mod;
}
