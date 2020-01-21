#include <iostream>
#include <string.h>
using namespace std;
string s[55];
int n;
bool posi[55];
int main(){
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> s[i];
    cin >> s[0];
    for(int i=1;i<=n;i++){
        if (s[i].size() <= s[0].size()) continue;
        bool ok = 1;
        for(int j=0;j<s[0].size();j++)
            if (s[0][j] != s[i][j]) ok = 0;
        if (ok) posi[s[i][s[0].size()] - 'A'] = 1;
    }
    for(int i=0;i<32;i++){
        if (i < 3 || i > 28) cout << '*';
        else if (posi[i-3]) cout << (char)(i-3+'A');
        else cout << '*';
        if (i % 8 == 7) cout << endl;
    }
}
