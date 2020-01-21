#include <bits/stdc++.h>
using namespace std;
long long ez[10000011],ans,tmp,n,m,a,b,k;
int main(){
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        cin >> a >> b >> k;
        ez[a] += k;
        ez[b+1] -= k;
    }
    ans = ez[1];
    for(int i=1;i<=n;i++){
        tmp += ez[i];
        ans = max(ans,tmp);
    }
    cout << ans;
}
