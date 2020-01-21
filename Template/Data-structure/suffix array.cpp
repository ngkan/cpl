#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
string s;
int sa[100005], sa_rank[100005], tmp[100005], lcp[100005];    // suffix array
int gap;
bool sa_cmp(int x,int y){
    if (sa_rank[x] != sa_rank[y])                                               // khac rank
        return sa_rank[x] < sa_rank[y];
    x += gap;                                                                   // giong rank thi so sanh phan duoi
    y += gap;
    return x < s.size() && y < s.size() ? sa_rank[x] < sa_rank[y] : x > y;
}
void build_sa(){
    for(int i=0;i<s.size();i++) sa[i] = i, sa_rank[i] = s[i];                   // init rank = chu cai dau tien cua hau to
    for(gap = 1;;gap *= 2){                                                     // gap la khoang cach xet: 1, 2, 4, 8, ...
        sort(sa,sa+s.size(),sa_cmp);                                            // sort lai
        for(int i=0;i<s.size();i++) tmp[i+1] = tmp[i] + sa_cmp(sa[i],sa[i+1]);  // khoi tao lai rank
        for(int i=0;i<s.size();i++) sa_rank[sa[i]] = tmp[i];                    // gan rank
        if (tmp[s.size()-1] == s.size()-1) break;                               // ktra xem da sort dc het chua
    }
    for(int i=0;i<s.size();i++) printf("%d ",sa[i]);
    printf("\n");
}
void build_lcp(){
    int k = 0;
    for(int i=0;i<s.size();i++){
        if (sa_rank[i] != s.size()-1){
            for (int j = sa[sa_rank[i] + 1]; s[i + k] == s[j + k];)
               ++k;
            lcp[sa_rank[i]] = k;
            if (k) k--;
        }
    }
    for(int i=0;i<s.size();i++) printf("%d ",lcp[i]);
}
int main(){
    cin >> s;
    build_sa();
    build_lcp();
}

