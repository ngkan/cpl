#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int,int> ii;
deque<ii> dqma,dqmi;
int k,n,a[3000005],ans;
int main(){
    scanf("%d %d",&k,&n);
    int ctrl=1;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        while(dqma.size() && dqma.back().fi <= a[i]) dqma.pop_back();
        while(dqmi.size() && dqmi.back().fi >= a[i]) dqmi.pop_back();
        dqma.push_back(ii(a[i],i));
        dqmi.push_back(ii(a[i],i));
        while(dqma.front().fi - dqmi.front().fi > k){
            ctrl++;
            while(dqma.front().se < ctrl) dqma.pop_front();
            while(dqmi.front().se < ctrl) dqmi.pop_front();
        }
        ans = max(ans, i - ctrl + 1);
    }
    printf("%d",ans);
}
