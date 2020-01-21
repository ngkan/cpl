#include <bits/stdc++.h>
using namespace std;
int test;
int z[1000005];
int cnt[1000005], sum[1000005];
string s;
int main(){
    iostream::sync_with_stdio(0);
    cin >> test;
    while(test--){
        memset(cnt,0,sizeof(cnt));
        memset(z,0,sizeof(z));
        cin >> s;
        int n = s.size();
        for(int i=1,l=0,r=0;i<n;i++){
            if (i <= r)
                z[i] = min (r - i + 1, z[i - l]);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]])
                ++z[i];
            if (i + z[i] - 1 > r)
                l = i, r = i + z[i] - 1;
        }
        for(int i=1;i<n;i++){
            cnt[i]++;
            cnt[min(i+z[i], 2*i)]--;
        }
        long long ans = 1;
        for(int i=1;i<n;i++)
            cnt[i] += cnt[i-1],
            ans = 1ll * ans * (cnt[i]+1) % 1000000007ll;
        cout << ans << endl;;
    }
}
