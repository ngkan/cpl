#include <bits/stdc++.h>
using namespace std;
int test;
int res[16][16];
bool visited[16][16];
int check(int x,int y){
    if (visited[x][y]) return res[x][y];
    visited[x][y]=1;
    return res[x][y] = !(((x-2 >=1 && y+1 <= 15)? check(x-2,y+1):1) & ((x-2 >=1 && y-1 >= 1)? check(x-2,y-1):1) & ((x-1 >=1 && y-2 >= 1)? check(x-1,y-2):1) & ((x+1 <=15 && y-2 >= 1)? check(x+1,y-2):1));
}
int main(){
    res[1][1] = 0;visited[1][1] = 1;
    res[1][2] = 0;visited[1][2] = 1;
    res[2][1] = 0;visited[2][1] = 1;
    res[2][2] = 0;visited[2][2] = 1;
    for(int i=1;i<=15;i++)
        for(int j=1;j<=15;j++)
            res[i][j] = check(i,j);
    cin >> test;
    while(test--){
        int a,b;
        cin >> a >> b;
        if (res[a][b]) cout <<"First\n";
        else cout << "Second\n";
    }
}
