#include <bits/stdc++.h>
#define ll long long
using namespace std;
const double pi = acos(-1);
struct point{
    double x,y;
    point(double x=0.0,double y=0.0): x(x), y(y) {}
    double angle(){
        double res = atan2(y,x);
        if (res < 0) res += 2.0*pi;
        return res;
    }
};
struct polygon{
    vector <point> vertices;
    double area(){
        #define zz vertices
        #define I (i+1)%zz.size()
        double res = 0;
        for(int i=0;i<zz.size();i++)
            res += (zz[i].x + zz[I].x) * (zz[i].y - zz[I].y);
        #undef zz
        #undef I
        return max(1.0*res/2.0,- 1.0*res/2.0);
    }
};
struct pointLL{
    ll x,y;
    pointLL(ll x=0,ll y=0): x(x), y(y) {}
};
struct polygonLL{
    vector <pointLL> vertices;
    double area(){
        #define zz vertices
        #define I (i+1)%zz.size()
        ll res = 0;
        for(int i=0;i<zz.size();i++)
            res += (zz[i].x + zz[I].x) * (zz[i].y - zz[I].y);
        #undef zz
        #undef I
        return max(1.0*res/2.0,- 1.0*res/2.0);
    }
};
int n;
polygon a;
point tmp;
int main(){
    #define IN  "area1.in"
    #define OUT "area1.out"
    freopen(IN,"r",stdin);
    freopen(OUT,"w",stdout);
    #undef IN
    #undef OUT
    cout << fixed << setprecision(10);
    //cin >> n;
    n = 3;
    for(int i=0;i<n;i++)
        cin >> tmp.x >> tmp.y,
        a.vertices.push_back(tmp);
    cout << a.area();
}
