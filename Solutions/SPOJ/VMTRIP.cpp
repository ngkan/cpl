#include <bits/stdc++.h>
using namespace std;
const int _M = (int) 1e5 + 5;
int n,m,s,t,p[_M],k;
int lv[_M];
vector <int> G[_M];
vector <int> Gin[_M],Gout[_M];
priority_queue< int,vector<int>,greater<int> > pq[_M];
int in[_M],out[_M];
int res[_M];
bool used[_M];
queue <int> q;
void bfs1(){
    q.push(s);
    while(q.size()){
        int u = q.front();
        q.pop();
        for(int i=0;i<G[u].size();i++){
            int v = G[u][i];
            if (!lv[v])
                lv[v] = lv[u] + 1,
                Gout[u].push_back(v),
                Gin[v].push_back(u),
                q.push(v);
            else if (lv[u] + 1 == lv[v])
                Gout[u].push_back(v),
                Gin[v].push_back(u);
        }
    }
}
void del(int u){
    used[u] = 1;
    for(int i=0;i<Gin[u].size();i++){
        int p = Gin[u][i];
        if (used[p]) continue;
        out[p] -- ;
        if (!out[p]) del(p);
    }
    for(int i=0;i<Gout[u].size();i++){
        int v = Gout[u][i];
        if (used[v]) continue;
        in[v] -- ;
        if (!in[v]) del(v);
    }
}
void pre(){
    lv[s] = 1;
    bfs1();
    k = lv[t];
    used[s] = 1;
    used[t] = 1;
    for(int i=1;i<=n;i++)
        in[i] = Gin[i].size(), out[i] = Gout[i].size();
    for(int i=1;i<=n;i++)
        if (i != s && i != t && (!in[i] || !out[i]) && !used[i])
            del(i);
    for(int i=1;i<=n;i++)
        if (!used[i]) pq[lv[i]].push(i);
}
int main(){
    scanf("%d %d %d %d",&n,&m,&s,&t);
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    pre();
    for(int i=1;i<=k;i++){
        scanf("%d",&p[i]);
        if (p[i] == 1){
            res[1] = s;
            continue;
        }
        if (p[i] == k){
            res[k] = t;
            continue;
        }
        while(used[pq[p[i]].top()]) pq[p[i]].pop();
        res[p[i]] = pq[p[i]].top();
        pq[p[i]].pop();
        while(pq[p[i]].size()){
            if (!used[pq[p[i]].top()])
                del(pq[p[i]].top());
            pq[p[i]].pop();
        }
    }
    for(int i=1;i<=k;i++)
        printf("%d ",res[i]);
}
