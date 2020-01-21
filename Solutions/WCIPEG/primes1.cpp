#include <bits/stdc++.h>
using namespace std;
int t;
int main(){
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << ((1-(n%400!=0)) || ((n%100) && (1-(n%4!=0)))) << endl;
    }
}
