#include <bits/stdc++.h>
using namespace std;
int n,ans;
int main(){
    scanf("%d",&n);
    //n = 1000000;
    for(int i=1;i<=(int)sqrt(n);i++){
        if (n % i != 0) continue;
        for(int a=i;a<=n;a+=i){
            int b = n + i - a;
            if (a > b) break;
            ans += (__gcd(a,b) == i && a <= b);
        }
        if (n/i == i) continue;
        for(int a=n/i;a<=n;a+=n/i){
            int b = n + n/i - a;
            if (a > b) break;
            ans += (__gcd(a,b) == n/i && a <= b);
        }
    }
    printf("%d",ans);
}
