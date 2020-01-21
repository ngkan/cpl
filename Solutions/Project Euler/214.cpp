#include <bits/stdc++.h>
using namespace std;
const int n = (int) 4e7 - 1;
int phi[n+5], notprime[n+5], len[n+5];
void prep(){
    notprime[1] = 1;
    for(int i=1;i<=n;i++)   phi[i] = i;
    for(int i=2;i<=n;i++){
        if (notprime[i])    continue;
        for(int j=i;j<=n;j+=i){
            if (j != i) notprime[j] = 1;
            phi[j] = phi[j] / i * (i-1);
        }
    }
    long long res = 0;
    len[1] = 1;
    for(int i=2;i<=n;i++){
        len[i] = 1 + len[phi[i]];
        if (!notprime[i] && len[i] == 25) res += i;
    }
    cout << res;
}
int main(){
    prep();
}
