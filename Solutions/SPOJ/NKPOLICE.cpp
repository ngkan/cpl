#include <bits/stdc++.h>
using namespace std;
const int oo = (int) 1e8;
int n,m,q,cnt,root_kid,root;
int low[100005],num[100005];
int beg[100005],fin[100005];
int depth[100005];
bool khop[100005];
vector <int> G[100005];
vector <int> g[100005];
void dfs(int u,int p){
    low[u] = oo;
    num[u] = ++ cnt;
    beg[u] = cnt;
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i];
        if (v == p) continue;
        if (num[v])
            low[u] = min(low[u], num[v]);
        else{
            g[u].push_back(v);
            depth[v] = depth[u] + 1;
            if (u == root) root_kid ++;
            dfs(v,u);
            if (low[v] >= num[u] && u != root) khop[u] = 1;
            low[u] = min(low[u],low[v]);
        }
    }
    //G[u].clear();
    fin[u] = ++ cnt;
}
bool nam_o_duoi(int u,int p){
    return (beg[p] <= beg[u] && fin[u] <= fin[p]);
}
bool check1(int a,int b,int g1,int g2){
    if (beg[g1] > beg[g2]) swap(g1,g2);
    if (nam_o_duoi(a,g2) && nam_o_duoi(b,g2)) return 1;
    if (!nam_o_duoi(a,g2) && !nam_o_duoi(b,g2)) return 1;
    return 0;
}
int _find(int u,int des){
    int l = 0, r = g[u].size() - 1;
    while(l != r){
        int mid = (l+r)/2;
        if( beg[des] > fin[g[u][mid]]) l = mid+1;
        else if( fin[des] < beg[g[u][mid]] ) r = mid-1;
        else l = r = mid;
    }
    return g[u][l];
}
bool check2(int a,int b,int c){
    if (!nam_o_duoi(a,c) && !nam_o_duoi(b,c)) return 1;
    if (nam_o_duoi(a,c) && nam_o_duoi(b,c)){
        int c1 = _find(c,a);
        int c2 = _find(c,b);
        if (c1 == c2) return 1;
        if (low[c1] < num[c] && low[c2] < num[c]) return 1;
        return 0;
    }
    if (nam_o_duoi(a,c)) swap(a,b);
    int c2 = _find(c,b);
    if (low[c2] < num[c]) return 1;
    return 0;
}
void input(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    root = 1;
    root_kid = 0;
    dfs(1,1);
    if (root_kid >= 2) khop[1] = 1;
}
int main(){
    input();
    scanf("%d",&q);
    while(q--){
        int type,a,b,g1,g2,c;
        scanf("%d",&type);
        if (type == 1){
            scanf("%d %d %d %d",&a,&b,&g1,&g2);
            if (nam_o_duoi(g1,g2)) swap(g1,g2);
            if (depth[g1] + 1 != depth[g2] || low[g2] <= num[g1])
                printf("yes\n");
            else{
                if (check1(a,b,g1,g2)) printf("yes\n");
                else printf("no\n");
            }
        }
        else{
            scanf("%d %d %d",&a,&b,&c);
            if (!khop[c])
                printf("yes\n");
            else{
                if (check2(a,b,c)) printf("yes\n");
                else printf("no\n");
            }
        }
    }
}
