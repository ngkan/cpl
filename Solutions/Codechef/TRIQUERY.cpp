#include <bits/stdc++.h>
using namespace std;
struct point{
    int x,y;
    point (int x=0,int y=0): x(x), y(y) {}
};
struct query{
    int x,y,d,id;
    query (int x=0,int y=0,int d=0,int id=0): x(x), y(y), d(d), id(id) {}
};
bool cmp1(query a,query b){
    return a.x + a.y + a.d < b.x + b.y + b.d;
}
bool cmp2(query a,query b){
    return a.x + a.y < b.x + b.y;
}
int n,m,sweep,total,ans[300005];
int fw[3][300005];  // 1 = left 2 = down
void fw_upd(int type,int pos,int val){
    for(;pos<=300000;pos+=pos&-pos) fw[type][pos] += val;
}
int fw_get(int type,int pos){
    if (!pos) return 0;
    int res = 0;
    for(;pos;pos-=pos&-pos) res += fw[type][pos];
    return res;
}
query q[200005];
vector <point> line[1000005];
int main(){
    freopen("test.inp","r",stdin);
    freopen("ans.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        line[x+y].push_back(point(x,y));
    }
    for(int i=1;i<=m;i++)
        scanf("%d %d %d",&q[i].x,&q[i].y,&q[i].d), q[i].id = i;
    sweep = total = 0;
    sort(q+1,q+m+1,cmp1);
    for(int i=1;i<=m;i++){
        while(sweep < q[i].x + q[i].y + q[i].d){
            ++sweep;
            for(int j=0;j<line[sweep].size();j++)
                ++total,
                fw_upd(1,line[sweep][j].x,1),
                fw_upd(2,line[sweep][j].y,1);
        }
        ans[q[i].id] += total - fw_get(1,q[i].x-1) - fw_get(2,q[i].y-1);
    }
    sweep = total = 0;  for(int i=1;i<=300000;i++) fw[1][i] = fw[2][i] = 0;
    sort(q+1,q+m+1,cmp2);
    for(int i=1;i<=m;i++){
        while(sweep < q[i].x + q[i].y - 2){
            ++sweep;
            for(int j=0;j<line[sweep].size();j++)
                ++total,
                fw_upd(1,line[sweep][j].x,1),
                fw_upd(2,line[sweep][j].y,1);
        }
        ans[q[i].id] += fw_get(1,q[i].x-1) + fw_get(2,q[i].y-1) - total;
    }
    for(int i=1;i<=m;i++)
        printf("%d\n",ans[i]);
}
/*
8 3
3 1
1 3
2 2
2 3
3 2
1 2
2 1
1 1
1 1 2
2 2 1
1 2 1
*/
