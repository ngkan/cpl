#include <bits/stdc++.h>
using namespace std;
int n,x,cnt[1000005],oops,ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        cnt[x]++;
    }
    for(int i=1;i<=n;i++){
        oops += cnt[i-1];
        if (n - oops >= i) ans = i;
    }
    printf("%d",ans);
}
