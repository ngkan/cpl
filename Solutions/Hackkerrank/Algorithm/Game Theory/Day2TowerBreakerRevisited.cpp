#include <bits/stdc++.h>
using namespace std;
vector <int> prime;
bool visited[1000001];
int n,x,ans,test;
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
int main(){
    pre(1000000);
    cin >> test;
    while(test--){
        cin >> n;
        ans = 0;
        while(n--){
            cin >> x; ans^=val(x);
        }
        if (ans) cout << 1 << endl;
        else cout << 2 << endl;
    }
}
