#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
map <string, ll> dp[40];
void backtrack(string s, int sum){
    if (sum == m) {dp[1][s] = 1; return;}
    if (sum > m)   return;
    backtrack(s + '2', sum + 2);
    backtrack(s + '3', sum + 3);
}
bool ok(string &x, string &y){
    int pix = 1, piy = 1;
    int vx = x[0] - '0', vy = y[0] - '0';
    while(1){
        if (pix == x.size() && piy == y.size()) return 1;
        if (vx == vy) return 0;
        if (vx < vy){
            vx += x[pix++] - '0';
        }
        else{
            vy += y[piy++] - '0';
        }
    }
    return 1;
}
int main(){
    cin >> m >> n;
    backtrack("", 0);
    for(int i=2;i<=n;i++){
        for(auto it: dp[i-1]){
            string key = it.first;
            for(auto it2: dp[i-1]){
                string key2 = it2.first;
                if (ok(key, key2))
                    dp[i][key] += it2.second;
            }
        }
    }
    ll res = 0;
    for(auto it: dp[n]){
        res += it.second;
    }
    cout << res;
}
