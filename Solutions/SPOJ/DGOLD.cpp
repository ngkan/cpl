#include <bits/stdc++.h>
using namespace std;
vector <int> a,c;
int n,x,dp[(1<<12)],ans;
map <int,int> mp;
void pre1(){
    int m = n/2;
    for(int i=0;i<m;i++) c.push_back(a[i]);
    for(int i=0;i<m;i++)
        for(int mask = 0; mask < (1<<m); mask++)
            if (((1<<i) & mask)) dp[mask] += c[i];
    for(int mask1 = 0;mask1 < (1<<m); mask1 ++){
        for(int mask2 = mask1 + 1; mask2 < (1<<m); mask2 ++)
            if (!(mask1 & mask2)){
                mp[abs(dp[mask1] - dp[mask2])] = max(mp[abs(dp[mask1] - dp[mask2])], dp[mask1] + dp[mask2]);
            }
    }
}
void pre2(){
    int m = n - n/2;
    c.clear();
    memset(dp,0,sizeof(dp));
    for(int i=n/2;i<n;i++) c.push_back(a[i]);
    for(int i=0;i<m;i++)
        for(int mask = 0; mask < (1<<m); mask++)
            if (((1<<i) & mask)) dp[mask] += c[i];
    for(int mask1 = 0;mask1 < (1<<m); mask1 ++){
        for(int mask2 = mask1 + 1; mask2 < (1<<m); mask2 ++){
            if ((mask1 & mask2)) continue;
            if (dp[mask1] == dp[mask2])
                ans = max(ans, dp[mask1] + dp[mask2] + mp[0]);
            else if (mp[abs(dp[mask1] - dp[mask2])] > 0)
                ans = max(ans, dp[mask1] + dp[mask2] + mp[abs(dp[mask1] - dp[mask2])]);
        }
    }
}
int main(){
    scanf("%d",&n);
    while(n--) scanf("%d",&x), a.push_back(x);
    n = a.size();
    pre1();
    pre2();
    printf("%d",ans/2);
}
