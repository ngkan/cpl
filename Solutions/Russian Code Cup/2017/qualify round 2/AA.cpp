#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef pair<int,int> ii;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int n,m,test;
bool visited[25][25];
int d[25][25], ans[25][25];
vector <ii> lv[500];
int main(){
   scanf("%d",&test);
   while(test--){
      scanf("%d %d",&n,&m);
      memset(visited,0,sizeof(visited));
      visited[1][1] = 1;
      queue <ii> q;
      q.push(ii(1,1));
      d[1][1] = n*m;

      while(q.size()){
         int x = q.front().x;
         int y = q.front().y;
         q.pop();
         for(int k=0;k<4;k++){
            int X = x + dx[k];
            int Y = y + dy[k];
            if (X < 1 || X > n || Y < 1 || Y > m) continue;
            if (visited[X][Y]) continue;
            visited[X][Y] = 1;
            d[X][Y] = d[x][y] - 1;
            q.push(ii(X,Y));
         }
      }
      for(int i=1;i<=n;i++)
         for(int j=1;j<=m;j++)
            lv[d[i][j]].push_back(ii(i,j));
      int cnt = n*m;
      for(int l=500;l>=0;l--){
         for(int j=0;j<lv[l].size();j++)
            ans[lv[l][j].x][lv[l][j].y] = cnt--;
         lv[l].clear();
      }
      for(int i=1;i<=n;i++){
         for(int j=1;j<=m;j++)
            printf("%d ",ans[i][j]);
         printf("\n");
      }
   }
}
