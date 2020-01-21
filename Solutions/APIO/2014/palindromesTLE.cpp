#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = (ll) 1e9+9;
const ll base = 29;
int lg2[300005];
// remember to run this
void prepLg2(int bound){
    for(int i=2;i<=bound;i++)
        lg2[i] = lg2[i>>1] + 1;
}
struct suffixArray{
    int sa[300005], saRank[300005], tmp[300005];
    int lcp[300005][20];
    int strLen, gap;

    bool saCmp(int x,int y){
        if (saRank[x] != saRank[y])
            return saRank[x] < saRank[y];
        return x+gap < strLen && y+gap < strLen ? saRank[x+gap] < saRank[y+gap] : x > y;
    }

    void build_lcp(string &s){
        int k = 0;
        for(int i = 0; i < strLen; i ++){
            if (saRank[i] != strLen - 1){
                for (int j = sa[saRank[i] + 1]; max(i+k, j+k) < strLen && s[i + k] == s[j + k];)  ++k;
                lcp[saRank[i]][0] = k;
                if (k) k--;
            }
        }
        for(int k = 1; k < 20; k ++){
            for(int i = 0; i < strLen; i ++)
                if (i + (1<<k) < strLen)
                    lcp[i][k] = min(lcp[i][k-1], lcp[i+(1<<(k-1))][k-1]);
                else break;
        }
    }

    int getLcp(int l,int r){
        if (l > r)  swap(l, r);
        if (l == r) return strLen - sa[l];
        int k = lg2[r - l];
        return min(lcp[l][k], lcp[r-(1<<k)][k]);
    }

    void build(string &s, int isIndexFromOne = 0){
        strLen = s.size();

        for(int i = 0; i < strLen; i ++)
            sa[i] = i, saRank[i] = s[i];

        for(gap = 1;;gap *= 2){
            sort(sa, sa + strLen, [&](int a, int b) {return this->saCmp(a, b);});
            //sort(sa.begin(), sa.begin() + strLen, saCmp);
            for(int i = 0; i < strLen; i ++) tmp[i+1] = tmp[i] + saCmp(sa[i], sa[i+1]);
            for(int i = 0; i < strLen; i ++) saRank[sa[i]] = tmp[i];
            if (tmp[strLen-1] == strLen-1) break;
        }
        build_lcp(s);
    }
};
int n;
string s[2];
suffixArray suff;
ll hashCode[2][300000], pBase[300000];
int palin[2][300000];
void prepHash(){
    pBase[0] = 1;
    for(int i=1;i<300000;i++)
        pBase[i] = pBase[i-1] * base % mod;

    hashCode[0][0] = s[0][0] - 'a' + 1;
    hashCode[1][0] = s[1][0] - 'a' + 1;
    for(int i=1;i<n;i++)
        hashCode[0][i] = (hashCode[0][i-1] + pBase[i] * (s[0][i] - 'a' + 1)) % mod,
        hashCode[1][i] = (hashCode[1][i-1] + pBase[i] * (s[1][i] - 'a' + 1)) % mod;
}
bool checkPalindrome(int l1,int r1){
    int l2 = n-1-r1;
    int r2 = n-1-l1;

    ll val1 = (hashCode[0][r1] - (l1 == 0 ? 0 : hashCode[0][l1-1]) + mod) % mod;
    ll val2 = (hashCode[1][r2] - (l2 == 0 ? 0 : hashCode[1][l2-1]) + mod) % mod;
    val1 = val1 * pBase[max(0, r2 - r1)] % mod;
    val2 = val2 * pBase[max(0, r1 - r2)] % mod;
    return val1 == val2;
}
ll ans = 0;
bool check(int root, int rad, bool type){
    if (type){
        if (root - rad < 0 || root + rad >= n)  return 0;
        if (!checkPalindrome(root-rad, root+rad))   return 0;
        int len = 2 * rad + 1;
        int head = suff.saRank[root-rad];
        int far = head;
        int near = head;
        if (1ll * len * (n - len + 1) < ans)  return 1;
        for(int k=lg2[n-head+1]+1;k>=0;k--){
            if (far + (1<<k) < n && suff.getLcp(head, far + (1<<k)) >= len)
                far += (1<<k);
        }
        for(int k=lg2[head+1]+1;k>=0;k--){
            if (near - (1<<k) >= 0 && suff.getLcp(near - (1<<k), head) >= len)
                near -= (1<<k);
        }
        ans = max(ans, 1ll * len * (far - near + 1));
        return 1;
    }
    else{
        if (root-1 - rad < 0 || root + rad >= n)  return 0;
        if (!checkPalindrome(root-1-rad, root+rad))   return 0;
        int len = 2 * (rad+1);
        int head = suff.saRank[root-1-rad];
        int far = head;
        int near = head;
        if (1ll * len * (n - len + 1) < ans)  return 1;
        for(int k=lg2[n-head+1]+1;k>=0;k--){
            if (far + (1<<k) < n && suff.getLcp(head, far + (1<<k)) >= len)
                far += (1<<k);
        }
        for(int k=lg2[head+1]+1;k>=0;k--){
            if (near - (1<<k) >= 0 && suff.getLcp(near - (1<<k), head) >= len)
                near -= (1<<k);
        }
        ans = max(ans, 1ll * len * (far - near + 1));
        return 1;
    }
}
int main(){
    freopen("69","r",stdin);
    prepLg2(300000);
    iostream::sync_with_stdio(0);
    cin >> s[0];
    n = s[0].size();

    s[1] = s[0];
    reverse(s[1].begin(), s[1].end());

    suff.build(s[0]);
    prepHash();

    int pivot0 = -1, pivot1 = -1;
    for(int i=0;i<n;i++){
        pivot0 ++;
        pivot1 ++;
        while(pivot0 >= 0 && !check(i-pivot0, pivot0, 0))
            pivot0--;
        while(pivot1 >= 0 && !check(i-pivot1, pivot1, 1))
            pivot1--;
    }
    cout << ans;
}
