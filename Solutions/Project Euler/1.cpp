#include <bits/stdc++.h>
using namespace std;
long long n,test;
int main(){
    scanf("%lld",&test);
    while(test--){
        scanf("%lld",&n);n--;
        long long sum1 = (n/3) * (n/3+1) /2 * 3;
        long long sum2 = (n/5) * (n/5+1) /2 * 5;
        long long sum3 = (n/15) * (n/15+1) / 2 * 15;
        printf("%lld\n",sum1+sum2-sum3);
    }
}
