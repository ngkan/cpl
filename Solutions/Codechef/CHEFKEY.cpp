/*
https://www.codechef.com/OCT16/problems/CHEFKEY
*/
#include <bits/stdc++.h>
using namespace std;
int t,m,n,c;
int main(){
    cin >> t;
    while(t--){
        cin >> m >> n >> c;
        int ans = 0;
        for(int i=1;i<=m;i++)
            ans += (c%i == 0 && c/i <= n);
        cout << ans << endl;
    }
}
