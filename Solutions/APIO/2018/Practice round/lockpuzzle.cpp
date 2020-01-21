#include <bits/stdc++.h>
using namespace std;
int n,m;
string s,t;
int main(){
    cin >> n >> m >> s >> t;
    string ss = s;
    string tt = t;
    sort(ss.begin(), ss.end());
    sort(tt.begin(), tt.end());
    if (ss != tt){
        cout << -1;
        return 0;
    }
    vector <int> trace;
    int n = s.size();
    for(int id=0;id<n;id++){
        for(int i=0;i<n;i++){
            if (s[i] == t[id]){
                //cout << id << ' ' << i << endl;
                string s0, s1, s2;
                for(int j=0;j<i;j++)    s0.push_back(s[j]);
                for(int j=i;j<i+1;j++) s1.push_back(s[j]);
                for(int j=i+1;j<n;j++) s2.push_back(s[j]);
                //cout << s0 << ' ' << s1 << ' ' << s2 << endl;
                trace.push_back(n-i-1);
                trace.push_back(1);
                trace.push_back(n);
                reverse(s2.begin(), s2.end());
                s2 = s1 + s2 + s0;
                reverse(s2.begin(), s2.end());
                s = s2;
                break;
            }
        }
        //cout << s << endl;
    }

    cout << trace.size() << '\n';
    for(auto v: trace)  cout << v << ' ';
}
