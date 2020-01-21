#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = (int) 1e5 + 5;
ll n, w[N], h[N], prev[N], nex[N], pos, res[N], cnt;
int main(){
    scanf("%lld",&n);
    h[0] = h[n+1] = (1ll<<60);
    for(int i=1;i<=n;i++){
        scanf("%lld %lld",&w[i],&h[i]);
        prev[i] = i-1, nex[i] = i+1;
        if (h[pos] > h[i])  pos = i;
    }

    while(prev[pos] != 0 || nex[pos] != n+1){
        res[pos] = cnt + w[pos];
        cnt += (min(h[prev[pos]],h[nex[pos]]) - h[pos]) * w[pos];

        if (h[prev[pos]] < h[nex[pos]]){
            pos = prev[pos];
            w[pos] += w[nex[pos]];
            nex[pos] = nex[nex[pos]];
            prev[nex[pos]] = pos;
        }
        else{
            pos = nex[pos];
            w[pos] += w[prev[pos]];
            prev[pos] = prev[prev[pos]];
            nex[prev[pos]] = pos;
        }

        while(h[prev[pos]] < h[pos]) pos = prev[pos];
        while(h[pos] > h[nex[pos]]) pos = nex[pos];
    }
    res[pos] = cnt + w[pos];
    for(int i=1;i<=n;i++)
        printf("%lld\n",res[i]);
}
