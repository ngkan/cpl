#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    for(ll i=(ll) sqrt(1e18);i <= (ll)sqrt(2e18);i++){
        ll tmp = i*i;
        bool ok = 1;
        //cout << tmp << endl;
        if ((tmp/(ll)1e0)%10 != 0) ok = 0;
        if ((tmp/(ll)1e2)%10 != 9) ok = 0;
        if ((tmp/(ll)1e4)%10 != 8) ok = 0;
        if ((tmp/(ll)1e6)%10 != 7) ok = 0;
        if ((tmp/(ll)1e8)%10 != 6) ok = 0;
        if ((tmp/(ll)1e10)%10 != 5) ok = 0;
        if ((tmp/(ll)1e12)%10 != 4) ok = 0;
        if ((tmp/(ll)1e14)%10 != 3) ok = 0;
        if ((tmp/(ll)1e16)%10 != 2) ok = 0;
        if ((tmp/(ll)1e18)%10 != 1) ok = 0;
        if (ok) {cout << tmp << endl; return 0;}
    }
}
