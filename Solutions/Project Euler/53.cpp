#include <bits/stdc++.h>
using namespace std;
int res;
int main(){
    for(int n=1;n<=100;n++){
        int tmp = 1;
        for(int j=1;j<=n;j++){
            tmp = tmp * (n+1-j) / j;
            //if (n == 23 && j == 10) cout << tmp << endl;
            if (tmp > 1000000){
                res += n+1 - 2 * (j);
                break;
            }
        }
    }
    cout << res;
}
