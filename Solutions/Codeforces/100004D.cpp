#include <bits/stdc++.h>
using namespace std;
string s;
int t;
vector <int> a;
int main(){
    cin >> t;
    while(t--){
        cin >> s;
        a.clear();
        for(int i=0;i<s.size();i++){
            s[i] = s[i] >= 'a' ? s[i] : s[i] - 'A' + 'a';
            if (s[i] <= 'o') a.push_back(2 + (s[i]-'a')/3);
            else if (s[i] <= 's') a.push_back(7);
            else if (s[i] <= 'v') a.push_back(8);
            else a.push_back(9);
        }
        bool ok = 1;
        for(int i=0;i<a.size();i++)
            if (a[i] != a[a.size()-1-i]) ok = 0;
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
