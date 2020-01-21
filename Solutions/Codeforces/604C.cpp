#include <bits/stdc++.h>
using namespace std;
int n,cnt,cnt1,cnt0,ok;
string s;
int main(){
    iostream::sync_with_stdio(0);
    cin >> n >> s;
    for(int i=0;i<s.size();i++){
        int last;
        for(last=i;last<s.size();last++)
            if (s[i] != s[last]) break;
        --last;
        ++cnt;
        if (last - i > 1)   ok = 2;
        if (last - i >= 1) {if (s[i] == '0') cnt0++; else cnt1++;}
        i = last;
    }
    if (cnt1 && cnt0) ok = 2;
    cout << cnt + max((int)(max(cnt1,cnt0) >= 1), max(ok, 2*max((cnt0>=2),(cnt1>=2))));
}
