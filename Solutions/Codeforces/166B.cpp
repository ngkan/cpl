#include <bits/stdc++.h>
using namespace std;
struct point{
    int x,y;
    point (int _x = 0,int _y= 0): x(_x),y(_y) {}    // constructor
};
int ccw(point a,point b,point c){
    b.x -= a.x; b.y -= a.y;
    c.x -= a.x; c.y -= a.y;
    long long tmp = 1ll * b.x * c.y - 1ll* b.y * c.x;
    if (tmp > 0) return 1;
    if (tmp == 0) return 0;
    return -1;
}
void ans(bool x){
    if (!x) printf("NO");
    else printf("YES");
    exit(0);
}
int n,m;
vector <point> a,baotren,baoduoi;
int lu,ld,ru,rd;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        a.push_back(point(x,y));
    }
    for(int i=0;i<a.size();i++){
        if (a[lu].x > a[i].x) lu = i;
        else if (a[lu].x == a[i].x && a[lu].y < a[i].y) lu = i;
        if (a[ld].x > a[i].x) ld = i;
        else if (a[ld].x == a[i].x && a[ld].y > a[i].y) ld = i;
        if (a[ru].x < a[i].x) ru = i;
        else if (a[ru].x == a[i].x && a[ru].y < a[i].y) ru = i;
        if (a[rd].x < a[i].x) rd = i;
        else if (a[rd].x == a[i].x && a[rd].y > a[i].y) rd = i;
    }
    for(int i=lu;;i++){
        baotren.push_back(a[i%n]);
        if (i%n == ru) break;
    }
    for(int i=ld;;i--){
        baoduoi.push_back(a[(i+n)%n]);
        if ((i+n)%n == rd) break;
    }
    scanf("%d",&m);
    while(m--){
        int x,y,l,r;
        scanf("%d %d",&x,&y);
        point tmp = point(x,y);
        if (tmp.x <= baotren[0].x || tmp.x >= baotren[baotren.size()-1].x) ans(0);
        l = 0,r = baotren.size() - 1;
        while (l <= r){
            if (r-l<=1){
                if (baotren[r].x <= tmp.x) l = r;
                break;
            }
            int mid = (l+r)/2;
            if (baotren[mid].x <= tmp.x) l = mid;
            else r = mid;
        }
        if (ccw(baotren[l],baotren[l+1],tmp) != -1) ans(0);
        l = 0, r = baoduoi.size() - 1;
        while (l <= r){
            if (r-l<=1){
                if (baoduoi[r].x <= tmp.x) l = r;
                break;
            }
            int mid = (l+r)/2;
            if (baoduoi[mid].x <= tmp.x) r = mid;
            else l = mid;
        }
        if (ccw(baoduoi[l],baoduoi[l+1],tmp) != 1) ans(0);
    }
    ans(1);
}
