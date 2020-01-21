#include <bits/stdc++.h>
using namespace std;
int wood,res,n,m;
string s[30];
vector <int> room;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int bfs(int x,int y){
    int res = 1;
    s[x][y] = 'I';
    for(int i=0;i<4;i++){
        int X = x + dx[i];
        int Y = y + dy[i];
        if (X < 0 || Y < 0 || X >= n || Y >= m) continue;
        if (s[X][Y] != 'I') res += bfs(X,Y);
    }
    return res;
}
int main(){
    cin >> wood >> n >> m;
    for(int i=0;i<n;i++)
        cin >> s[i];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        if (s[i][j] == '.') room.push_back(bfs(i,j));
    sort(room.begin(),room.end(),greater<int>());
    for(int i=0;i<room.size();i++){
        if (wood < room[i]) break;
        res ++;
        wood -= room[i];
    }
    if (res == 1)
        cout << "1 room, " << wood << " square metre(s) left over";
    else
        cout << res << " rooms, " << wood << " square metre(s) left over";
}
