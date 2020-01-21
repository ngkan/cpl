#include <bits/stdc++.h>
using namespace std;
int n;
int sum = 0;
int a[500005],b[500005];
int dq[500005], dqfront,dqback;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]), sum += a[i];
    for(int i=0;i<n/2;i++)
        b[0] += a[i];
    for(int i=1;i<n;i++)
        b[i] = b[i-1] - a[i-1] + a[(i+n/2-1+n)%n];
    for(int i=1;i<=n/2 + (n%2==1);i++){
        if (dqfront==dqback) dq[dqback++] = i;
        else{
            while(dqfront < dqback && b[dq[dqback-1]] < b[i]) --dqback;
            dq[dqback++]=i;
        }
    }

    int ans = 0;
    for(int i=0;i<n;i++){
        if (dq[dqfront] == i) dqfront++;
        ans = max(ans, sum - b[dq[dqfront]]);
        while(dqfront < dqback && b[dq[dqback-1]] < b[(i+n/2 + (n%2==1)+1)%n]) --dqback;
            dq[dqback++]=(i+n/2 + (n%2==1)+1)%n;
    }
    cout << ans;
}
