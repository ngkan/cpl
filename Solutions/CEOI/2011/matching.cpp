#include <bits/stdc++.h>
using namespace std;
struct fwTree{
    int node[1000005];
    void clear(){
        for(int i=1;i<=(int)1e6;i++)
            node[i] = 0;
    }
    void upd(int pos,int val){
        for(;pos<=(int)1e6;pos+=pos&-pos)
            node[pos] += val;
    }
    int get(int pos){
        int res = 0;
        for(;pos;pos-=pos&-pos)
            res += node[pos];
        return res;
    }
};
int getInt(){
    char c;
    int res = 0;
    bool mark = 0;
    while(c = getchar()){
        if (c < '0' || '9' < c){
            if (mark)   break;
            continue;
        }
        mark = 1;
        res = res * 10 + (c - '0');
    }
    return res;
}

int n, m, a[2000005];
int val[1000005];
int prefixSuffix[2000005];
fwTree fw;
vector <int> nen;
int main(){
    // input
    n = getInt();
    m = getInt();

    for(int i=1;i<=n;i++)
        a[getInt()] = i;
    for(int i=1;i<=m;i++)
        a[n+1+i] = getInt(),
        nen.push_back(a[n+1+i]);

    sort(nen.begin(), nen.end());
    for(int i=1;i<=m;i++)
        a[n+1+i] = lower_bound(nen.begin(), nen.end(), a[n+1+i]) + 1 - nen.begin();// cout << a[i+1+n] << ' '; cout << endl;

    // val[i] = how many columns that are lower than column i when we consider only first i columns
    for(int i=1;i<=n;i++){
        val[i] = fw.get(a[i]);
        fw.upd(a[i], 1);
    }

    // prefixSuffix[i] = longest suffix at i that equals to prefix

    fw.clear();
    int pivot = 2;

    vector <int> res;
    //cout << 0 << ' ';
    for(int i=2;i<=n+m+1;i++){
        if (i == n+1){
            fw.clear();
            prefixSuffix[i] = 0;
            pivot = i+1;
            //cout << 0 << ' ';
            continue;
        }
        int tmp = prefixSuffix[i-1];
        if (tmp == n){
            while(pivot < i - prefixSuffix[tmp])
                fw.upd(a[pivot], -1),
                ++ pivot;
            tmp = prefixSuffix[tmp];
        }

        while(fw.get(a[i]) != val[tmp+1]){
            while(pivot < i - prefixSuffix[tmp])
                fw.upd(a[pivot], -1),
                ++ pivot;
            tmp = prefixSuffix[tmp];
        }
        fw.upd(a[i], 1);
        prefixSuffix[i] = tmp + 1;
        //cout << prefixSuffix[i] << ' ';
        if (i > n && prefixSuffix[i] == n)
            res.push_back(i - n - 1 - n + 1);
    }
    //cout << endl;
    printf("%d\n",res.size());
    for(auto v: res)    printf("%d ", v);
}
/*
5 10
2 1 5 3 4
5 6 3 8 12 7 1 10 11 9
*/
