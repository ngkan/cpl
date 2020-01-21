#include <bits/stdc++.h>
using namespace std;
int n,m,ans,a[205][205],b[205],L[205],R[205];
int sum[205][205];
int col1[205][205];
int col3[205][205];
string s[205];
int solve(int x1,int y1,int x2,int y2){
    int l = y1+1, r = y2 - 1;
    int res1=0,res3=0;
    memset(b,0,sizeof(b));
    memset(L,0,sizeof(L));
    memset(R,0,sizeof(R));
    for(int i=l;i<=r;i++)
        b[i] = col1[x1-1][i];
    for(int i=l;i<=r;i++){
        L[i] = i;
        int k = i-1;
        while(l <= k && b[k] >= b[i]){
            L[i] = L[k];
            k = L[i] - 1;
        }
    }
    for(int i=r;i>=l;i--){
        R[i] = i;
        int k = i+1;
        while(k <= r && b[i] <= b[k]){
            R[i] = R[k];
            k = R[i] + 1;
        }
    }
    for(int i=l;i<=r;i++)
        res1 = max(res1,(R[i] - L[i] + 1) * b[i]);

    memset(b,0,sizeof(b));
    memset(L,0,sizeof(L));
    memset(R,0,sizeof(R));
    for(int i=l;i<=r;i++)
        b[i] = col3[x2+1][i];
    for(int i=l;i<=r;i++){
        L[i] = i;
        int k = i-1;
        while(l <= k && b[k] >= b[i]){
            L[i] = L[k];
            k = L[i] - 1;
        }
    }
    for(int i=r;i>=l;i--){
        R[i] = i;
        int k = i+1;
        while(k <= r && b[i] <= b[k]){
            R[i] = R[k];
            k = R[i] + 1;
        }
    }
    for(int i=l;i<=r;i++)
        res3 = max(res3,(R[i] - L[i] + 1) * b[i]);
    //cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << ' ' << (x2-x1+1) * (y2-y1+1) << ' ' << res1 << ' ' << res3 << endl;
    if (!res1 || !res3) return 0;
    return (x2-x1+1) * (y2-y1+1) + res1 + res3;
}
void pre(){
    for(int i=1;i<=n;i++){
        int tmp = 0;
        for(int j=1;j<=m;j++){
            tmp += a[i][j];
            sum[i][j] = sum[i-1][j] + tmp;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if (a[i][j] == 0) col1[i][j] = 0;
            else col1[i][j] = col1[i-1][j] + 1;
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=1;j<=m;j++){
            if (a[i][j] == 0) col3[i][j] = 0;
            else col3[i][j] = col3[i+1][j] + 1;
        }
    }
}
int get(int x1,int y1,int x2,int y2){
    return sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1];
}
int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> s[i];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            a[i+1][j+1] = s[i][j] - '0';
    pre();
    for(int x1=1;x1<=n;x1++){
        for(int x2=x1;x2<=n;x2++){
            int y1, y2;
            // y2 - y1 >= 2
            for(y1 = 1;y1 <= m;y1 ++){
                for(y2 = y1;y2<=m;y2++){
                    if (get(x1,y1,x2,y2) != (x2 - x1 + 1) * (y2 - y1 + 1)){
                        break;
                    }
                }
                y2--;
                if (y2 - 2>= y1){
                    int tmp = solve(x1,y1,x2,y2);
                    ans = max(ans,tmp);
                }
                y1 = max(y1,y2-1);
            }
        }
    }
    cout << ans;
}
