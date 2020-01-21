#include <bits/stdc++.h>
using namespace std;
int t;
int main(){
    cin >> t;
    while(t--){
        int x;
        cin >> x;
        if (x < 0) cout << "X\n";
        else if (x < 50) cout << "F\n";
        else if (x < 60) cout << "D\n";
        else if (x < 70) cout << "C\n";
        else if (x < 80) cout << "B\n";
        else if (x <= 100) cout << "A\n";
        else cout << "X\n";
    }
}
