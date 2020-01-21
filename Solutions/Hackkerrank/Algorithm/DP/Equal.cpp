#include <bits/stdc++.h>
using namespace std;
map<int,int> ez;
int ans,n,a[10001],low,test;
int main(){
    for(int i=-5;i<=-1;i++) ez[i] = 999999;
    for(int i=1;i<=1000;i++) ez[i] = min(ez[i-1]+1,min(ez[i-2]+1,ez[i-5]+1));
    cin >> test;
    while(test--){
        cin >> n;
        ans=999999999;low=10000000;
        for(int i=1;i<=n;i++) cin >> a[i],low=min(low,a[i]);
        for(int j=low;j>=max(low-4,0);j--){
            int tmp = 0;
            for(int i=1;i<=n;i++) tmp+=ez[a[i]-j];
            ans = min(ans,tmp);
        }
        cout << ans << endl;
    }
}
