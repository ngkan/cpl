#include <bits/stdc++.h>
using namespace std;
int mi,ma,s,n,cnt1,cnt2;
int main(){
    scanf("%d",&n);
    scanf("%d",&s), mi = ma = s;
    while(--n){
        scanf("%d",&s);
        cnt1 += (s > ma);
        cnt2 += (s < mi);
        ma = max(ma,s);
        mi = min(mi,s);
    }
    printf("%d %d",cnt1,cnt2);
}
