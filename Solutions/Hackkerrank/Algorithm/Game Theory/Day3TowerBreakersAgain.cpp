#include <bits/stdc++.h>
using namespace std;
int test,n,a[1001],ans;
vector <int> prime;
bool visited[1000001];
void pre(int n){
    for(int i=2;i<=n;i++){
        if (visited[i]) continue;
        prime.push_back(i);
        for(int j=i;j<=n;j+=i) visited[j] = 1;
    }
}
int val(int x){
    int res = 0;
    for(int i=0;;i++){
        if (x == 1) break;
        while(x%prime[i]==0) {res++;x/=prime[i];}
    }
    return res;
}
int val2(int x){
    while(x%2==0) x/=2;
    int res = 0;
    for(int i=0;;i++){
        if (x == 1) break;
        while(x%prime[i]==0) {res++;x/=prime[i];}
    }
    return res;
}
int main(){
    pre(1000000);
    cin >> test;
    while(test--){
        cin >> n;
        ans = 0;
        int check = 0,check2=0;
        for(int i=1;i<=n;i++) {
            cin >> a[i];
            if (a[i]%2 || val(a[i])==1) ans^=val(a[i]);
            else{
                if (val2(a[i]) == 0) ans^=1;
                else check2^=1;
            }
        }
        ans %= 2;
        if ((ans+check)%2==1) cout << 1 << endl;
        else cout << 2 << endl;
    }
}
