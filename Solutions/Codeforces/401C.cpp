#include <bits/stdc++.h>
using namespace std;
int n,N,M,m;

string res;
int main(){
    cin >> n >> m;
    if (n > m+1) {cout << -1;exit(0);}
    if (2*n + 2 < m) {cout << -1;exit(0);}
    if (n == m+1) for(int i=0;i<n+m;i++) if (i%2) res.push_back('1');else res.push_back('0');
    else{
        int cnt = m-n;
        for(int i=0;i<n;i++){
            if (cnt) res.push_back('1'),res.push_back('1'),cnt--,m-=2;
            else res.push_back('1'),m--;
            res.push_back('0');
        }
        for(int i=1;i<=m;i++) res.push_back('1');
    }
    cout << res;
}
