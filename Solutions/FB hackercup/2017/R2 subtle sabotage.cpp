#include <bits/stdc++.h>
using namespace std;
int n,m,k,test;
int main(){
    freopen("subtle_sabotage.txt","r",stdin);
    freopen("out1.txt","w",stdout);
    cin >> test;
    for(int i=1;i<=test;i++){
        cin >> n >> m >> k;
        if (n > m) swap(n,m);
        if (n <= k)
            cout << "Case #" << i << ": " << -1 << endl;
        else if (n <= 2*k){
            if (m <= 2*k+2)
                cout << "Case #" << i << ": " << -1 << endl;
            else
                cout << "Case #" << i << ": " << 2 << endl;
        }
        else if (n <= 3*k){
            if (m <= 2*k+2)
                cout << "Case #" << i << ": " << -1 << endl;
            else
                cout << "Case #" << i << ": " << 3 << endl;
        }
        else if (n <= 4*k){
            if (m <= 2*k+2)
                cout << "Case #" << i << ": " << -1 << endl;
            else
                cout << "Case #" << i << ": " << 4 << endl;
        }
        else{
            if (k == 1)
                cout << "Case #" << i << ": " << 5 << endl;
            else
                cout << "Case #" << i << ": " << 4 << endl;
        }
    }
}
