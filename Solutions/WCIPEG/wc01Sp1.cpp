#include <bits/stdc++.h>
using namespace std;
struct point{
    int x,y;
};
point mk(int a,int b){
    point t;
    t.x = a;
    t.y = b;
    return t;
}
int n;
char s[105][105],type;
vector <point> a;
bool inside(point x){
    return !(x.x >= n || x.y >= n || x.x < 0 || x.y < 0);
}
int area(point x,point y){
    return (x.x - y.x) * (x.x - y.x) + (x.y - y.y) * (x.y - y.y);
}
void deb(point& x){
    cout << x.x << ' ' << x.y << endl;
}
bool check(point x,point y){
    if (!inside(x) || !inside(y)) return 0;
    if (s[x.y][x.x] == type && s[y.y][y.x] == '*') return 1;
    if (s[x.y][x.x] == type && s[y.y][y.x] == type) return 1;
    if (s[x.y][x.x] == '*' && s[y.y][y.x] == type) return 1;
    return 0;
}
int query(point a,point b){
    int nx1 = b.x - a.x, ny1 = b.y - a.y;
    int nx2 = a.x - b.x, ny2 = a.y - b.y;
    point q = mk(a.x - ny1,a.y + nx1);  //deb(q);
    point w = mk(b.x + ny2,b.y - nx2);  //deb(w);
    point e = mk(a.x + ny1,a.y - nx1);  //deb(e);
    point r = mk(b.x - ny2,b.y + nx2);  //deb(r);
    //cout << area(a,b) << endl;
    if (check(q,w)) return area(a,b);
    if (check(e,r)) return area(a,b);
    return 0;
}
int main(){
    iostream::sync_with_stdio(0);
    while(cin >> n){
        if (n == -1) break;
        a.clear();
        int ans = 0;
        for(int i=n-1;i>=0;i--)
            cin >> s[i];
        cin >> type;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if (s[i][j] == type) a.push_back(mk(j,i));
        for(int i=0;i<a.size();i++)
            for(int j=i+1;j<a.size();j++)
                //cout << a[i].x << ' ' << a[i].y << ' ' << a[j].x << ' ' << a[j].y << endl,
                //cout << area(a[i],a[j]) << endl,
                ans = max(ans,query(a[i],a[j]));
        cout << ans << endl;
    }
}
/*
4
**k*
k***
***k
****
k
-1
*/
