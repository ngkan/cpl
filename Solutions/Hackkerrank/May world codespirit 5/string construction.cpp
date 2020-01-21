#include <bits/stdc++.h>
using namespace std;
int res,test;
string s;
bool ez[200];
int main(){
    cin >> test;
    while(test--){
            res = 0;
        memset(ez,0,sizeof(ez));
        cin >> s;
        for(int i=0;i<s.size();i++) res += 1 - ez[s[i]],ez[s[i]]=1;
        cout << res << endl;
    }
}

