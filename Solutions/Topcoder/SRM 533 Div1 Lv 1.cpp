#include <stdio.h>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
class CasketOfStar{
public:
    int n, dp[55][55], a[55];
    int cal(int l,int r){
        if (l > r) return 0;
        if (l == r) return 0;
        if (l +1 == r) return 0;
        if (dp[l][r]) return dp[l][r];
        int res = 0;
        for(int i=l+1;i<r;i++)
            res = max(res, cal(l,i) + cal(i,r));
        return dp[l][r] = res + a[l] * a[r];
    }
    int maxEnergy(vector <int> w){
        memset(dp,0,sizeof(dp));
        n = w.size();
        for(int i=0;i<n;i++)
            a[i] = w[i];
        return cal(0,n-1);
    }
} ahi;
vector<int> a;
int main(){
    a.push_back(1); a.push_back(2); a.push_back(3);
    cout << ahi.CasketOfStar::maxEnergy(a);
}

