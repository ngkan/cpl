#include "train.h"
#include <bits/stdc++.h>
using namespace std;
#define AREZOU 1
#define BORZOU 0

int n, m;
vector <int> G[5005];
vector <int> Gback[5005];
int owner[5005];
int chargingStation[5005];
int result[5005];
int deg[5005];
bool  visited[5005], ok[5005], del[5005];
void solve(vector <int> lst){
    memset(deg, 0, sizeof(deg));
    memset(visited, 0, sizeof(visited));
    memset(ok, 0, sizeof(ok));

    for(auto u: lst){
        ok[u] = 1;
        for(auto v: Gback[u]){
            if (!del[v])  deg[v] ++;
        }
    }

    vector <int> goodForArezou;
    vector <int> goodForBorzou;
    queue <int> q;

    for(auto v: lst)
        if (chargingStation[v]) q.push(v), visited[v] = 1;

    while(q.size()){
        int u = q.front();
        q.pop();
        goodForArezou.push_back(u);
        for(auto v: Gback[u]){
            if (del[v]) continue;
            -- deg[v];
            if (!visited[v] && (owner[v] == AREZOU || !deg[v])){
                visited[v] = 1;
                q.push(v);
            }
        }
    }

    for(auto v: goodForArezou)  ok[v] = 0;
    memset(visited, 0, sizeof(visited));
    for(int i=0;i<n;i++){
        deg[i] = 0;
        if (ok[i])  q.push(i), visited[i] = 1;
    }

    for(auto u: lst){
        for(auto v: Gback[u]){
            if (!del[v])  deg[v] ++;
        }
    }

    while(q.size()){
        int u = q.front();
        q.pop();
        goodForBorzou.push_back(u);
        for(auto v: Gback[u]){
            if (del[v]) continue;
            -- deg[v];
            if (!visited[v] && (owner[v] == BORZOU || !deg[v])){
                visited[v] = 1;
                q.push(v);
            }
        }
    }

    for(auto v: goodForBorzou)  del[v] = 1;
    vector <int> newLst;
    for(int i=0;i<n;i++)    if (!del[i])    newLst.push_back(i);
    if (lst == newLst) {for(auto v: lst) result[v] = 1; return;}
    solve(newLst);
}

vector<int> who_wins(vector<int> A, vector<int> R, vector<int> U, vector<int> V) {
	n = A.size();
	for(int i=0;i<n;i++)
        owner[i] = A[i],
        chargingStation[i] = R[i];
    m = U.size();
    for(int i=0;i<m;i++){
        Gback[V[i]].push_back(U[i]);
    }
    vector <int> lst;
    for(int i=0;i<n;i++)    lst.push_back(i);
    solve(lst);
    vector <int> res;
    for(int i=0;i<n;i++)    res.push_back(result[i]);
    return res;
}
/*
2 4
0 1
1 0
0 0
0 1
1 0
1 1
*/
