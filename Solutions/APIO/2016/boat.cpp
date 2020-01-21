#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = (ll) 1e9+7;
int n, a[505], b[505];
ll f[505][3005];
ll g[505];
ll fact[505], inv[505];
ll Ckn(int x,int y){
    return fact[y] * inv[x] % mod * inv[y-x] % mod;
}
ll mod_inverse(ll a){
    ll r1 = a, r2 = mod, x1 = 1,x2 = 0, q, tmp;
    while(r2 != 0){
        q = r1 / r2;
        tmp = x1 -  q * x2;
        x1 = x2;
        x2 = tmp;
        tmp = r1 % r2;
        r1 = r2;
        r2 = tmp;
    }
    return (x1+mod)%mod;
}
int main(){
    fact[0] = 1;
    for(int i=1;i<=500;i++)
        fact[i] = fact[i-1] * i % mod;
    for(int i=0;i<=500;i++)
        inv[i] = mod_inverse(fact[i]);

    iostream::sync_with_stdio(0);
    cin >> n;
    vector <int> lst;
    for(int i=1;i<=n;i++)
        cin >> a[i] >> b[i],
        lst.push_back(a[i]),
        lst.push_back(b[i]);
    sort(lst.begin(), lst.end());
    lst.resize(unique(lst.begin(),lst.end()) - lst.begin());
    vector <pair<int,int> > rangeTmp;
    for(int i=0;i<lst.size();i++){
        rangeTmp.push_back({lst[i], lst[i]});
        if (i != lst.size() - 1 && lst[i]+1 <= lst[i+1]-1)
            rangeTmp.push_back({lst[i]+1, lst[i+1]-1});
    }

    rangeTmp.insert(rangeTmp.begin(), {-1,-1});
    pair<int,int> range[3004];
    for(int i=0;i<rangeTmp.size();i++)
        range[i] = rangeTmp[i];
    g[0] = 1;

    for(int j = 1;j < rangeTmp.size();j ++){
        // f[i][j] = cnt of way that end at i and value of i in range j
        // g[i] = sum(f[i][0] -> f[i][j-1])

        int len = range[j].second - range[j].first + 1;
        ll arr[505], sumG[505];
        arr[0] = 1;
        sumG[0] = g[0];
        for(int i=1;i<=n;i++)
            sumG[i] = (sumG[i-1] + g[i]) % mod,
            arr[i] = arr[i-1] * (len+1-i) % mod;

        ll numberOfWayToChoose[505];
        numberOfWayToChoose[0] = 1;
        numberOfWayToChoose[1] = arr[1];

        int mjk=0;
        for(int i=1;i<=n;i++) mjk += (a[i] <= range[j].first && range[j].second <= b[i]);

        for(int possiBoat=2;possiBoat<=mjk;possiBoat++){
            numberOfWayToChoose[possiBoat] = 0;
            for(int k=2;k<=min(possiBoat, len);k++)
                numberOfWayToChoose[possiBoat] = (numberOfWayToChoose[possiBoat] + Ckn(k-2, possiBoat-2) * arr[k] % mod * inv[k]) % mod;
        }

        for(int i=1;i<=n;i++){
            if (!(a[i] <= range[j].first && range[j].second <= b[i]))    continue;
            int possiBoat = 0;
            for(int ii=i;ii>=1;ii--){
                if (!(a[ii] <= range[j].first && range[j].second <= b[ii]))  continue;
                possiBoat++;
                f[i][j] = (f[i][j] + sumG[ii-1] * numberOfWayToChoose[possiBoat]) % mod;
            }
        }
        for(int i=0;i<=n;i++){
            g[i] = (g[i] + f[i][j]) % mod;
        }
    }

    ll ans = 0;
    for(int i=1;i<=n;i++)
        ans = (ans+ g[i]) % mod;
    cout << ans;
}

