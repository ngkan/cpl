#include <bits/stdc++.h>
using namespace std;
int test,n;
string s[1000];
void change(char &x){
    x = '1' + '0' - x;
}
void ans(bool ok){
    if (ok) cout << "Triangle " << test << " can be filled.\n";
    else cout << "Triangle " << test << " cannot be filled.\n";
}
int main(){
    iostream::sync_with_stdio(0);
    while(cin >> n && n){
        test++;
        for(int i=0;i<n;i++)
            cin >> s[i];
        if (n == 1){
            if (s[0][0] == '0') ans(1);
            else ans(0);
            continue;
        }
        for(int i=n-1;i;i--)
            for(int j=0;j<n-i;j++)
                if (s[i][j] != '0')
                    change(s[i][j]),
                    change(s[i-1][j]),
                    change(s[i-1][j+1]);
        for(int i=0;i<n-2;i++)
            if (s[0][i] != '0')
                change(s[0][i]),
                change(s[0][i+1]),
                change(s[0][i+2]);
        if (s[0][n-2] != '0' || s[0][n-1] != '0') ans(0);
        else ans(1);
    }
}
