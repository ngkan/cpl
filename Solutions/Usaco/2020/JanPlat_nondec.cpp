/*  
    ┬┴┬┴┤(･_├┬┴┬┴ hiding from those WAs
*/

#include <bits/stdc++.h>
using namespace std;

const int mod = (int) 1e9+7;
int quickmod(int x){
    if (x >= mod)   x -= mod;
    return x;
}
struct query{
    int l, r, id;
    query(int l=0,int r=0,int id=0): l(l), r(r), id(id) {}
};

int n, lim;
int a[50005];
int q;
vector <query> b;
int res[200005];

int f[50005][2][21];/*
0: subseqs that end at i and begin with (number)
1: subseqs that begin from i and end with (number)
*/
int temp[50005][2][21];
void answer_query(int l,int r, vector<query> &ask){
    if (l == r){
        for(auto v: ask)
            res[v.id] = 2;
        return;
    }

    for(int i=l;i<=r;i++)
        for(int t=0;t<2;t++)
            for(int k=1;k<=lim;k++)
                temp[i][t][k] = 0;
    
    int mid = (l+r)/2;
    for(int i=mid;i>=l;i--){
        for(int k=1;k<=lim;k++)
            temp[i][1][k] = quickmod(temp[i+1][1][k] + f[i][1][k]);
    }
    for(int i=mid+1;i<=r;i++){
        for(int k=1;k<=lim;k++)
            temp[i][0][k] = quickmod(temp[i-1][0][k] + f[i][0][k]);
    }

    for(auto v: ask){
        int id = v.id,  ll = v.l, rr = v.r;
        for(int k=1;k<=lim;k++)
            res[id] = quickmod(res[id] + temp[ll][1][k]),
            res[id] = quickmod(res[id] + temp[rr][0][k]);

        for(int k=1;k<=lim;k++)
            for(int kk=k;kk<=lim;kk++)
                res[id] = quickmod(1ll * temp[ll][1][k] * temp[rr][0][kk] % mod + res[id]);
        res[id] = quickmod(res[id] + 1);
    }
}

void solve(int l,int r, vector <query> &ask){
    if (l == r){
        f[l][0][a[l]] = 1;
        f[l][1][a[l]] = 1;
        answer_query(l, r, ask);
        return;
    }
    
    int mid = (l+r)/2;
    vector <query> lef, rig, cur;

    for(auto v: ask){
        if (v.r <= mid)         lef.push_back(v);
        else if (mid+1 <= v.l)  rig.push_back(v);
        else                    cur.push_back(v);
    }
    
    solve(l, mid,   lef);
    solve(mid+1, r, rig);

    // answer query
    answer_query(l, r, cur);

    int tempL[lim+1][lim+1];
    int tempR[lim+1][lim+1];
    memset(tempL, 0, sizeof(tempL));
    memset(tempR, 0, sizeof(tempR));

    // temp array for dp
    for(int i=l;i<=r;i++)
        for(int t=0;t<2;t++)
            for(int k=1;k<=lim;k++)
                temp[i][t][k] = 0;

    // count n0 of subseq 0 on the left
    for(int i=l;i<=mid;i++){
        for(int k=1;k<=a[i];k++)
            tempL[k][a[i]] = quickmod(tempL[k][a[i]] + f[i][0][k]);
    }
    // make the array partial sums
    for(int i=1;i<=lim;i++){
        for(int j=i+1;j<=lim;j++)
            tempL[i][j] = quickmod(tempL[i][j] + tempL[i][j-1]);
    }
    // calculate update for 0
    for(int i=mid+1;i<=r;i++){
        for(int beg=1;beg<=a[i];beg++){
            for(int k=beg;k<=a[i];k++){
                temp[i][0][beg] = quickmod(1ll * f[i][0][k] * tempL[beg][k] % mod + temp[i][0][beg]);
            }
        }
    }
    
    // count n0 of subseq 1 on the right
    for(int i=mid+1;i<=r;i++){
        for(int k=a[i];k<=lim;k++)
            tempR[a[i]][k] = quickmod(tempR[a[i]][k] + f[i][1][k]);
    }
    // make the array partial sums
    for(int i=lim-1;i>=1;i--){
        for(int j=i;j<=lim;j++)
            tempR[i][j] = quickmod(tempR[i][j] + tempR[i+1][j]);
    }
    // calculate update for 1
    for(int i=l;i<=mid;i++){
        for(int end=a[i];end<=lim;end++){
            for(int k=a[i];k<=end;k++){
                temp[i][1][end] = quickmod(1ll * f[i][1][k] * tempR[k][end] % mod + temp[i][1][end]);
            }
        }
    }
    // merge
    for(int i=l;i<=r;i++)
        for(int t=0;t<2;t++)
            for(int k=1;k<=lim;k++)
                f[i][t][k] = quickmod(f[i][t][k] + temp[i][t][k]);
}

void init(){
    cin >> n >> lim;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    
    cin >> q;
    for(int i=1;i<=q;i++){
        int l, r;
        cin >> l >> r;
        b.push_back(query(l, r, i));
    }
}

void ngk(){
    init();
    solve(1, n, b);
    for(int i=1;i<=q;i++)
        cout << res[i] << '\n';
}

int main(int argc, char *argv[]){
    freopen("nondec.in","r",stdin);
    freopen("nondec.out","w",stdout);
    iostream::sync_with_stdio(0);
    int test = 1;
    while(test--){
        ngk();
    }
    return 0;
}