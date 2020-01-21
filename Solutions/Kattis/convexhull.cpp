#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
struct point{
    int x,y;
    point(int x=0,int y=0): x(x), y(y) {}
    bool operator == (const point &A){
        return x == A.x && y == A.y;
    }
};
bool cmp(point a,point b){
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}
int ccw(point o,point a,point b){
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}
int n;
point a[10005];
vector <point> ans;
int main(){
    while(scanf("%d",&n) == 1 && n){
        ans.clear();
        for(int i=1;i<=n;i++)
            scanf("%d %d",&a[i].x,&a[i].y);
        sort(a+1,a+n+1,cmp);
        n = unique(a+1,a+n+1) - a - 1;
        #define cnt ans.size()
        for(int i=1;i<=n;i++){
            while(cnt >= 2 && ccw(ans[cnt-2],ans[cnt-1],a[i]) <= 0)
                ans.erase(ans.end()-1);
            ans.push_back(a[i]);
        }
        int old = cnt;
        for(int i=n;i>=1;i--){
            while(cnt >= old+2 && ccw(ans[cnt-2],ans[cnt-1],a[i]) <= 0)
                ans.erase(ans.end()-1);
            ans.push_back(a[i]);
        }
        ans.resize(distance(ans.begin(),unique(ans.begin(),ans.end())));
        if (cnt >= 2 && ans.back() == ans.front())
            ans.erase(ans.end()-1);
        printf("%d\n",cnt);
        for(int i=0;i<cnt;i++)
            printf("%d %d\n",ans[i].x,ans[i].y);
    }
}
