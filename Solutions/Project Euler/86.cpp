#include <bits/stdc++.h>
using namespace std;
long long cnt = 0,n;
int main(){
    cin >> n;
    for(long long a=1;a<=n;a++){
        for(long long b=a;b<=n;b++)
            for(long long c=b;c<=n;c++){
                long long tmp = a*a + b*b + c*c + 2*a*b;
                if (tmp == (long long) sqrt(tmp) * (long long) sqrt(tmp)) cnt++;
            }
    }
    cout << cnt;
}
