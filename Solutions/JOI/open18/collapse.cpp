#include "collapse.h"
#include <bits/stdc++.h>
using namespace std;

int dsup[5005];
int rem[5005][5005];
int dsu_p(int x){
    return x == dsup[x] ? x : dsup[x] = dsu_p(dsup[x]);
}
void dsu_union(int x,int y){
    dsup[dsu_p(y)] = dsu_p(x);
}
int n, totalE, q;
std::vector<int> simulateCollapse(
	int NN,
	std::vector<int> T,
	std::vector<int> X,
	std::vector<int> Y,
	std::vector<int> W,
	std::vector<int> P
) {

    n = NN;
    totalE = T.size();
    q = W.size();
    vector <int> result;
    if (n > 5000)   return result;

    for(int _=0;_<q;_++){
        for(int i=0;i<n;i++)    dsup[i] = i;

        for(int j=0;j<=min(totalE-1, W[_]);j++){
            if (X[j] > Y[j])    swap(X[j], Y[j]);
            if (X[j] <= P[_] && P[_] < Y[j])    continue;
            if (T[j] == 1)  rem[X[j]][Y[j]]++;
            else    rem[X[j]][Y[j]] --;
        }
        for(int j=0;j<=min(totalE-1, W[_]);j++){
            if (X[j] > Y[j])    swap(X[j], Y[j]);
            if (X[j] <= P[_] && P[_] < Y[j])    continue;

            if (rem[X[j]][Y[j]]) dsu_union(X[j], Y[j]), rem[X[j]][Y[j]] = 0;
        }

        int cnt = 0;
        for(int i=0;i<n;i++)    cnt += dsu_p(i) == i;
        result.push_back(cnt);
    }
    return result;
}
