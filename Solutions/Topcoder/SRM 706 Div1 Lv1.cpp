#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,ii> iiii;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
class MovingCandies{
public:
    int d[20][20][405];
    priority_queue<iiii,vector<iiii>,greater<iiii> > pq;
    int minMoved(vector <string> s){
        int tmp = 0, n = s.size(), m = s[0].size();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                tmp += (s[i][j] == '#');
        if (tmp < n+m-1) return -1;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                for(int k=0;k<=400;k++)
                    d[i][j][k] = (int) 1e9;

        d[0][0][1] = (s[0][0] != '#');

        pq.push(iiii(ii(d[0][0][1],1),ii(0,0)));
        while(pq.size()){
            int du = pq.top().fi.fi;
            int step = pq.top().fi.se;
            int x = pq.top().se.fi;
            int y = pq.top().se.se;
            pq.pop();

            if (du != d[x][y][step]) continue;
            for(int k=0;k<4;k++){
                int X = x + dx[k];
                int Y = y + dy[k];
                if (X < 0 || n <= X || Y < 0 || m <= Y) continue;
                if (d[X][Y][step+1] > d[x][y][step] + (s[X][Y] != '#'))
                    d[X][Y][step+1] = d[x][y][step] + (s[X][Y] != '#'),
                    pq.push(iiii(ii(d[X][Y][step+1],step+1),ii(X,Y)));
            }
        }
        int ans = (int) 1e9;
        for(int i=n+m-1;i<=tmp;i++)
            ans = min(ans, d[n-1][m-1][i]);
        return ans;
    }
};
vector <string> s;
MovingCandies a;
int main(){
    s.push_back("#...###");
    s.push_back("#...#.#");
    s.push_back("##..#.#");
    s.push_back(".#....#");
    cout << a.MovingCandies::minMoved(s);
}
