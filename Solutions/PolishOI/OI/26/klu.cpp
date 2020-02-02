/*  
    ┬┴┬┴┤(･_├┬┴┬┴ hiding from those WAs
*/

#include <bits/stdc++.h>
using namespace std;

namespace FastIO{
    template<typename T>
    T read(){
        char c; bool neg = 0, met = 0;
        T res = 0;
        while((c = getchar())){
            if (c == '-') 
                met = neg = 1;
            else if (c < 48 || c > 57) 
                if (!met)    continue; else break;
            else
                met = 1,
                res = (res<<3) + (res<<1) + c - '0';
        }
        if (neg)    res = -res;
        return res;
    }
}

int n, m;
int a[2000000], l[2000000], r[2000000];
void eval(int bit){
    vector <int> b[2];
    for(int i=0;i<m;i++)    b[(a[i]>>bit)&1].push_back(i);
    for(int i=0;i<m;i++)    b[(a[i]>>bit)&1].push_back(i);
    for(int i=0;i<m;i++)    b[(a[i]>>bit)&1].push_back(i);

    if (b[0].empty() || b[1].empty())
        return;
    
    int pivot[2] = {};

    for(int i=0;i<m;i++){
        int x[] = { b[0][pivot[0]] + (b[0][pivot[0]] < i ? m : 0),
                    b[1][pivot[1]] + (b[1][pivot[1]] < i ? m : 0) };
        
        int y[] = { b[0][pivot[0]+b[0].size()/3-1] + (b[0][pivot[0]+b[0].size()/3-1] < i ? m : 0),
                    b[1][pivot[1]+b[1].size()/3-1] + (b[1][pivot[1]+b[1].size()/3-1] < i ? m : 0) };

        l[i] = max(l[i], max(x[0], x[1]));
        r[i] = min(r[i], min(y[0], y[1]));

        pivot[(a[i]>>bit)&1] ++;
    }
}
void ngk(){
    n = FastIO::read<int>();
    m = FastIO::read<int>();
    for(int i=0;i<m;i++)
        a[i] = FastIO::read<int>(),
        l[i] = i, r[i] = i + m;
    
    for(int i=0;i<n;i++)
        eval(i);
    
    long long ans = 0;
    for(int i=0;i<m;i++)
        ans += max(0, r[i] - l[i]);
    
    cout << ans/2;
}

int main(int argc, char *argv[]){
    iostream::sync_with_stdio(0);
    int test = 1;
    while(test--){
        ngk();
    }
    return 0;
}