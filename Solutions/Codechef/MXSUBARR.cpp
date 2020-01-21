#include <bits/stdc++.h>
#define ll long long
using namespace std;
int test,n,a[100005];
bool mark[100005];
vector <int> ahi;
vector <ll> val[100005];
int main(){
    scanf("%d",&test);
    while(test--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=n;i++){
            int last;
            for(last=i;last<=n;last++)
                if (a[last] != a[i]) break;
            last --;
            if (!mark[a[i]]) ahi.push_back(a[i]);
            mark[a[i]] = 1;
            val[a[i]].push_back(last-i+1);
            i = last;
        }
        ll res = 1;
        for(int i=0;i<ahi.size();i++){
            ll cnt = 0;
            for(int j=0;j<val[ahi[i]].size();j++)
                cnt += val[ahi[i]][j] * (val[ahi[i]][j] + 1) / 2;
            cnt %= ((ll)(1e9+7));
            res = (res * cnt) % ((ll)(1e9+7));
            mark[ahi[i]] = 0;
            val[ahi[i]].clear();
        }
        ahi.clear();
        printf("%lld\n",res);
    }
}
