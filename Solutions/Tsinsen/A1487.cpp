#include <bits/stdc++.h>
using namespace std;
struct fw_tree{
    int node[400005];
    void reset(){
        for(int i=0;i<=400000;i++)  node[i] = 0;
    }
    void upd(int pos,int val){
        for(;pos<=400000;pos+=pos&-pos) node[pos] += val;
    }
    int get(int pos){
        int res = 0;
        for(;pos;pos-=pos&-pos) res += node[pos];
        return res;
    }
};
struct point{
    int x, y, z,id, type;
    // type = 0 = ask
    // type = 1 = count
    point(int x=0,int y=0,int id=0,int type=0): x(x), y(y), id(id), type(type) {}
};
bool cmp_point0(point a,point b){
    if (a.z != b.z) return a.z > b.z;
    return a.type < b.type;
}
bool cmp_point1(point a,point b){
    if (a.z != b.z) return a.z < b.z;
    return a.type < b.type;
}

point a[100005], b[100005];
int n, m, tmp;
int ans[100005];
vector <point> event;
vector <int> compress;
fw_tree fw_x, fw_y;

int main(){
    // input
    iostream::sync_with_stdio(0);
    cin >> tmp >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i].x >> a[i].y >> a[i].z;
        a[i].id = i;
        a[i].type = 1;
        compress.push_back(a[i].x);
        compress.push_back(a[i].y);
    }
    for(int i=1;i<=m;i++){
        cin >> b[i].x >> b[i].y >> b[i].z;
        b[i].id = i;
        b[i].type = 0;
        compress.push_back(b[i].x);
        compress.push_back(b[i].y);
    }

    // pre-process
    //  // compressing
        sort(compress.begin(), compress.end());
        compress.resize(unique(compress.begin(),compress.end()) - compress.begin());
        for(int i=1;i<=n;i++){
            a[i].x = lower_bound(compress.begin(), compress.end(), a[i].x) - compress.begin() + 1;
            a[i].y = lower_bound(compress.begin(), compress.end(), a[i].y) - compress.begin() + 1;
        }
        for(int i=1;i<=m;i++){
            b[i].x = lower_bound(compress.begin(), compress.end(), b[i].x) - compress.begin() + 1;
            b[i].y = lower_bound(compress.begin(), compress.end(), b[i].y) - compress.begin() + 1;
        }
    //  // event
        for(int i=1;i<=n;i++)
            event.push_back(a[i]);
        for(int i=1;i<=m;i++)
            event.push_back(b[i]);

    int seen_point;
    // first sweep
    seen_point = 0;
    sort(event.begin(), event.end(), cmp_point0);
    for(int l=0;l<(int)event.size();l++){
        int r = l;
        for(;r<(int)event.size();r++)   if (event[l].z  != event[r].z || event[l].type != event[r].type)    break; r--;
        if (event[l].type == 0){
            // query
            for(int i=l;i<=r;i++){
                ans[event[i].id] += seen_point - (fw_x.get(400000) - fw_x.get(event[i].x-1)) - (fw_y.get(400000) - fw_y.get(event[i].y-1));
            }
        }
        else{
            for(int i=l;i<=r;i++){
                ++seen_point;
                fw_x.upd(event[i].x, 1);
                fw_y.upd(event[i].y, 1);
            }
        }
        l = r;
    }

    // second sweep
    // don't need seen_point
    sort(event.begin(), event.end(), cmp_point1);
    fw_x.reset();
    fw_y.reset();
    for(int l=0;l<(int)event.size();l++){
        int r = l;
        for(;r<(int)event.size();r++)   if (event[l].z  != event[r].z || event[l].type != event[r].type)    break; r--;
        if (event[l].type == 0){
            // query
            for(int i=l;i<=r;i++){
                ans[event[i].id] += fw_x.get(event[i].x - 1) + fw_y.get(event[i].y - 1);
            }
        }
        else{
            for(int i=l;i<=r;i++){
                fw_x.upd(event[i].x, 1);
                fw_y.upd(event[i].y, 1);
            }
        }
        l = r;
    }

    // final
    for(int i=1;i<=m;i++)
        printf("%d\n", ans[i]);
}
