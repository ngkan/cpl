#include <stdio.h>
#include <utility>
#include <set>
#include <algorithm>
#include <assert.h>
using namespace std;
typedef pair<int,int> ii;
#define fi first
#define se second
int n;
int x[500005], y[500005], r[500005];
ii a[1000005];
bool cmp(ii id1,ii id2){
    int val1 = x[id1.fi] + id1.se * r[id1.fi];
    int val2 = x[id2.fi] + id2.se * r[id2.fi];
    if (val1 != val2) return val1 < val2;
    return id1.se < id2.se;
}
bool check(int id1,int id2){
    return 1ll * (x[id1] - x[id2]) * (x[id1] - x[id2])
    + 1ll * (y[id1] - y[id2]) * (y[id1] - y[id2])
    == 1ll * (r[id1] + r[id2]) * (r[id1] + r[id2]);
}
set <ii> s;
set <ii> chk;
int ans = 0;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        a[2*i-1] = ii(i,-1),
        a[2*i]   = ii(i, 1),
        scanf("%d %d %d",&x[i],&y[i],&r[i]);
    sort(a+1,a+2*n+1,cmp);
    for(int i=1;i<=2*n;i++){
        set<ii>::iterator it0, it1;
        if (a[i].se == -1){
            it0 = it1 = s.lower_bound(ii(y[a[i].fi], a[i].fi));
            if (it1 != s.end()){
                if (!chk.count(ii(a[i].fi, (*it1).se)) && !chk.count(ii((*it1).se,a[i].fi)))
                    chk.insert(ii(a[i].fi, (*it1).se)),
                    ans += check(a[i].fi, (*it1).se);
            }
            if (it0 != s.begin()){
                it0 --;
                if (!chk.count(ii(a[i].fi, (*it0).se)) && !chk.count(ii((*it0).se,a[i].fi)))
                    chk.insert(ii(a[i].fi, (*it0).se)),
                    ans += check(a[i].fi, (*it0).se);
            }
            s.insert(ii(y[a[i].fi], a[i].fi));
        }
        else{
            it0 = it1 = s.lower_bound(ii(y[a[i].fi], a[i].fi));
            it1++;
            if (it0 != s.begin() && it1 != s.end()){
                it0--;
                if (!chk.count(ii((*it0).se,(*it1).se)) && !chk.count(ii((*it1).se,(*it0).se)))
                    chk.insert(ii((*it0).se,(*it1).se)),
                    ans += check((*it0).se,(*it1).se);
            }
            s.erase(ii(y[a[i].fi], a[i].fi));
        }
    }
    printf("%d",ans);
}
