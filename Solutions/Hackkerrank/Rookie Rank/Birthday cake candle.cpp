#include <bits/stdc++.h>
using namespace std;
int res,h,n,x;
int main(){
    cin >> n;
    while(n--){
        cin >> x;
        if (x == h) res++;
        else if (x > h) res=1,h=x;
    }
    cout << res;
}
