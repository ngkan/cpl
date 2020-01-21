#include <bits/stdc++.h>
using namespace std;
int dp[(1<<15)][(1<<6)];
class Xscoregame{
public:
    int getscore(vector <int> A){
        int dis = (1<<6)-1;
        for(int i=0;i<(1<<15);i++)
            for(int j=0;j<(1<<6);j++)
                dp[i][j] = -1;
        dp[0][0] = 0;
        int n = A.size();
        for(int mask=0;mask<(1<<n);mask++){
            for(int last=0;last<(1<<6);last++){
                if (dp[mask][last] == -1) continue;
                #define val dp[mask][last]
                #define dm ((val + (val^A[i])) & dis)
                for(int i=0;i<n;i++){
                    if ((mask & (1<<i))) continue;
                    dp[(mask|(1<<i))][dm]
                    = max(dp[(mask|(1<<i))][dm],
                          val + (val^A[i]));
                }
            }
        }
        int ans = 0;
        for(int last=0;last<(1<<6);last++)
            ans = max(ans, dp[(1<<n)-1][last]);
        return ans;
    }
};
#define pb push_back
int main(){
    vector<int> a;
    Xscoregame t;
    a.pb(5),a.pb(4),a.pb(1);
    cout << t.Xscoregame::getscore(a);
    cout <<
}
