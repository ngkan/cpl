#include <bits/stdc++.h>
using namespace std;
long long x,y,cnt;
int main(){
    while(scanf("%lld %lld",&x,&y) == 2){
        if (!x && !y) break;
        cnt = 0;
        while(1){
            if (x > y) swap(x,y);
            if (y >= 2*x){
                if (cnt%2) printf("S\n");
                else printf("T\n");
                break;
            }
            y%=x;
            cnt++;
        }
    }
}
