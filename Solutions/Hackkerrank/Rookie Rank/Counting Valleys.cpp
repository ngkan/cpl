#include <bits/stdc++.h>
using namespace std;
int n,ans,lv;
bool ez;
string s;
int main(){
    cin >> n >> s;
    for(int i=0;i<n;i++){
        if (s[i] == 'U') lv++;
        else lv--;
        if (!ez && lv < 0){
            ez=1;
        }
        else if (ez){
            if (lv == 0) ans++,ez=0;
        }
    }
    cout << ans;
}
