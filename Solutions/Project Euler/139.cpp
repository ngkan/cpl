#include <bits/stdc++.h>
using namespace std;
int main(){
    int ans = 0;
    int n = (int) 1e8;
    for(int i=1;i*i < n;i++){
        for(int j=1;j<i && 2*i*i + 2*i*j < n;j++){
            if (__gcd(i,j) == 1 && (i+j)%2 == 1 && (i*i + j*j) % abs(i*i - j*j - 2 * i * j) == 0)    ans+=n/(2*i*i + 2*i*j);
        }
        //cout << i << ' ' << ans << endl;
    }
    cout << ans;
}
