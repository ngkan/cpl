/*
https://www.codechef.com/OCT16/problems/CHDOGS
*/
#include <bits/stdc++.h>
using namespace std;
int test;
int main(){
    cin >> test;
    while(test--){
        double s,v;
        cin >> s >> v;
        cout << fixed << setprecision(6) << s * 2 / 3 / v << endl;
    }
}
