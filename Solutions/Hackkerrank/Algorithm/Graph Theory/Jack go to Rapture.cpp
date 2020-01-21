#include <bits/stdc++.h>
using namespace std;
struct edge{
    int u,v,w;
    edge (int u=0,int v=0,int w=0): u(u), v(v), w(w) {}
    bool operator <(edge x){
        return w < x.w;
    }
};
int dsup[50005];
int dsu_p(int x){return x == dsup[x] ? x : dsup[x] = dsu_p(dsup[x]);}
void dsu_union(int x,int y){if (dsu_p(x) == dsu_p(y)) return; dsup[dsu_p(y)] = dsu_p(x);}
int n,m;
vector <edge> a;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        a.push_back(edge(u,v,w));
    }
    for(int i=1;i<=n;i++) dsup[i] = i;
    sort(a.begin(),a.end());
    for(int i=0;i<a.size();i++){
        dsu_union(a[i].u,a[i].v);
        if (dsu_p(1) == dsu_p(n))
            return printf("%d",a[i].w);
    }
    printf("NO PATH EXISTS");
}
