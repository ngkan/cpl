#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,q;
ll sumrow, sumcol, cntrow, cntcol;
bool askcol[1000005], askrow[1000005];
int main(){
    freopen("adjustment.in","r",stdin);
    freopen("adjustment.out","w",stdout);
    iostream::sync_with_stdio(0);
    cin >> n >> q;
    cntrow = cntcol = n;
    while(q--){
        char c; ll x;
        cin >> c >> x;
        if (c == 'R'){
            if (askrow[x]) cout << 0 << endl;
            else{
                cout << n*(n+1)/2 - sumrow + cntrow * x << endl;
                cntcol --;
                sumcol += x;
                askrow[x] = 1;
            }
        }
        else{
            if (askcol[x]) cout << 0 << endl;
            else{
                cout << n*(n+1)/2 - sumcol + cntcol * x << endl;
                cntrow --;
                sumrow += x;
                askcol[x] = 1;
            }
        }
    }
}
