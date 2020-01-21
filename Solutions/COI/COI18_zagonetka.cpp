#include <bits/stdc++.h>
using namespace std;
int n, a[105];
int rev[105];
int edge[105][105];
int b[105];
// topo sort
int degin[105];
bool check(vector<int> &lst,int bound){
    for(int i=1;i<=n;i++)
        b[i] = a[i],
        degin[i] = 0;
    
    for(auto x: lst)
        for(auto y: lst)
            degin[y] += edge[x][y];
    queue <int> q;
    for(auto x: lst)
        if (!degin[x])  q.push(x);
    while(q.size()){
        int u = q.front();
        q.pop();
        b[u] = bound--;
        for(auto v:lst){
            if (edge[u][v]){
                degin[v] --;
                if (!degin[v])
                    q.push(v);
            }
        }
    }
    
    for(auto v: lst){
        if (degin[v])   return 1;
    }
    
    cout << "query ";   for(int i=1;i<=n;i++)   cout << b[i] << ' '; cout << endl;
    int res;
    cin >> res;
    return res;
}
bool called[105];
int CNT;
int cal(int x){
    called[x] = 1;
    while(1){
        bool ok = 0;
        for(int i=1;i<=n;i++)
            if (!called[i] && edge[x][i])
                ok = 1,
                cal(i);
        if (!ok)    break;
    }
    b[x] = ++CNT;
}
int main(){
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i],
        rev[a[i]] = i;
    
    for(int gap=1;gap<n;gap++){
        for(int id=1;id<=n-gap;id++){
            vector <int> lst;
    
            for(int i=1;i<=n;i++){
                if (id <= a[i] && a[i] <= id+gap)
                    lst.push_back(i);
            }
    
            // condition
            edge[rev[id]][rev[id+gap]] = 1;
            edge[rev[id+gap]][rev[id]] = !check(lst, id+gap);
            edge[rev[id]][rev[id+gap]] = 0;
        }
    }
    cout << "end" << endl;
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                for(int l=1;l<=n;l++){
                    if (edge[i][j] && edge[j][l])
                        edge[i][l] = 1;
                }
    }
    for(int i=1;i<=n;i++)
        edge[0][i] = 1;
    cal(0);
    for(int i=1;i<=n;i++)   cout << b[i] << ' '; cout << endl;
    
    CNT = 0;
    for(int i=1;i<=n;i++)   called[i] = 0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            swap(edge[i][j], edge[j][i]);
    cal(0);
    for(int i=1;i<=n;i++)   cout << n+1-b[i] << ' '; cout << endl;
}