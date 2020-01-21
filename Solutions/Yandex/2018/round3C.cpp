#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll,ll> bishop;
typedef pair<ll,ll> ii;
ll n, lim;
bishop a[200005];
vector <bishop> mjk, mjk2;
long long check(vector <bishop> &lst){
    vector <ii> query;
    for(auto v:lst){
        // cut
        query.push_back(ii(v.first - v.second, -1));
        query.push_back(ii(v.first - v.second + 2ll * lim, 1));
        query.push_back(ii(v.first + v.second, 3));
    }
    sort(query.begin(), query.end());
    ll cnt = 0;
    ll res = 0;
    for(auto v: query){
        if (v.second != 3)
            cnt -= v.second;
        else
            res += cnt;
    }
    return res;
}
int main(){
    iostream::sync_with_stdio(0);
    cin >> n >> lim;
    for(int i=1;i<=n;i++){
        cin >> a[i].first >> a[i].second;
        if (abs(a[i].first + a[i].second)%2 == 0)
            mjk.push_back(a[i]);
        else
            mjk2.push_back(a[i]);
    }
    long long ans = 1ll * n * (2ll*lim-1);
    ans -= check(mjk);
    cerr << ans << endl;
    ans -= check(mjk2);
    cout << ans;
}
