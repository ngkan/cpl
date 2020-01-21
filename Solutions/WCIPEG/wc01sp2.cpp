#include <bits/stdc++.h>
using namespace std;
int Ckn[101][101];
int n,k,a,b;
int main(){
    for(int i=0;i<=50;i++){
        for(int j=0;j<=50;j++){
            if (i == 0)
                Ckn[i][j] = 1;
            else if (j > 0)
                Ckn[i][j] = Ckn[i][j-1] + Ckn[i-1][j-1];
        }
    }
    while(cin >> n >> k){
        if (n + k == -2) break;
        cin >> a >> b;
        int res = 0;
        a--,b--;
        int len1 = (a-b+n)%n, len2 = n - len1;
        if ((k-len1)%2==0 && k >= len1)
            res += Ckn[len1 + (k-len1)/2][k];
        if ((k-len2)%2==0 && k >= len2)
            res += Ckn[len2 + (k-len2)/2][k];
        cout << res << endl;
    }
}
