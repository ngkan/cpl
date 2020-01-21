#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a,b,c,ans;
int main(){
    ans = (ll) 5e18;
    cin >> a >> b >> c;
    ans = min(ans, 3*max(a,max(b,c)) - a - b - c);
    a--;
    ans = min(ans, 3*max(a,max(b,c)) - a - b - c);
    b--;
    ans = min(ans, 3*max(a,max(b,c)) - a - b - c);
    c--;
    ans = min(ans, 3*max(a,max(b,c)) - a - b - c);
    a++,b++,c++;
    a++;
    a--;
    ans = min(ans, 3*max(a,max(b,c)) - a - b - c);
    b--;
    ans = min(ans, 3*max(a,max(b,c)) - a - b - c);
    c--;
    ans = min(ans, 3*max(a,max(b,c)) - a - b - c);
    a++,b++,c++;
    b++;
    a--;
    ans = min(ans, 3*max(a,max(b,c)) - a - b - c);
    b--;
    ans = min(ans, 3*max(a,max(b,c)) - a - b - c);
    c--;
    ans = min(ans, 3*max(a,max(b,c)) - a - b - c);
    printf("%lld",ans);
}
