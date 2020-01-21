#include <iostream>
#include <string.h>
using namespace std;
string s;
int n,ans;
int main(){
    cin >> n;
    while(n--){
        cin >> s;
        for(int i=0;i<s.size();i++){
            if (s[i] == 'A') ans+=4;
            if (s[i] == 'K') ans += 3;
            if (s[i] == 'Q') ans += 2;
            if (s[i] == 'J') ans += 1;
        }
    }
    cout << ans;
}
