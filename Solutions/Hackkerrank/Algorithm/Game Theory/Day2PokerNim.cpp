#include <bits/stdc++.h>
using namespace std;
int ans,n,test,x,k;
int main(){
    cin >> test;
    while(test--){
        ans = 0;
        cin >> n >> k;
        while(n--) cin >> x,ans^=x;
        if (!ans) cout << "Second\n";
        else cout <<"First\n";
    }
}
