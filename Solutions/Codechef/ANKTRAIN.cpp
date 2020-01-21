#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,t;
    cin >> t;
    while(t--){
        cin >> n;
        int v = (n-1)%8 + 1;
        if      (v == 1) cout << n-1+4 << "LB\n";
        else if (v == 4) cout << n-4+1 << "LB\n";
        else if (v == 2) cout << n-2+5 << "MB\n";
        else if (v == 5) cout << n-5+2 << "MB\n";
        else if (v == 3) cout << n-3+6 << "UB\n";
        else if (v == 6) cout << n-6+3 << "UB\n";
        else if (v == 7) cout << n-7+8 << "SU\n";
        else             cout << n-8+7 << "SL\n";
    }
}
