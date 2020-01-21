#include <bits/stdc++.h>
using namespace std;
int n,d,a[300005],ans;
int main(){
    scanf("%d %d",&n,&d);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int ctrl=1+d;
    for(int i=2;i<=n;i++){
        if (a[i]) ctrl = i + d;
        if (i == ctrl) ans++, ctrl = i + d;
    }
    printf("%d",ans);
}
