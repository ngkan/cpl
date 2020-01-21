#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct point{
    int x,y,id;
    point(int x=0,int y=0,int id=0): x(x), y(y), id(id) {}
};
int n;
point a[100005];
point b[100005];
ll dist(point p,point q){
    return 1ll * (p.x - q.x) * (p.x - q.x) + 1ll* (p.y - q.y) * (p.y - q.y);
}
int mini_rad;
bool cmp_b(point x,point y){
    return x.x == y.x  ?   x.y < y.y : x.x < y.x;
}
int color[100005];
bool ok;
vector <int> G[100005];
void dfs(int u){
    for(int i=0;i<G[u].size();i++){
        if (!ok)    return;
        int v = G[u][i];

        if (color[v] == -1)
            color[v] = color[u] ^ 1,
            dfs(v);
        else if (color[v] == color[u]) {ok = 0; return;}
    }
}
bool check(ll val){
    for(int i=0;i<=n;++i)   color[i] = -1, G[i].clear();
    ok = 1;
    mini_rad = (int)sqrt(val);
    for(int i=1;i<=n;i++){
        b[i].x = a[i].x / mini_rad;
        b[i].y = a[i].y / mini_rad;
        b[i].id = i;
    }
    sort(b+1,b+n+1,cmp_b);

    int cnt = 0;
    for(int i=1;i<=n;i++){
        if (i != 1 && b[i].x == b[i-1].x && b[i].y == b[i-1].y)
            ++cnt;
        else cnt = 1;
        if (cnt > 6)    return 0;   // dirichlet
    }

    for(int i=1;i<=n;i++){
        for(int X = b[i].x - 1; X <= b[i].x + 1; X++){
            for(int Y = b[i].y - 1; Y <= b[i].y - 1; Y++){
                int L = 0, R = n;
                while(L+1 < R){
                    int mid = (L+R)/2;
                    if (b[mid].x != X){
                        if (b[mid].x >= X) R = mid;
                        else L = mid;
                    }
                    else{
                        if (b[mid].y >= Y) R = mid;
                        else L = mid;
                    }
                }

                int pos = R;

                for(;pos<=n;pos++){
                    if (b[pos].x == X && b[pos].y <= Y+2){
                        if (b[pos].id != b[i].id && dist(a[b[i].id], a[b[pos].id]) <= val)
                            G[b[i].id].push_back(b[pos].id);
                    }
                    else break;
                }

            }
        }
    }

    for(int i=1;i<=n;i++){
        if (color[i] == -1) color[i] = 0, dfs(i);
        if (!ok) return ok;
    }

    return ok;
}
signed main(){
    freopen("03.d.in","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d %d",&a[i].x,&a[i].y);

    ll L = 0, R = (ll)1e18+1;
    while(L+1 < R){
        cout << L << ' ' << R << endl;
        ll mid = (L+R)/2;
        if (check(mid)) L = mid;
        else R = mid;
    }
    /*
    check(L);
    cout << R << endl;
    vector <int> l0, l1;
    for(int i=1;i<=n;i++)   if (!color[i]) l0.push_back(i); else l1.push_back(i);
    cout << l0.size() << endl;
    for(int i=0;i<l0.size();i++) cout << l0[i] << ' '; cout << endl;
    cout << l1.size() << endl;
    for(int i=0;i<l1.size();i++) cout << l1[i] << ' ';
    */
}

