#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int N = (int) 5e5+5;
int n;
string s;
int sa[N], sa_rank[N], tmp[N], lcp[N];    // suffix array
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
    //for(int i=0;i<s.size();i++) printf("%d ",sa[i]);
    //printf("\n");
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
    //for(int i=0;i<s.size();i++) printf("%d ",lcp[i]);printf("\n");
}
int h[N],lg2[N];
vector<int> val[2*N];
int rmq[N][20];
int main(){
    for(int i=2;i<N;i++) lg2[i] = lg2[i/2] + 1;
    iostream::sync_with_stdio(0);
    cin >> n >> s;
    s = 'z' + s;
    for(int i=0;i<=n;i++)
        h[i] = (i? h[i-1]:0) + (s[i] == '(' ? 1 : -1),
        val[N+h[i]].push_back(i),
        rmq[i][0] = h[i];
    for(int k=1;k<=19;k++)
        for(int i=0;i<=n;i++)
            if (i + (1<<k) - 1 <= n)
                rmq[i][k] = min(rmq[i][k-1],rmq[i+(1<<(k-1))][k-1]);
    build_sa();
    build_lcp();
    int ctrl = 1;
    long long ans = 0;
    for(int i=0;i<=n;i++){
        if (s[sa[i]] >= ')') break;
        int hnow = h[sa[i]];
        int l = 1, r = n - sa[i] + 2;
        while(l+1<r){
            int mid = (l+r)/2;
            int gg = mid;
            int tmp = min(rmq[sa[i]][lg2[gg]], rmq[sa[i]+ mid-1 - (1<<lg2[gg])][lg2[gg]]);
            if (tmp >= hnow-1) l = mid;
            else r = mid;
        }
        #define vec val[N+hnow-1]
        int res = 0;
        if (l >= ctrl){
            res = -(lower_bound(vec.begin(),vec.end(), sa[i] + ctrl-1) - vec.begin());
            res += (upper_bound(vec.begin(),vec.end(), sa[i] + l-1) - vec.begin());
            ans += res;
        }

        //cout << sa[i] << ' ' << res << ' ' << ctrl << ' ' << l << ' ' << lcp[i] << endl;
        ctrl = min(max(l,ctrl-1), lcp[i]) + 1;
    }
    cout << ans;
}
/*
15
(())(()())(()()
5
(()()
*/
