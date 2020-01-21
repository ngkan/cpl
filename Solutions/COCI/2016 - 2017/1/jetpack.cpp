#include <bits/stdc++.h>
using namespace std;
int n;
string s[15];
int trace[15][100005];
bool dp[15][100005];
vector <int> res1,res2;
void build(int height, int col){
    bool ifcnt = 0;
    int cnt = 0;
    while(col){
        if (trace[height][col] == height){
            if (height != 10){
                if (ifcnt){
                    res1.push_back(col);
                    res2.push_back(cnt);
                    cnt = 0;
                    ifcnt = 0;
                }
            }
            else{
                if (!ifcnt)
                    ifcnt = 1;
                cnt++;
            }
            col--;
        }
        else if (trace[height][col] == height+1){
            if (ifcnt){
                res1.push_back(col);
                res2.push_back(cnt);
                cnt = 0;
                ifcnt = 0;
            }
            height ++, col--;
        }
        else{
            if (!ifcnt)
                ifcnt = 1, cnt++;
            else
                cnt++;
            height--, col--;
        }
    }
    if (ifcnt)
        res1.push_back(col+1), res2.push_back(cnt);
    reverse(res1.begin(),res1.end());
    reverse(res2.begin(),res2.end());
}
int main(){
    iostream::sync_with_stdio(0);
    cin >> n;
    for(int i=10;i>=1;i--)
        cin >> s[i];
    dp[1][1] = 1;
    trace[1][1] = 1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=10;j++){
            if (s[j][i-1] == 'X') continue;
            if ((j == 1||j==10) && dp[j][i-1])
                dp[j][i] = 1,
                trace[j][i] = j;
            else if (j < 10 && dp[j+1][i-1])
                dp[j][i] = 1,
                trace[j][i] = j+1;
            else if (j > 1 && dp[j-1][i-1])
                dp[j][i] = 1,
                trace[j][i] = j-1;
        }
    }
//    for(int j=10;j>=1;j--){
//        for(int i=1;i<=n;i++)
//            cout << dp[j][i]; cout << endl;
//    }
    for(int i=1;i<=10;i++)
        if (dp[i][n]){
            build(i,n);
            break;
        }
    cout << res1.size() << endl;
    for(int i=0;i<res1.size();i++)
        cout << res1[i]-1 << ' ' << res2[i] << endl;
}
