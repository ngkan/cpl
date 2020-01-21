#include <iostream>
#include <algorithm>
#include <utility>
#define pos first
#define val second
#include <cmath>
#include <vector>
#include <stdio.h>
using namespace std;
const double pi = acos(-1);
const double eps = 1e-9;
typedef pair<double,int> di;
struct point{
    double x,y;
    point(double x=0.0,double y=0.0): x(x), y(y) {}
    point operator + (const point& TMP) const{
        return point(x + TMP.x, y + TMP.y);
    }
    point operator - (const point& TMP) const{
        return point(x - TMP.x, y - TMP.y);
    }
    point& operator += (const point& TMP){
        x += TMP.x;
        y += TMP.y;
        return *this;
    }
    point& operator -= (const point& TMP){
        x -= TMP.x;
        y -= TMP.y;
        return *this;
    }
    void in(){
        cin >> x >> y;
    }
    double angle(point ROOT = point(0.0,0.0)){
        double res = atan2(y-ROOT.y,x-ROOT.x);
        if (res <= -eps) res += 2.0*pi;
        return res;
    }
};
double dis(point X,point Y){
    return sqrt((X.x - Y.x) * (X.x - Y.x) + (X.y - Y.y)*(X.y - Y.y));
}
int n,ans;
double R = 1.0;
point a[1005];
vector <di> list;
bool cmp(di x,di y){
    if (abs(x.pos - y.pos) < eps) return x.val < y.val;
    return x.pos < y.pos;
}
int main(){
    iostream::sync_with_stdio(0);
    while(cin >> n && n){
        ans = 1;
        for(int i=1;i<=n;i++) a[i].in();
        for(int i=1;i<=n;i++){
            list.clear();
            point ROOT = a[i];
            for(int j=1;j<=n;j++){
                if (j == i) continue;
                double d = dis(a[j],ROOT);
                if (d >= 2.0*R + eps) continue;
                double va = acos(d/2.0/R);
                double angle = a[j].angle(ROOT);
                double x1 = angle - va;
                double x2 = angle + va;
                if (x1 <= -eps)
                    list.push_back(di(x1+2.0*pi,1)),
                    list.push_back(di(2.0*pi,-1)),
                    list.push_back(di(0,1)),
                    list.push_back(di(x2+eps,-1));
                else if (2.0*pi <= x2)
                    list.push_back(di(x1,1)),
                    list.push_back(di(2.0*pi,-1)),
                    list.push_back(di(0,1)),
                    list.push_back(di(x2-2.0*pi+eps,-1));
                else
                    list.push_back(di(x1,1)),
                    list.push_back(di(x2+eps,-1));
            }
            sort(list.begin(),list.end(),cmp);
            int tmp = 0;
            for(int j=0;j<list.size();j++){
                tmp += list[j].val;
                ans = max(ans,tmp+1);
            }
        }
        cout << ans << endl;
    }
}
