#include <bits/stdc++.h>
using namespace std;
string a,b;
string _new(string s){
    if (s.size()%2==1) return s;
    string s1 (s,0,s.size()/2);
    string s2 (s,s.size()/2,s.size()/2);
    s1 = _new(s1);
    s2 = _new(s2);
    if (s1 < s2) return s1 + s2;
    return s2 + s1;
}
int main(){
    cin >> a >> b;
    a = _new(a);
    b = _new(b);
    if (a == b) cout << "YES";
    else cout << "NO";
}
