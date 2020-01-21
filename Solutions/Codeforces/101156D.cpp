#include <bits/stdc++.h>
#define ll  long long
using namespace std;
ll test;
ll oo = (ll) 3e18;
ll n,k;
vector <ll> Ckn[2005];
vector <ll> res;
ll choose(ll k,ll n){
    if (k > n || k < 0) return 0;
    k = min(k, n - k);
    return Ckn[k][n-k];
}
int main(){
    for(int i=0;i<=2000;i++){
        if (i <= 4) Ckn[i].assign(1005005,0);
        else Ckn[i].assign(1005005/i,0);
    }
    for(int i=0;i<=2000;i++){
        for(int j=i;j<i + Ckn[i].size();j++)
            if (i == 0) Ckn[i][j] = 1;
            else Ckn[i][j-i] = min(oo, choose(i,j-1) + choose(i-1,j-1));
    }
    while(cin >> n >> k && n){
        test++;
        if (n == 1){
        	printf("Case %lld: %lld\n",test,k);
        	continue;
        }
        k++;
        if (n == 2){
            ll sum,L = 0, R = (ll) 2e9;
            while(L+1<R){
                sum = (L+R)/2;
                if (sum * (sum+1)/2 < k) L = sum;
                else R = sum;
            }
            sum = L;
        	k -= sum * (sum+1) / 2;
        	printf("Case %lld: %lld %lld\n",test,k-1,sum-k+1);
        	continue;
        }
        ll sum = 0;
        if (n == 3){
            ll L = 0, R = (ll) 2e6;
            while(L + 1 < R){
                sum = (L+R)/2;
                if ((sum+2) * sum * (sum+1) / 6 < k) L = sum;
                else R = sum;
            }
            sum = L;
            k -= (sum+2) * sum * (sum+1) / 6;
            ll num=0;
            L = 0, R = (ll) sum+1;
            while(L + 1 < R){
                num = (L+R)/2;
                if (num * (sum+1) - num*(num-1)/2 < k) L = num;
                else R = num;
            }
            num = L;
            k -= num * (sum+1) - num*(num-1)/2;
            printf("Case %lld: %lld %lld %lld\n",test,num,k-1,sum-num-k+1);
            continue;
        }

        for(sum=0;;sum++){
            if (choose(sum,n-1+sum) < k)
                k -= choose(sum,n-1+sum);
            else break;
        }
        printf("Case %lld:",test);
        for(ll i=1;i<n;i++){
            for(ll num=0;;num++){
                if (choose(sum-num,n-1-i+sum-num) < k)
                    k -= choose(sum-num,n-1-i+sum-num);
                else{
                    printf(" %lld",num);
                    sum -= num;
                    break;
                }
            }
        }
        printf(" %lld\n",sum);
    }
}
/*
6 123123000
*/
