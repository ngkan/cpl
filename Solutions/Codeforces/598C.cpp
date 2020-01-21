#include <bits/stdc++.h>
#define fi first
#define se second
const long double pi = 3.14159265359;
using namespace std;
int n,x,y,ans1,ans2;
long double ans = 1000;
vector < pair<long double,int> > a;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&x,&y);
        if (atan2(y,x) >= 0) a.push_back(pair<long double,int>(atan2(y,x) ,i));
        else a.push_back(pair<long double,int>(atan2(y,x) + 2*pi,i));
    }
    sort(a.begin(),a.end());
    a.push_back(pair<long double,int>(a[0].fi + 2*pi, a[0].se));
    for(int i=0;i<n;i++){
        if (min(a[i+1].fi - a[i].fi,2*pi - a[i+1].fi + a[i].fi) < ans)
            ans = min(a[i+1].fi - a[i].fi, 2*pi - a[i+1].fi + a[i].fi),
            ans1 = a[i].se,
            ans2 = a[i+1].se;
    }
    cout << ans1 << ' ' << ans2;
}
