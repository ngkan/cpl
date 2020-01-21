#include <bits/stdc++.h>
using namespace std;
int a[1055][1055],ans,n;
bool mark[1055][1055][5];
// 0 up 1 right 2 down 3 left
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int dfs(int x,int y,int val){
    int res = 1;
    for(int d=0;d<4;d++){
        int cnt = 0;
        int X = x + dx[d];
        int Y = y + dy[d];
        if (mark[x][y][d]) continue;
        if (1 <= X && X <= n && 1 <= Y && Y <= n && !mark[X][Y][(d+2)%4]){
            bool sure = 1;
            if (abs(a[x][y] - a[X][Y]) != val) continue;
            for(int dd=0;dd<4;dd++)
                if (mark[X][Y][dd] && abs(a[X][Y] - a[X+dx[dd]][Y+dy[dd]]) == val)
                    sure = 0;
            mark[X][Y][(d+2)%4] = 1;
            mark[x][y][d] = 1;
            if (!sure) continue;
            cnt += dfs(X,Y,val);
        }
        else continue;
        res += cnt;
    }
    return res;
}
int main(){
    for(int i=0;i<=1005;i++) a[0][i] = (1<<25), a[i][0] = (1<<25);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ans = max(ans,dfs(i,j,abs(a[i][j] - a[i+1][j])));
            ans = max(ans,dfs(i,j,abs(a[i][j] - a[i][j+1])));
        }
    }
    printf("%d",ans);
}
