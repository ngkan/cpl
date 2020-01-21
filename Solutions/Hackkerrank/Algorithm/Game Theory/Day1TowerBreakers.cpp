#include <bits/stdc++.h>
using namespace std;
int test;
int main(){
    cin >> test;
    while(test--){
        int n,m;
        cin >> n >> m;
        if (m == 1) {cout <<"2\n";continue;}
        if (n%2 == 1) cout <<"1\n";
        else cout <<"2\n";
    }
}
