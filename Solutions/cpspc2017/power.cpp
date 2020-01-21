#pragma GCC optimize("O3")

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int read_int(){
    char c;
    bool check = 0;
    int res = 0;
    while(1){
        c = getchar();
        if (c == '-') {check = 1; continue;}
        if (c == ' ' || c == '\n') break;
        res = res*10 + c - '0';
    }
    if (check) return -res;
    return res;
}
struct point{
    int x,y;
    point(int x=0,int y=0): x(x), y(y) {}
};
int n;
point a[100005];
ll dist(point p,point q){
    return 1ll * (p.x - q.x) * (p.x - q.x) + 1ll* (p.y - q.y) * (p.y - q.y);
}
// k-d tree
int kd_root;
int child_l[100005], child_r[100005];
bool cmp_x_axis(int x,int y){
    return a[x].x < a[y].x;
}
bool cmp_y_axis(int x,int y){
    return a[x].y < a[y].y;
}
int build_kd(int layer,vector <int> &v,int L,int R){
    int pivot = rand() % (R-L) + L;

    if (layer == 0) nth_element(v.begin() + L, v.begin() + pivot, v.begin() + R, cmp_x_axis);
    else            nth_element(v.begin() + L, v.begin() + pivot, v.begin() + R, cmp_y_axis);

    child_l[v[pivot]] = L   < pivot ? build_kd(layer ^ 1, v, L,   pivot) : -1;
    child_r[v[pivot]] = pivot+1 < R ? build_kd(layer ^ 1, v, pivot+1, R) : -1;
    return v[pivot];
}

int cnt = 0;
void kd_count(int id,bool depth,int x0,int x1,int y0,int y1,point center,ll radius,int mini_rad,int *v,int &vsz){
    if (dist(a[id], center) <= radius)
        v[++vsz] = id;
    cnt++;
    if (vsz > 6)    return;
    if (center.x - mini_rad > x1)   return;
    if (x0 > center.x + mini_rad)   return;
    if (center.y - mini_rad > y1)   return;
    if (y0 > center.y + mini_rad)   return;

    if (depth == 0){
        if (child_l[id] != -1)  kd_count(child_l[id], 1, x0, a[id].x, y0, y1, center, radius, mini_rad, v, vsz);
        if (vsz > 6)    return;
        if (child_r[id] != -1)  kd_count(child_r[id], 1, a[id].x, x1, y0, y1, center, radius, mini_rad, v, vsz);
    }
    else{
        if (child_l[id] != -1)  kd_count(child_l[id], 0, x0, x1, y0, a[id].y, center, radius, mini_rad, v, vsz);
        if (vsz > 6)    return;
        if (child_r[id] != -1)  kd_count(child_r[id], 0, x0, x1, a[id].y, y1, center, radius, mini_rad, v, vsz);
    }
}

void prep(){
    vector <int> lst;
    for(int i=1;i<=n;i++)   lst.push_back(i);
    kd_root = build_kd(0, lst, 0, n);
}

int color[100005];
int adj[100005], adjsz;
int q[100005], ql, qr;
int mjk = 0;
bool check(ll val){
    for(int i=0;i<=n;++i)   color[i] = -1;
    int mini_rad = (int)sqrt(val);

    for(int i=1;i<=n;++i){
        //if (i%10000 == 0) cout << i << endl;
        if (color[i] != -1)   continue;
        color[i] = 0;
        ql = qr = 0;
        q[qr++] = i;
        while(ql<qr){
            int u = q[ql++];
            adjsz = 0;
            cnt = 0;
            #define M 1000000000
            kd_count(kd_root, 0, -M, M, -M, M, a[u], val, mini_rad, adj, adjsz);
            #undef M
            mjk = max(mjk, cnt);
            if (adjsz > 6)  return 0;
            //cout << mjk << endl;
            for(int j=1;j<=adjsz;++j){
                int v = adj[j];
                if (v == u) continue;

                if (color[v] == -1)
                    color[v] = color[u] ^ 1,
                    q[qr++] = v;
                else if (color[v] == color[u])  return 0;
            }
        }
    }
    return 1;
}
signed main(){
    freopen("03.d.in","r",stdin);
    srand(time(NULL));
    n = read_int();
    for(int i=1;i<=n;++i)   a[i].x = read_int(), a[i].y = read_int();
    prep();
    check(100);
    /*
    ll L = 0, R = (ll) 1e18+1;
    while(L+1 < R){
        cout << L << ' ' << R << endl;
        ll mid = (L+R)/2;
        if (check(mid)) L = mid;
        else R = mid;
    }
    /*
    check(L);
    printf("%lld\n",R);
    vector <int> l0, l1;
    for(int i=1;i<=n;++i)   if (!color[i]) l0.push_back(i); else l1.push_back(i);
    printf("%d\n",(int)l0.size());
    for(int i=0;i<l0.size();++i) printf("%d ",l0[i]);   printf("\n");
    printf("%d\n",(int)l1.size());
    for(int i=0;i<l1.size();++i) printf("%d ",l1[i]);
    */
}
