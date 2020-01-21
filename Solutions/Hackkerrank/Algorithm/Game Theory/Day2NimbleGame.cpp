#include <bits/stdc++.h>
using namespace std;
int n,test,a[101],ans;
int main(){
    cin >> test;
    while(test--){
        ans = 0;
        cin >> n;
        for(int i=0;i<=n-1;i++) {cin >> a[i];if (a[i]%2) ans^=i;}
        if (ans) cout <<"First\n";
        else cout << "Second\n";
    }
}
