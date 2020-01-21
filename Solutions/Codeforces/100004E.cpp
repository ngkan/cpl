#include <bits/stdc++.h>
using namespace std;
int test,c,t,l,e[30][1005],p[30][1005],dp[30][1005],ans;
int main(){
    iostream::sync_with_stdio(0);
    cin >> test;
    while(test--){
        cin >> c >> t >> l;
        for(int i=1;i<=c;i++)
            for(int j=1;j<=t;j++)
                dp[i][j] = (int) 1e9,
                cin >> p[i][j] >> e[i][j];
        for(int i=1;i<=t;i++)
            dp[1][i] = e[1][i] + p[1][i];
        for(int i=2;i<=c;i++)
            for(int j=1;j<=t;j++){
                for(int jj=1;jj<=t;jj++)
                    dp[i][j] = min(dp[i][j], dp[i-1][jj] + abs(p[i][j] - p[i-1][jj]));
                dp[i][j] += e[i][j];
            }
        ans = (int) 1e9;
        for(int i=1;i<=t;i++)
            ans = min(ans, dp[c][i] + l - p[c][i]);
        cout << ans << endl;
    }
}
