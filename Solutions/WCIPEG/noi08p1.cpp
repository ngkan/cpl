#include <bits/stdc++.h>
using namespace std;
int read_int(){
    char c;
    bool negative = 0;
    bool check = 0;
    int res = 0;
    while(1){
        c = getchar();
        if (c == '-')   {negative = 1; continue;}
        if (c == ' ' || c == '\n') {if (check) break; else continue;}
        check = 1;
        res = res*10 + c - '0';
    }
    if (negative)   res = -res;
    return res;
}
int n, m;
vector <int> G[100005], revG[100005];
int distanceFromRoot[100005];
int considerValue = -1;
void dfs(int u,int val){
    distanceFromRoot[u] = val;
    for(int v: G[u]){
        if (distanceFromRoot[v] != -2*n){
            if (val+1 != distanceFromRoot[v]){
                if (considerValue == -1)
                    considerValue = abs(distanceFromRoot[v] - val - 1);
                else
                    considerValue = __gcd(abs(distanceFromRoot[v] - val - 1), considerValue);
            }
        }
        else
            dfs(v, val+1);
    }
    for(int v: revG[u]){
        if (distanceFromRoot[v] != -2*n){
            if (val-1 != distanceFromRoot[v]){
                if (considerValue == -1)
                    considerValue = abs(distanceFromRoot[v] - val + 1);
                else
                    considerValue = __gcd(abs(distanceFromRoot[v] - val + 1), considerValue);
            }
        }
        else
            dfs(v, val-1);
    }
}

bool visited[100005];
set <int> dfs1Size;
void dfs1(int u, int val){
    if (visited[u]) return;
    visited[u] = 1;
    dfs1Size.insert(val);
    for(int v: G[u]){
        dfs1(v, val+1);
    }
    for(int v: revG[u]){
        dfs1(v, val-1);
    }
}

bool okCheck;
void dfsCheck(int u,int val,int lim){
    if (visited[u]){
        if (val != distanceFromRoot[u]) okCheck = 0;
        return;
    }
    visited[u] = 1;
    distanceFromRoot[u] = val;
    //cout << u << ' ' << val << endl;
    for(int v: G[u]){
        dfsCheck(v, (val+1)%lim, lim);
    }
    for(int v: revG[u]){
        dfsCheck(v, (val+lim-1)%lim, lim);
    }
}
bool check(int val){
    //cout << val << endl;
    memset(visited,0,sizeof(visited));
    memset(distanceFromRoot,0,sizeof(distanceFromRoot));
    okCheck = 1;
    for(int i=1;i<=n;i++){
        if (!visited[i])    dfsCheck(1, 0, val);
    }
    return okCheck;
}
int main(){
    n = read_int();
    m = read_int();
    while(m--){
        int x = read_int(), y = read_int();
        G[x].push_back(y);
        revG[y].push_back(x);
    }

    if (n < 3){
        cout << "-1 -1";
        return 0;
    }

    for(int i=1;i<=n;i++)
        distanceFromRoot[i] = -2*n;

    for(int i=1;i<=n;i++){
        if (distanceFromRoot[i] == -2*n){
            dfs(i, 0);
        }
    }

    //cerr << considerValue << endl;

    if (considerValue == -1){
        // everything is ok
        int maxAns = 0;
        for(int i=1;i<=n;i++){
            if (visited[i]) continue;
            dfs1Size.clear();
            dfs1(i, 0);
            //minAns = max(minAns, (int)dfs1Size.size());
            maxAns += dfs1Size.size();
        }
        if (maxAns < 3)    cout << "-1 -1";
        else cout << maxAns << ' ' << 3;
    }
    else{
        int maxAns = -1, minAns = n+1;
        for(int t = 1; t <= (int)sqrt(considerValue); t++){
            if (considerValue % t)  continue;
            if (t > 2 && check(t))
                maxAns = max(maxAns, t), minAns = min(minAns, t);
            if (considerValue/t > 2 && check(considerValue/t))
                maxAns = max(maxAns, considerValue/t), minAns = min(minAns, considerValue/t);
        }
        cout << maxAns << ' ' << min(maxAns, minAns);
    }
}
