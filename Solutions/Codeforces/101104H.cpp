#include <bits/stdc++.h>
using namespace std;
int n,test,dp[105][4][4][4][4];
bool card[105][4];
map<char,int> mp;
void maximize(int &x,int y){
    x = max(x,y);
}
// y r g b
int main(){
    freopen("test2.out","r",stdin);
    //freopen("ans.out","w",stdout);
    mp['y'] = 0, mp['r'] = 1, mp['g'] = 2, mp['b'] = 3;
    iostream::sync_with_stdio(0);
    cin >> test;
    while(test--){
        for(int i=0;i<=100;i++) for(int y=0;y<4;y++) for(int r=0;r<4;r++) for(int g=0;g<4;g++) for(int b=0;b<4;b++) dp[i][y][r][g][b] = -1000;
        dp[0][0][0][0][0] = 0;
        int ans = 0;
        memset(card,0,sizeof(card));
        cin >> n;
        for(int i=1;i<=n;i++){
            string s; int val = 0;
            cin >> s;
            for(int j=0;j<s.size()-1;j++)
                val = val * 10 + s[j] - '0';
            card[val][mp[s[s.size()-1]]] = 1;
        }
        for(int i=0;i<100;i++){
            for(int y=0;y<4;y++) for(int r=0;r<4;r++) for(int g=0;g<4;g++) for(int b=0;b<4;b++){
                if (dp[i][y][r][g][b] < 0) continue;
                for(int mask = 0; mask < 16; mask ++){
                    int y0,r0,g0,b0;
                    int t0 = (((1<<0)&mask) && card[i+1][0]);   if (t0) y0 = min(3,y+1); else y0 = 0;
                    int t1 = (((1<<1)&mask) && card[i+1][1]);   if (t1) r0 = min(3,r+1); else r0 = 0;
                    int t2 = (((1<<2)&mask) && card[i+1][2]);   if (t2) g0 = min(3,g+1); else g0 = 0;
                    int t3 = (((1<<3)&mask) && card[i+1][3]);   if (t3) b0 = min(3,b+1); else b0 = 0;
                    int res = dp[i][y][r][g][b];
                    if (t0 && y == 2) res += 3*i; else if (t0 && y == 3) res += i+1;
                    if (t1 && r == 2) res += 3*i; else if (t1 && r == 3) res += i+1;
                    if (t2 && g == 2) res += 3*i; else if (t2 && g == 3) res += i+1;
                    if (t3 && b == 2) res += 3*i; else if (t3 && b == 3) res += i+1;
                    maximize(dp[i+1][y0][r0][g0][b0], res);
                }
                if (card[i+1][0] && card[i+1][1] && card[i+1][2]){
                    int res = dp[i][y][r][g][b], b0;
                    int t3 = card[i+1][3];   if (t3) b0 = min(3,b+1); else b0 = 0;
                    if (t3 && b == 2) res += 3*i; else if (t3 && b == 3) res +=i+1;
                    maximize(dp[i+1][0][0][0][b0], res + 3*i+3);
                }
                if (card[i+1][0] && card[i+1][1] && card[i+1][3]){
                    int res = dp[i][y][r][g][b], g0;
                    int t2 = card[i+1][2];   if (t2) g0 = min(3,g+1); else g0 = 0;
                    if (t2 && g == 2) res += 3*i; else if (t2 && g == 3) res +=i+1;
                    maximize(dp[i+1][0][0][g0][0], res + 3*i+3);
                }
                if (card[i+1][0] && card[i+1][2] && card[i+1][3]){
                    int res = dp[i][y][r][g][b], r0;
                    int t1 = card[i+1][1];   if (t1) r0 = min(3,r+1); else r0 = 0;
                    if (t1 && r == 2) res += 3*i; else if (t1 && r == 3) res += i+1;
                    maximize(dp[i+1][0][r0][0][0], res + 3*i+3);
                }
                if (card[i+1][1] && card[i+1][2] && card[i+1][3]){
                    int res = dp[i][y][r][g][b],y0;
                    int t0 =  card[i+1][0];   if (t0) y0 = min(3,y+1); else y0 = 0;
                    if (t0 && y == 2) res += 3*i; else if (t0 && y == 3) res += i+1;
                    maximize(dp[i+1][y0][0][0][0], res + 3*i+3);
                }
                if (card[i+1][0] && card[i+1][1] && card[i+1][2] && card[i+1][3])
                    maximize(dp[i+1][0][0][0][0], dp[i][y][r][g][b] + 4*i+4);
            }
        }
        for(int y=0;y<4;y++) for(int r=0;r<4;r++) for(int g=0;g<4;g++) for(int b=0;b<4;b++) maximize(ans,dp[100][y][r][g][b]);
        cout << ans << endl;
    }
}
/*
3
5
7g 7b 7r 8r 9r
7
23b 1y 24b 1r 93b 1b 100r
8
2y 2r 2g 2b 4g 5g 6g 7g
*/
