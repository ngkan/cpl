#include <bits/stdc++.h>
using namespace std;
int res;
string s;
int main(){
    cin >> s;
    for(int i=0;i<s.size();i++)
        res += (s[i] < 'a');
    cout << res + 1;
}
