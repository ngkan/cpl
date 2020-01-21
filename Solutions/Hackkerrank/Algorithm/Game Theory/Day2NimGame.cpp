#include <bits/stdc++.h>
using namespace std;
int ans,n,test,x;
int main(){
    cin >> test;
    while(test--){
        ans = 0;
        cin >> n;
        while(n--) cin >> x,ans^=x;
        if (!ans) cout << "Second\n";
        else cout <<"First\n";
    }
}
