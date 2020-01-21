#include <bits/stdc++.h>
#define ll long long
#define fff(i,a,b) for(int i=(a);i<(b);i++)
#define ff(i,a,b) for(int i=(a);i<=(b);i++)
#define fb(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
typedef vector<int> vi;
map <int,int> mp[100005];
int l,CNT = 1;
int leaf[205];
int d[201][201];
vi G[100005];
int nhan[100005];
bool used[100005];
void gg(void){
    cout << -1;
    exit(0);
}
void build(){
    int ccnt = l;
    queue<int> q;
    ff(i,1,l)   nhan[leaf[i]] = i;
    used[leaf[1]] = 1;
    q.push(leaf[1]);
    while(q.size()){
        int u = q.front();
        q.pop();
        fff(i,0,G[u].size()){
            int v = G[u][i];
            if (used[v]) continue;
            if (!nhan[v]) nhan[v] = ++ccnt;
            used[v] = 1;
            q.push(v);
        }
    }
}
void dfs(int u,int p,int dis,int root){
    if (G[u].size() == 1 && u != root){
        if (d[nhan[root]][nhan[u]] != dis) gg();
    }
    fff(i,0,G[u].size()){
        int v = G[u][i];
        if (v == p) continue;
        dfs(v,u,dis+1,root);
    }
}

void solve(vi lst,int dis){
    if (!lst.size()) return;
    vi tmp[205];
    ff(i,0,200) tmp[i].clear();
    int bot = lst[0];
    fff(i,1,lst.size()){
        // luon luon so sanh vi root la nut 1
        int d1 = d[1][lst[i]];
        int d2 = d[bot][lst[i]];
        int x = (d1 + d2 - d[1][bot]) / 2;
        if (2 * x != d1 + d2 - d[1][bot]) gg();
        int pos = d2 - x;
        if (pos <= 0 || d[1][bot] - dis < pos) gg();
        if (pos == d[1][bot]) gg();
        tmp[pos].push_back(lst[i]);
    }
    int old_CNT = CNT;
    solve(tmp[d[1][bot] - dis], dis);
    ff(i,1,d[1][bot] - dis){
        CNT++;
        if (i == d[1][bot] - dis) leaf[lst[0]] = CNT;
        G[old_CNT].push_back(CNT);
        G[CNT].push_back(old_CNT);
        old_CNT = CNT;
        solve(tmp[d[1][bot] - dis - i],dis + i);
    }
}
int main(){
    //freopen("restore.in","r",stdin);
    //freopen("restore.out","w",stdout);
    scanf("%d",&l);
    ff(i,1,l)
        ff(j,1,l)
            scanf("%d",&d[i][j]);
    vi tmp;
    ff(i,2,l) tmp.push_back(i);
    leaf[1] = 1;
    solve(tmp,0);
    build();
    ff(i,1,l) dfs(leaf[i],leaf[i],0,leaf[i]);
    cout << CNT << endl;
    ff(i,1,l){
        if (mp[leaf[i]][G[leaf[i]][0]] || mp[G[leaf[i]][0]][leaf[i]]) continue;
        cout << nhan[leaf[i]] << ' ' << nhan[G[leaf[i]][0]] << endl,
        mp[leaf[i]][G[leaf[i]][0]] = 1;
    }
    ff(i,1,CNT){
        fff(j,0,G[i].size()){
            if (mp[i][G[i][j]] || mp[G[i][j]][i]) continue;
            cout << nhan[i] << ' ' << nhan[G[i][j]] << endl,
            mp[i][G[i][j]] = 1;
        }
    }
}
/*
4
0 5 3 3
5 0 4 4
3 4 0 2
3 4 2 0
*/
