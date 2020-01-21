#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll test,n,m,s;

int main(){
    scanf("%lld",&test);
    while(test--){
        scanf("%lld %lld %lld",&n,&m,&s);
        if (m <= (n-2) * (n-1) / 2 + 1)
            printf("%lld\n", s + m - n + 1);
        else{
            m -= (n-2) * (n-1) / 2;
            ll sum = (n-1) * (n-2) / 2 + m * (s-n+2);
            ll w = 1 + (n-2) * (s-n+1)/(n-1);
            if (w % (n-2))
                sum += min(0ll, w/(n-2) * ((n-2) * (n-1) /2 - m * (n-2))),
                w %= (n-2);
            else
                sum += min(0ll, (w/(n-2)-1) * ((n-2) * (n-1) /2 - m * (n-2))),
                w = (n-2);
            w--;
            sum += min(0ll, (n-2) * (n-1) / 2 - (n-2-w) * (n-1-w) / 2 - m * w);
            printf("%lld\n",sum);
        }
    }
}
