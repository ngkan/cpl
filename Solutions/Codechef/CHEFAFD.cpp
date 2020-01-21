#include <bits/stdc++.h>
using namespace std;
int t,n;
string s[155][155];
vector <int> G[155*155];
int pair_1[155*155], pair_2[155*155];
bool visited[155*155];
bool dfs(int u){
    if (!u) return 1;
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i];
        if (!visited[v]){
            visited[v] = 1;
            if (dfs(pair_2[v])){
                pair_1[u] = v;
                pair_2[v] = u;
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    iostream::sync_with_stdio(0);
    cin >> t;
    while(t--){
        for(int i=1;i<155*155;i++) G[i].clear(),pair_1[i] = pair_2[i] = 0;
        cin >> n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin >> s[i][j];
                int u = (i - 1) * n + j;
                for(int k=0;k<s[i][j].size();k++){
                    if (s[i][j][k] == 'U' && i > 1)
                        G[u].push_back(u - n);
                    if (s[i][j][k] == 'L' && j > 1)
                        G[u].push_back(u - 1);
                    if (s[i][j][k] == 'D' && i < n)
                        G[u].push_back(u + n);
                    if (s[i][j][k] == 'R' && j < n)
                        G[u].push_back(u + 1);
                }
            }
        }
        int cnt = 0, ahi = -1;
        while(cnt < n*n && cnt != ahi){
            ahi = cnt;
            fill(visited+1,visited+n*n+1,0);
            for(int i=1;i<=n*n;i++){
                if (!pair_1[i] && dfs(i))
                    cnt++;
            }
        }
        if (cnt != n*n) cout << "NO" << endl;
        else{
            cout << "YES" << endl;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    int u = (i-1) * n + j;
                    if (u - pair_1[u] == -1) cout << "R ";
                    if (u - pair_1[u] ==  1) cout << "L ";
                    if (u - pair_1[u] == -n) cout << "D ";
                    if (u - pair_1[u] ==  n) cout << "U ";
                }
                cout << endl;
            }
        }
    }
}
