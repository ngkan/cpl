#include <bits/stdc++.h>
using namespace std;
string s;
long long dp[5005];
int main(){
    iostream::sync_with_stdio(0);
    while(cin >> s){
        if (s == "0") break;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<s.size();i++){
            if (!i){
                if ('1' <= s[i] && s[i] <= '9')
                    dp[i] ++;
            }
            else if (i == 1){
                string tmp(s,i-1,2);
                if ('1' <= s[i] && s[i] <= '9')
                    dp[i] += dp[i-1];
                if ("10" <= tmp  &&  tmp <= "26")
                    dp[i] ++;
            }
            else{
                string tmp(s,i-1,2);
                if ('1' <= s[i] && s[i] <= '9')
                    dp[i] +=  dp[i-1];
                if ("10" <= tmp && tmp <= "26")
                    dp[i] += dp[i-2];
            }
        }
        cout << dp[s.size()-1] << endl;
    }

}
