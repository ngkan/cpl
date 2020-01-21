#include <bits/stdc++.h>
using namespace std;
int t,n,ans,a[100005];
int ahi[10000007];
int ax[10000007];
vector <int> used;
int read_int(){
    char c;
    bool check = 0;
    int res = 0;
    while(1){
        c = getchar();
        if (c == '-') {check = 1; continue;}
        if (c == ' ' || c == '\n') break;
        res = res*10 + c - '0';
    }
    if (check) return -res;
    return res;
}
int main(){
    for(int i=2;i<=10000000;i++){
        if (!ax[i])
            for(int j=i;j<=10000000;j+=i)
                ax[j] = i;
    }
    t = read_int();
    while(t--){
        ans = 0;
        for(int i=0;i<used.size();i++) ahi[used[i]] = 0;
        used.clear();
        n = read_int();
        for(int i=1;i<=n;i++){
            int x, tmp = 0;
            x = read_int();
            vector <int> mini;
            while(x > 1){
                int vl = ax[x];
                tmp = max(tmp, ahi[vl]);
                mini.push_back(vl);
                used.push_back(vl);
                while(x % vl == 0)  x /= vl;
            }
            ans = max(ans,tmp+1);
            for(int j=0;j<mini.size();j++)
                ahi[mini[j]] = tmp+1;
        }
        printf("%d\n",ans);
    }
}
