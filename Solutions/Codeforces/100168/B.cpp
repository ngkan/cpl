#include <bits/stdc++.h>
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
int main(){
    #define IN  "angle2.in"
    #define OUT "angle2.out"
    freopen(IN,"r",stdin);
    freopen(OUT,"w",stdout);
    #undef IN
    #undef OUT
    cout << fixed << setprecision(10);
    point a,b;
    cin >> a.x >> a.y >> b.x >> b.y;
    double res = max(a.angle(),b.angle()) - min(a.angle(),b.angle());
    if (res > pi) res = 2.0*pi - res;
    cout << res;
}
