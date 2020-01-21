#include <bits/stdc++.h>
using namespace std;
const int mod = (int) 1e6;
int n,l,dp[35][5][35][35];
int precal[5][35][(1<<5)];
string s[5][5];
int mask[5][35];
void init(){
    cin >> n >> l;
    for(int i=0;i<5;i++)    cin >> s[1][i], s[1][i] = "0" + s[1][i];
    for(int i=0;i<5;i++)    cin >> s[2][i], s[2][i] = "0" + s[2][i];
    for(int i=1;i<=l;i++){
        for(int j=0;j<5;j++)
            mask[1][i] |= ((s[1][j][i] == '#')<<j),
            mask[2][i] |= ((s[2][j][i] == '#')<<j);
    }
}
void prep(){
    for(int type=1;type<=2;type++){
        for(int i=0;i<=l;i++){
            for(int mask=0;mask<(1<<5);mask++){
                for(int len=min(l,i+1);len;len--){
                    bool ok = 1;
                    for(int j=i-len+2;j<=i;j++){
                        for(int row=0;row<5;row++)
                            if (s[type][row][j] != s[type][row][j-(i-len+2)+1])
                                ok = 0;
                    }
                    for(int row=0;row<5;row++)
                        if ((s[type][row][len]=='#') != ((mask&(1<<row)) > 0)) ok = 0;
                    if (ok){
                        precal[type][i][mask] = max(precal[type][i][mask],len);
                        break;
                    }
                }

            }
        }
    }
}
int main(){
    init();
    prep();
    dp[0][0][0][0] = 1;
    for(int i=0;i<=n;i++){
        for(int cnt=0;cnt<=2;cnt++){
            for(int l1=0;l1<=l;l1++){
                for(int l2=0;l2<=l;l2++){
                    for(int mask=0;mask<32;mask++){
                        int l1new = precal[1][l1][mask];
                        int l2new = precal[2][l2][mask];
                        if (cnt == 0){
                            if (l1new == l)
                                dp[i+1][1][l1new][l2new] = (dp[i+1][1][l1new][l2new] + dp[i][cnt][l1][l2]) % mod;
                            else if (l2new == l)
                                dp[i+1][2][l1new][l2new] = (dp[i+1][2][l1new][l2new] + dp[i][cnt][l1][l2]) % mod;
                            else
                                dp[i+1][0][l1new][l2new] = (dp[i+1][0][l1new][l2new] + dp[i][cnt][l1][l2]) % mod;
                        }
                        else if (cnt == 1){
                            if (l2new == l);
                            else
                                dp[i+1][1][l1new][l2new] = (dp[i+1][1][l1new][l2new] + dp[i][cnt][l1][l2]) % mod;
                        }
                        else{
                            if (l1new == l);
                            else
                                dp[i+1][2][l1new][l2new] = (dp[i+1][2][l1new][l2new] + dp[i][cnt][l1][l2]) % mod;
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int l1=0;l1<=l;l1++)
        for(int l2=0;l2<=l;l2++)
            ans = (ans + dp[n][1][l1][l2] + dp[n][2][l1][l2]) % mod;
    cout << ans;
}
