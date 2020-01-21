#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
typedef pair<ll,ll> ii;
set <ii> s;
ll t,n,q,sum[100005];
ii a[100005];
int main(){
    scanf("%lld",&t);
    while(t--){
        s.clear();
        scanf("%lld %lld",&n,&q);
        for(int i=1;i<=n;i++)   scanf("%lld",&a[i].fi), a[i].se = i;
        sort(a+1,a+n+1,greater<ii>());
        s.insert(ii(1,n));
        for(int i=1;i<=n;i++){
            set<ii>::iterator it;
            it = s.upper_bound(ii(a[i].se,(1ll<<60))); --it;
            ii ahi = *it;
            s.erase(it);
            sum[i] = sum[i-1] + (a[i].se - ahi.fi + 1) * (ahi.se - a[i].se + 1);
            if (ahi.fi < a[i].se) s.insert(ii(ahi.fi,a[i].se - 1));
            if (a[i].se < ahi.se) s.insert(ii(a[i].se + 1,ahi.se));
        }
        for(int i=1;i<=q;i++){
            ll x;
            scanf("%lld",&x);
            ll l = 0, r = n;
            while(l+1 < r){
                ll mid = (l+r)/2;
                if (sum[mid] < x) l = mid;
                else r = mid;
            }
            printf("%lld\n",a[r].fi);
        }
    }
}
