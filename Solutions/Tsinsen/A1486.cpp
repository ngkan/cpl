#include <bits/stdc++.h>
using namespace std;
int trie_kid[4000005][2], trie_val[4000005], trieSize;
void trieInsert(int val, int num_vip){
    int cur = 0;
    for(int bit=29;bit>=-1;bit--){
        trie_val[cur] = max(trie_val[cur], num_vip);
        if (bit == -1)  break;

        int state = ((val >> bit) & 1);
        if (trie_kid[cur][state] == -1){
            trie_kid[cur][state] = ++ trieSize;
            cur = trieSize;
        }
        else{
            cur = trie_kid[cur][state];
        }
    }
}
int trieGet(int val, int num_vip, int lim){
    if (trie_val[0] + num_vip < lim)    return -1;
    int res = 0;
    int cur = 0;

    for(int bit = 29;bit>=0;bit--){
        int state = ((val >> bit) & 1);
        if (trie_kid[cur][1 ^ state] != -1 && trie_val[trie_kid[cur][1^state]] + num_vip >= lim){
            res += (1 << bit);
            cur = trie_kid[cur][1 ^ state];
        }
        else{
            cur = trie_kid[cur][state];
        }
    }
    return res;
}
void trieReset(){
    for(int i=0;i<=trieSize;i++)    trie_kid[i][0] = trie_kid[i][1] = -1, trie_val[i] = - 200000;
    trieSize = 0;
}
int n,k, ans = -1;
int c[100005], is_vip[100005];
vector <int> G[100005];
int child[100005];
bool banned[100005];
void build_child_centroid(int u,int p){
    child[u] = 1;
    for(int i=0;i<(int)G[u].size();i++){
        int v = G[u][i];
        if (banned[v] || v == p) continue;
        build_child_centroid(v,u);
        child[u] += child[v];
    }
}
int find_centroid(int u,int p,int root){
    for(int i=0;i<(int)G[u].size();i++){
        int v = G[u][i];
        if (banned[v] || v == p || child[root] > 2 * child[v]) continue;
        return find_centroid(v,u,root);
    }
    return u;
}
void firstDfs(int u,int p,int val,int num_vip){
    if (banned[u])  return;
    val ^= c[u];
    num_vip += is_vip[u];
    ans = max(ans, trieGet(val, num_vip, k));
    for(int i=0;i<(int)G[u].size();i++){
        int v = G[u][i];
        if (v == p || banned[v]) continue;
        firstDfs(v, u, val, num_vip);
    }
}
void secondDfs(int u,int p,int val,int num_vip){
    if (banned[u])  return;
    val ^= c[u];
    num_vip += is_vip[u];
    trieInsert(val, num_vip);
    for(int i=0;i<(int)G[u].size();i++){
        int v = G[u][i];
        if (v == p || banned[v]) continue;
        secondDfs(v, u, val, num_vip);
    }
}
void solve(int x){
    build_child_centroid(x,x);
    int u = find_centroid(x,x,x);
    banned[u] = 1;

    trieReset();
    trieInsert(0, 0);
    ans = max(ans, trieGet(c[u], is_vip[u], k));
    trieInsert(c[u], is_vip[u]);

    for(int i=0;i<(int)G[u].size();i++){
        int v = G[u][i];
        firstDfs(v, u, 0, 0);
        secondDfs(v, u, c[u], is_vip[u]);
    }

    // continue solve
    for(int i=0;i<(int)G[u].size();i++){
        if (!banned[G[u][i]]){
            solve(G[u][i]);
        }
    }
}

int main(){
    // input
    for(int i=0;i<=4000000;i++) trie_kid[i][0] = trie_kid[i][1] = -1, trie_val[i] = -200000;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)   scanf("%d",&is_vip[i]);
    for(int i=1;i<=n;i++)   scanf("%d",&c[i]);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }

    solve(1);
    printf("%d",ans);
}
