#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
#define fi first
#define se second
using namespace std;
typedef pair<int,int> ii;
struct block{
    int len,pos,id;
    block(int len=0,int pos=0,int id=0): len(len), pos(pos), id(id) {}
};
bool cmp(block x,block y){
    if (x.pos == y.pos) return x.len > y.len;
    return x.pos < y.pos;
}
int n, res;
block a[100005];
vector <int> ax[100005];
set <ii> s;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d %d",&a[i].len,&a[i].pos), a[i].pos += a[i].len, a[i].id = i;
    sort(a+1,a+n+1,cmp);
    res = 1;
    ax[res].push_back(a[1].id);
    s.insert(ii(a[1].pos,1));
    set<ii>::iterator it;
    for(int i=2;i<=n;i++){
        it = s.upper_bound(ii(a[i].pos-a[i].len,100000));
        if (it == s.begin()){
            res++;
            ax[res].push_back(a[i].id);
            s.insert(ii(a[i].pos, res));
        }
        else{
            --it;
            ii ahi = *it;
            s.erase(it);
            ax[ahi.se].push_back(a[i].id);
            s.insert(ii(a[i].pos, ahi.se));
        }
    }
    printf("%d\n",res);
    for(int i=1;i<=res;i++)
        for(int j=0;j<ax[i].size();j++)
            printf("%d\n",ax[i][j]);
}
