#include <bits/stdc++.h>
using namespace std;
long long t,n;
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        cout << n*(n+1)/2 - 2 * (1ll<<((int)log2(n)+1)) + 2 << endl;
    }
}
