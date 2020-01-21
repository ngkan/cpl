#include "catdog.h"
#include <bits/stdc++.h>
using namespace std;
#define CAT 0
#define DOG 1

int n;
vector <int> G[100005];
int currentPet[100005];
int dp[1005][2];

void initialize(int NN, std::vector<int> A, std::vector<int> B) {
    n = NN;
    for(int i=1;i<=n;i++)   currentPet[i] = -1;

    for(int i=0;i<A.size();i++){
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }

}
void doDp(int u,int p){
    dp[u][CAT] = dp[u][DOG] = 0;

    for(auto v: G[u]){
        if (v == p) continue;
        doDp(v, u);
        if (currentPet[v] == CAT){
            dp[u][CAT] += dp[v][CAT];
            dp[u][DOG] += dp[v][CAT] + 1;
        }
        else if (currentPet[v] == DOG){
            dp[u][CAT] += dp[v][DOG] + 1;
            dp[u][DOG] += dp[v][DOG];
        }
        else{
            dp[u][CAT] += min(dp[v][CAT], dp[v][DOG] + 1);
            dp[u][DOG] += min(dp[v][CAT] + 1, dp[v][DOG]);
        }
    }
}
int result(){
    if (currentPet[1] == CAT)   return dp[1][CAT];
    else if (currentPet[1] == DOG) return dp[1][DOG];
    else return min(dp[1][CAT], dp[1][DOG]);
}

int cat(int u) {
    currentPet[u] = CAT;
    doDp(1,1);
    return result();
}

int dog(int u) {
    currentPet[u] = DOG;
    doDp(1,1);
    return result();
}

int neighbor(int u) {
    currentPet[u] = -1;
    doDp(1,1);
    return result();
}
