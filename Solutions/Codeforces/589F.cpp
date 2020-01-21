#include <bits/stdc++.h>
using namespace std;
int n,cnt,a[505],b[505];
int f[505][505], c[505][505], p[505], flow;
int mark[10004];
vector <int> G[505];
void build(){
    cnt = n;
    int last = -1, fin = -1;
    for(int i=1;i<=10000;i++){
        if (mark[i]){
            if (last == -1 && fin == -1){
                last = i;
                fin = max(fin, mark[i]);
            }
            else{
                if (i == fin){
                    ++cnt, a[cnt] = last, b[cnt] = fin;
                    if (mark[i] == i)
                        last = -1, fin = -1;
                    else
                        last = i+1, fin = mark[fin];
                }
                else{
                    ++cnt, a[cnt] = last, b[cnt] = i;
                    last = i+1;
                    fin = max(fin,mark[i]);
                }
            }
        }
    }
    if (last != -1)
        ++cnt, a[cnt] = last, b[cnt] = fin;

    for(int i=1;i<=n;i++)
        for(int j=n+1;j<=cnt;j++)
            c[i][j] = max(0,min(b[i],b[j]) - max(a[i],a[j])+1),
            G[i].push_back(j),
            G[j].push_back(i);
    for(int i=1;i<=n;i++){
        G[0].push_back(i);
        G[i].push_back(0);
    }
    for(int i=n+1;i<=cnt;i++){
        G[i].push_back(cnt+1);
        G[cnt+1].push_back(i);
        c[i][cnt+1] = b[i] - a[i] + 1;
    }
}
bool find_aug(){
    fill(p,p+501,-1);
    queue <int> q;
    q.push(0);
    while(q.size()){
        int u = q.front();
        q.pop();
        if (u == cnt+1) return 1;
        for(int i=0;i<G[u].size();i++){
            int v = G[u][i];
            if (p[v] == -1 && c[u][v] > f[u][v]){
                p[v] = u;
                q.push(v);
            }
        }
    }
    return 0;
}
void inc_flow(){
    int res = (1<<30);
    for(int v=cnt+1; v!=0; v=p[v])
        res = min(res,c[p[v]][v] - f[p[v]][v]);
    for(int v=cnt+1; v!=0; v=p[v])
        f[p[v]][v] += res,
        f[v][p[v]] -= res;
    flow += res;
}
bool solve(int val){
    flow = 0;
    memset(f,0,sizeof(f));
    for(int i=1;i<=n;i++)
        c[0][i] = val;
    while (find_aug())
        inc_flow();
    if (flow == val * n) return 1;
    return 0;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d %d",&a[i],&b[i]),
        a[i] ++,
        mark[a[i]] = max(mark[a[i]],b[i]), mark[b[i]] = max(mark[b[i]],b[i]);
    build();
//    for(int i=1;i<=cnt;i++)
//        cout << a[i] << ' ' << b[i] << endl;
//    cout << endl;
//    for(int i=1;i<=n;i++)
//        for(int j=n+1;j<=cnt;j++)
//        cout << i << ' ' << j << ' ' << c[i][j] << endl;
    int l=0,r=10000;
    while(l != r){
        if (l+1>=r){
            if (solve(r)) l = r;
            else r = l;
        }
        int mid = (l+r)/2;
        if (solve(mid)) l = mid;
        else r = mid;
    }
    printf("%d",l*n);
}
