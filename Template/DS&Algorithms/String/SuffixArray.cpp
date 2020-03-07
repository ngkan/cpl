#include <bits/stdc++.h>
using namespace std;

/*
    Suffix array
    Status: ???, need to upgrade
*/

int lg2[100005];
// remember to run this
void prepLg2(int bound){
    for(int i=2;i<=bound;i++)
        lg2[i] = lg2[i>>1] + 1;
}
struct SuffixArray{
    vector <int> sa, saRank, tmp;
    vector <vector <int> > lcp;
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
        sa.assign(strLen + 5, 0);
        saRank.assign(strLen + 5, 0);
        tmp.assign(strLen + 5, 0);
        lcp.assign(strLen + 5, vector<int>(20));
        //for(int i = 0; i < strLen; i ++)
        //    lcp[i].assign(20, 0);

        for(int i = 0; i < strLen; i ++)
            sa[i] = i, saRank[i] = s[i];

        for(gap = 1;;gap *= 2){
            sort(sa.begin(), sa.begin() + strLen, [&](int a, int b) {return this->saCmp(a, b);});
            //sort(sa.begin(), sa.begin() + strLen, saCmp);
            for(int i = 0; i < strLen; i ++) tmp[i+1] = tmp[i] + saCmp(sa[i], sa[i+1]);
            for(int i = 0; i < strLen; i ++) saRank[sa[i]] = tmp[i];
            if (tmp[strLen-1] == strLen-1) break;
        }
        build_lcp(s);
    }
};
int main(){
    prepLg2(100000);
}
