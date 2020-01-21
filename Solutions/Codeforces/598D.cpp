#include <bits/stdc++.h>
using namespace std;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int n,m,k,a,b;
int ans[1000][1000];
bool visited[1000][1000], visited2[1000][1000];
string s[1000];
int bfs(int x,int y){
    if (visited[x][y]) return 0;
    visited[x][y] = 1;
    int res = 0;
    for(int i=0;i<4;i++){
        int X = x + dx[i], Y = y + dy[i];
        if (X < 0 || n <= X || Y < 0 || m <= Y || s[X][Y] != '.') res++;
        else res += bfs(X,Y);
    }
    return res;
}
void bfs2(int x,int y,int val){
    if (visited2[x][y]) return;
    visited2[x][y] = 1;
    ans[x][y] = val;
    for(int i=0;i<4;i++){
        int X = x + dx[i], Y = y + dy[i];
        if (X < 0 || n <= X || Y < 0 || m <= Y || s[X][Y] != '.') continue;
        else bfs2(X,Y,val);
    }
}
int main(){
    iostream::sync_with_stdio(0);
    cin >> n >> m >> k;
    for(int i=0;i<n;i++)
        cin >> s[i];
    for(int i=0;i<k;i++){
        cin >> a >> b;
        a--, b--;
        if (!visited[a][b]) bfs2(a,b,bfs(a,b));
        cout << ans[a][b] << endl;
    }
}
