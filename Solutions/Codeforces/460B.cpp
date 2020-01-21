#include <bits/stdc++.h>
using namespace std;
long long a,b,c;
vector <long long> res;
long long zzpow(long long x,long long p){
    long long res = 1;
    while (p > 0) res*=x,p--;
    return res;
}
bool check(long long x,long long val){
    if (x <= 0 || x >= 1000000000) return 0;
    long long sum = 0;
    while(x>0) sum += x%10,x/=10;
    return sum == val;
}
int main(){
    cin >> a >> b >> c;
    for(long long i=1;i<=81;i++) if (check(b * zzpow(i,a) + c, i)) res.push_back(b * zzpow(i,a) + c);
    cout << res.size() << endl;
    for(int i=0;i<res.size();i++) cout << res[i] << ' ';
}
