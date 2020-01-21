#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int N = (int) 1e5+5;
struct edge{
    int u,v,w;
    edge(int u=0,int v=0,int w=0): u(u), v(v), w(w) {}
};
bool cmp(edge x,edge y){
    return x.w < y.w;
}
int dsup[N], dsusize[N];
int dsu_p(int x){
    return dsup[x] == x ? x : dsup[x] = dsu_p(dsup[x]);
}
void dsu_union(int x,int y){
    if (dsu_p(x) == dsu_p(y)) return;
    dsusize[dsu_p(x)] += dsusize[dsu_p(y)];
    dsup[dsu_p(y)] = dsu_p(x);
}
int n;
vector <edge> a;
double res;
int main(){
    for(int i=1;i<N;i++) dsup[i] = i, dsusize[i] = 1;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        a.push_back(edge(u,v,w));
    }
    sort(a.begin(),a.end(),cmp);
    for(int i=0;i<a.size();i++){
        res += 1.0 * a[i].w * dsusize[dsu_p(a[i].u)] * dsusize[dsu_p(a[i].v)];
        dsu_union(a[i].u,a[i].v);
    }
    res /= (1.0 * n * (n-1) / 2);
    for(int i=0;i<a.size();i++)
        res -= 1.0 * a[i].w;
    printf("%lf",-res);
}
