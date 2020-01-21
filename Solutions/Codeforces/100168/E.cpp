#include <bits/stdc++.h>
#define ll long long
using namespace std;
const double pi = acos(-1);
const double eps = 1e-6;
struct point{
    double x,y;
    point(double x=0.0,double y=0.0): x(x), y(y) {}
    point operator + (const point& TMP) const{
        return point(x + TMP.x, y + TMP.y);
    }
    point& operator += (const point& TMP){
        x += TMP.x;
        y += TMP.y;
    }
    point& operator -= (const point& TMP){
        x -= TMP.x;
        y -= TMP.y;
    }
    double angle(){
        double res = atan2(y,x);
        if (res < 0) res += 2.0*pi;
        return res;
    }
};
point point_rotate(point X, double val){
    point TMP = X;
    X.x = TMP.x * cos(val) - TMP.y * sin(val);
    X.y = TMP.x * sin(val) + TMP.y * cos(val);
    return X;
}
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
struct line{
    double a,b,c;
    point head,end;
    line(double a=0.0,double b=0.0,double c=0.0): a(a), b(b), c(c) {}
};
line bisector(point Y,point X,point Z){
    // compute bisector - phan giac cua goc YXZ
    line res;
    Y -= X;
    Z -= X;
    double val = (Y.angle() - Z.angle())/ 2.0;
    res.head = point_rotate(Y, - val) + X;
    res.end = X;
    if (abs(res.head.x - res.end.x) < eps){
        res.a = 1.0;
        res.b = 0.0;
        res.c = -res.head.x;
        return res;
    }
    if (abs(res.head.y - res.end.y) < eps){
        res.a = 0.0;
        res.b = 1.0;
        res.c = -res.head.y;
        return res;
    }
    res.a = (res.head.y - res.end.y) / (res.head.x - res.end.x);
    res.b = -1.0;
    res.c = res.head.y - res.a * res.head.x;
    return res;
}
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
point A,B,C;
line res;
int main(){
    #define IN  "bisector.in"
    #define OUT "bisector.out"
    freopen(IN,"r",stdin);
    freopen(OUT,"w",stdout);
    #undef IN
    #undef OUT
    cout << fixed << setprecision(10);
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
    res = bisector(B,A,C);
    cout << res.a << ' ' << res.b << ' ' << res.c;
}
