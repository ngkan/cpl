#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair <int,int> ii;
typedef pair <ii,int> iiI;
struct point{
    int x,y;
    point (int x=0,int y=0): x(x), y(y) {}
};
int dis(point a,point b){
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
int n,ans;
point a[305];
vector <iiI> lst;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d %d",&a[i].x,&a[i].y);
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            for(int k=j+1;k<=n;k++){
                int d1 = dis(a[i],a[j]);
                int d2 = dis(a[i],a[k]);
                int d3 = dis(a[j],a[k]);
                iiI tri = iiI(ii(min(d1,min(d2,d3)),d1 + d2 + d3 - min(d1,min(d2,d3)) - max(d1,max(d2,d3))),max(d1,max(d2,d3)));
                lst.push_back(tri);
            }
    sort(lst.begin(),lst.end());
    for(int i=0;i<lst.size();i++){
        int last;
        for(last = i;last < lst.size(); last++)
            if (lst[i] != lst[last]) break;
        last--;
        ans += (last-i) * (last-i+1) / 2;
        i = last;
    }
    printf("%d",ans);
}
