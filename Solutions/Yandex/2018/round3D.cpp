#include <bits/stdc++.h>
using namespace std;
int read_int(){
    char c;
    bool negative = 0;
    bool check = 0;
    int res = 0;
    while(1){
        c = getchar();
        if (c == '*'){
            return -12345678;
        }
        if (c == '-')   {negative = 1; continue;}
        if (c == ' ' || c == '\n') {if (check) break; else continue;}
        check = 1;
        res = res*10 + c - '0';
    }
    if (negative)   res = -res;
    return res;
}
int n, c[100005];
vector <int> G[100005];
bool isfail = 0;
pair<double, double> dfs(int u,int p,double val){
    if (isfail) return {0,0};
    if (c[u] != -12345678){
        for(auto v: G[u]){
            if (v == p) continue;
            pair<double, double> tmp = dfs(v,u,val);
            if (1.0 * c[u] < tmp.first - val || tmp.second + val < 1.0 * c[u])
                isfail = 1;
            if (isfail) return {0,0};
        }
        return {c[u], c[u]};
    }
    double L = -12345678;
    double R = 12345678;
    for(auto v: G[u]){
        if (v == p) continue;
        pair<double, double> tmp = dfs(v,u,val);
        if (isfail) return {0,0};
        L = max(L, tmp.first-val);
        R = min(R, tmp.second+val);
    }
    if (L > R)
        isfail = 1;
    return make_pair(L, R);
}
bool check(double c){
    isfail = 0;
    dfs(1,1,c);
    return !isfail;
}
int main(){
    n = read_int();
    for(int i=1;i<=n;i++){
        c[i] = read_int();
    }
    for(int i=1;i<n;i++){
        int x = read_int(), y = read_int();
        G[x].push_back(y);
        G[y].push_back(x);
    }
    check(2.5);
    double l = 0, r = 2e6+3;
    for(int _=0;_<100;_++){
        double mid = (l+r)/2;
        if (check(mid))  r = mid;
        else l = mid;
    }
    cout << fixed << setprecision(9) << l;
}
