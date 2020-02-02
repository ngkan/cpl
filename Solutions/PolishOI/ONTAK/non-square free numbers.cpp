#include <bits/stdc++.h>
using namespace std;
long long n;
long long souocnt[200005];
long long khung[200005];
bool used[200005],P[200005];
void pre(long long N){
    for(long long i=2;i<=N;i++) khung[i] = i;
    for(long long i=2;i<=N;i++){
        if (used[i]) continue;
        P[i] = 1;
        for(long long j=i;j<=N;j+=i){
            used[j] = 1;
            khung[j]/=i;
            souocnt[j]++;
        }
    }
    for(long long i=2;i<=N;i++) if (khung[i] != 1) souocnt[i] = -1;
}
long long cal(long long x){
    long long res = 0;
    for(long long i=2;i*i<=x;i++){
        if (souocnt[i] == -1) continue;
        else if (souocnt[i] % 2) res += x / (i*i);
        else res -= x / (i*i);
    }
    return res;
}
long long solve(long long x){
    long long l = 1, r = 30000000000ll;
    while(l <= r){
        if (r-l<=1){
            if (cal(l) == x) return l;
            return r;
        }
        long long mid = (l+r)/2;
        if (cal(mid) >= x) r = mid;
        else l = mid;
    }
}
int main(){
    pre(200000);
    cin >> n;
    cout << solve(n);
}
