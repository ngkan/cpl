#include <bits/stdc++.h>
using namespace std;
double res;
int n,x;
int main(){
    cin >> n;
    while(n--) cin >> x, res += (double) x;
    cout << fixed << setprecision(1) << res/2;
}
