#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
ll read_ll(){
    char c;
    ll res = 0;
    bool check = 0;
    while(1){
        c = getchar();
        if (c == '-') {check = 1; continue;}
        if (c == ' ' || c == '\n') break;
        res = res * 10ll + (ll) c - '0';
    }
    if (check) return -res;
    return res;
}
struct point{
    ll x,y;
    point(ll x = 0.0,ll y = 0.0): x(x), y(y) {}
};
bool cmp(point x,point y){
    return x.y < y.y;
}
ll dist(point a,point b){
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
ll n,tmp;
vector <point> a,b;
ll solve(ll l,ll r){
    if (l == r) return (1ll<<60);
    if (l == r-1) return dist(a[l],a[r]);
    ll mid = (l+r)/2;
    ll d0 = min(solve(l,mid), solve(mid+1,r));
    ll L = (1ll<<60), R = -(1ll<<60);
    b.clear();
    for(ll i=l;i<=r;i++)
        if (a[mid].x - d0 <= a[i].x && a[i].x <= a[mid].x + d0) b.push_back(a[i]);
    sort(b.begin(), b.end(), cmp);
    for(ll i=0;i<(ll) b.size();i++){
        for(ll j=i+1;j<min((ll)b.size(),i+8);j++)
            d0 = min(d0, dist(b[i],b[j]));
    }
    return d0;
}
int main(){
    n = read_ll();
    for(ll i=1;i<=n;i++)
        tmp += read_ll(), a.push_back(point(i,tmp));
    printf("%lld",solve(0,n-1));
}
