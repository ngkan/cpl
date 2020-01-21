#include <bits/stdc++.h>
using namespace std;
int m,l,r,k;
string s;
int pos[100005], tmp[100005];
int main(){
    iostream::sync_with_stdio(0);
    cin >> s >> m;
    for(int i=0;i<s.size();i++) pos[i] = i;
    while(m--){
        cin >> l >> r >> k;
        l--, r--;
        for(int i=0;i<=r-l;i++)
            tmp[l + i] = pos[l + ((i - k) % (r-l+1) + r-l+1) % (r-l+1)];
        for(int i=0;i<=r-l;i++)
            pos[l+i] = tmp[l+i];
    }
    for(int i=0;i<s.size();i++) cout << s[pos[i]];
}
