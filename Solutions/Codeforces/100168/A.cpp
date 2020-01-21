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
    #define IN  "angle1.in"
    #define OUT "angle1.out"
    freopen(IN,"r",stdin);
    freopen(OUT,"w",stdout);
    #undef IN
    #undef OUT
    cout << fixed << setprecision(10);
    point a;
    cin >> a.x >> a.y;
    cout << a.angle();
}
