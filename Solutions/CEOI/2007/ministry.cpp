#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = (ll) 1e9+9;
const ll base =  1409ll;
const ll base2 = (ll) 4109;
char s[2000005];
ll n,cnt,h[1000005],val[1000005];
vector <ll> G[1000005];
stack<ll> st;
set<ll> ax[1000005];
ll zzpow(ll x,ll p){
    if (!p) return 1ll;
    ll t = zzpow(x,p/2);
    if (p%2) return t*t%mod*x%mod;
    return t*t%mod;
}
int main(){
    freopen("5.in","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%s",s);
    n=strlen(s)/2;
    for(int i=0;i<2*n;i++){
        if (s[i] == '(') st.push(++cnt);
        else{
            int u = st.top(); st.pop();
            if (st.size()) G[st.top()].push_back(u);
            h[u] = 1;
            //cout << u << endl;
            vector <ll> ez;
            for(int i=0;i<G[u].size();i++){
                h[u] = max(h[u], h[G[u][i]] + 1);
                ez.push_back(val[G[u][i]]);
            }
            sort(ez.begin(),ez.end());
            ll axx = 1;
            for(int i=0;i<ez.size();i++){
                ll b = 1;
                if (i >= 1) b *= base;
                if (i >= 2) b *= base;
                //b%=mod;
                val[u] = (val[u] + b * ez[i]) % mod;
                axx = axx * ez[i] % mod;
            }
           // cout << u << ' ' << h[u] << endl;
            val[u] = (val[u] * zzpow(base2,h[u]-1) + axx ) % mod;
            ax[h[u]].insert(val[u]);
        }
    }
    for(int i=1;i<=h[1];i++) cout << ax[i].size() << endl;
}
