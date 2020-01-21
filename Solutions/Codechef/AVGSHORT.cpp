#include <bits/stdc++.h>
using namespace std;
const int N = 505;
struct edge{
    int v;
    double w;
    edge(int v=0,double w=0.0): v(v), w(w) {}
};
int test,n,m,s,t,cntvisit[N];
bool visited[N];
double d[N],cnt[N];
vector <edge> G[N],Grev[N];
void dfs(int u){
    ++cntvisit[u];
    visited[u] = 1;
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i].v;
        if (visited[v]) continue;
        dfs(v);
    }
}
void dfsrev(int u){
    ++cntvisit[u];
    visited[u] = 1;
    for(int i=0;i<Grev[u].size();i++){
        int v = Grev[u][i].v;
        if (visited[v]) continue;
        dfsrev(v);
    }
}
bool dfscheck(int u){
    visited[u] = 1;
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i].v;
        if (visited[v]) return 1;
        dfs(v);
    }
    return 0;
}
int main(){
    scanf("%d",&test);
    while(test--){
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++) G[i].clear(), Grev[i].clear(), cntvisit[i] = 0;
        for(int i=1;i<=m;i++){
            int x,y,w;
            scanf("%d %d %d",&x,&y,&w);
            G[x].push_back(edge(y,1.0*w));
            Grev[y].push_back(edge(x,1.0*w));
        }
        scanf("%d %d",&s,&t);
        memset(visited,0,sizeof visited);   dfs(s);
        memset(visited,0,sizeof visited);   dfsrev(t);
        if (cntvisit[s] != 2){  printf("-1\n"); continue;}
        double l = 0, r = 1e6+12;
        for(int hax=0;hax<=100;hax++){
            double mid = (l+r)/2.0;
            fill(d,d+n+1,1e12);
            memset(visited,0,sizeof visited);
            memset(cnt,0,sizeof cnt);
            queue <int> q;  q.push(s);  visited[s] = 1;
            d[s] = 0.0;
            bool ok = 1;
            while(q.size()){
                int u = q.front();
                q.pop();
                visited[u] = 0;
                cnt[u] ++;
                if (cnt[u] > n){ ok = 0; break;}
                for(int i=0;i<G[u].size();i++){
                    int v = G[u][i].v;
                    if (cntvisit[v] != 2) continue;
                    if (d[v] > d[u] + G[u][i].w - mid){
                        d[v] = d[u] + G[u][i].w - mid;
                        if (!visited[v])
                            visited[v] = 1, q.push(v);
                    }
                }
            }
            if (ok == 0 || d[t] < 0) r = mid;
            else l = mid;
        }
        printf("%.6lf\n",l);
    }
}
