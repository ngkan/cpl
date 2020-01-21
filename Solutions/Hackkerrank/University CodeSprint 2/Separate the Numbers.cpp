#include <bits/stdc++.h>
#define int long long
using namespace std;
int q;
string s;
bool doit(int pos,int a){
    if (pos == s.size()) return 1;
    if (s[pos] == '0') return 0;
    int now = 0;
    for(int i=pos;i<min((int)s.size(),pos+18);i++){
        now = now * 10 + s[i] - '0';
        if (now > a) return 0;
        if (now == a) return doit(i+1,a+1);
    }
    return 0;
}
void check(){
    if (s[0] == '0') {cout << "NO" << endl; return;}
    int a = 0;
    for(int i=0;i<min((int)s.size()-1,18ll);i++){
        a = a * 10 + s[i] - '0';
        if (doit(i+1,a+1)){
            cout << "YES " << a << endl;
            return;
        }
    }
    cout << "NO" << endl;
}
signed main(){
    cin >> q;
    while(q--){
        cin >> s;
        check();
    }
}
