#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector <ll> x,res;
ll n,dp[505][505],a[505];
int main(){
    cin >> n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin >> dp[i][j];
    for(int i=1;i<=n;i++) cin >> a[i];
    reverse(a+1,a+n+1);
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dp[i][j] = min(dp[i][j], dp[i][a[k]] + dp[a[k]][j]);
        ll sum = 0;
        for(int i=1;i<=k;i++)
            for(int j=1;j<=k;j++)
                sum += dp[a[i]][a[j]];
        res.push_back(sum);
    }
    reverse(res.begin(),res.end());
    for(int i=0;i<res.size();i++) cout << res[i] << ' ';
}
