#include <bits/stdc++.h>
using namespace std;
int t,n,mjk,mj,k;
int zzpow(int x,int p){
    int res=1; while(p--)res*=x;return res;
}
int main(){
    cin >> n;
    for(int i=9;i>=0;i--){
        mj*=2;
        if (n/zzpow(10,i)%10){
            k++;    if(n/zzpow(10,i)%10==7)mj++;
        }
    }

    cout << mj+(1<<(k))-1;
}
