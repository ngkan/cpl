#include <bits/stdc++.h>
using namespace std;
int ans,n,test,x,a[10001];
int main(){
    cin >> test;
    while(test--){
        ans = 0;
        cin >> n;
        bool check = 0;
        for(int i=1;i<=n;i++) {cin >> a[i],ans^=a[i];if (a[i] > 1) check = 1;}
        if (check){
            if (ans) cout << "First\n";
            else cout << "Second\n";
        }
        else{
            if (ans == 1) cout << "Second\n";
            else cout <<"First\n";
        }
    }
}
