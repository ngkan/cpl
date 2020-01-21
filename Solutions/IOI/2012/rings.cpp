#include <bits/stdc++.h>
#include "grader.h"
using namespace std;
const int N = (int) 1e6+5;
struct myDsu{
    int dsup[N];
    int dsu_p(int x){
        return dsup[x] == x ? x : dsup[x] = dsu_p(dsup[x]);
    }
    void dsu_union(int x,int y){
        x = dsu_p(x);
        y = dsu_p(y);
        dsup[y] = x;
    }
};
int n;
vector <int> degThreeList, importantList;
vector <int> G[N];
int noCritical;
int cntAllDeg[10][5], numSubGraph[10], deg[10][N];
myDsu dsu[10];
void Init(int NN){
    n = numSubGraph[0] = cntAllDeg[0][0] = NN;
    for(int j=0;j<10;j++){
        for(int i=0;i<n;i++)
            dsu[j].dsup[i] = i;
    }
    for(int j=1;j<10;j++){
        numSubGraph[j] = cntAllDeg[j][0] = n-1;
    }
}
void Link(int A,int B,int pos){
    assert(A != importantList[pos] && B != importantList[pos]);
    if (deg[pos+1][A] <= 3)   cntAllDeg[pos+1][deg[pos+1][A]] --, cntAllDeg[pos+1][deg[pos+1][A]+1] ++;
    if (deg[pos+1][B] <= 3)   cntAllDeg[pos+1][deg[pos+1][B]] --, cntAllDeg[pos+1][deg[pos+1][B]+1] ++;
    if (dsu[pos+1].dsu_p(A) != dsu[pos+1].dsu_p(B)){
        dsu[pos+1].dsu_union(A, B);
        numSubGraph[pos+1] --;
    }
    deg[pos+1][A] ++;
    deg[pos+1][B] ++;
}
void buildImportant(int pos){
    for(int i=0;i<n;i++)    deg[pos+1][i] = 0, dsu[pos+1].dsup[i] = i;
    cntAllDeg[pos+1][0] = n-1;
    cntAllDeg[pos+1][1] = cntAllDeg[pos+1][2] = cntAllDeg[pos+1][3] = cntAllDeg[pos+1][4] = 0;
    numSubGraph[pos+1] = n-1;

    for(int u=0;u<n;u++){
        if (u != importantList[pos]){
            for(auto v: G[u]){
                if (v != importantList[pos] && u < v){
                    Link(u, v, pos);
                }
            }
        }
    }
}
void Link(int A, int B){
    if (noCritical) return;
    int cntLastDeg3 = cntAllDeg[0][3];

    if (G[A].size() <= 3)   cntAllDeg[0][G[A].size()] --, cntAllDeg[0][G[A].size()+1] ++;
    if (G[B].size() <= 3)   cntAllDeg[0][G[B].size()] --, cntAllDeg[0][G[B].size()+1] ++;
    G[A].push_back(B);
    G[B].push_back(A);

    if (dsu[0].dsu_p(A) != dsu[0].dsu_p(B))
        dsu[0].dsu_union(A, B),
        numSubGraph[0] --;

    for(int i=0;i<importantList.size();i++){
        if (A != importantList[i] && B != importantList[i])
            Link(A, B, i);
    }

    if (cntAllDeg[0][4] > 1){
        noCritical = 1;
        return;
    }
    if (cntAllDeg[0][4] == 0 && cntAllDeg[0][3] > 4){
        noCritical = 1;
        return;
    }

    if (cntAllDeg[0][4] == 1){
        static bool already = 0;
        if (already)    return;
        already = 1;
        importantList.clear();
        for(int i=0;i<n;i++)    if (G[i].size() > 3)    importantList.push_back(i);
        buildImportant(0);
        return;
    }

    if (cntAllDeg[0][3] != cntLastDeg3){
        importantList.clear();
        if (cntAllDeg[0][3] <= 2){
            for(int i=0;i<n;i++){
                if (G[i].size() == 3){
                    importantList.push_back(i);
                    for(auto v: G[i])   importantList.push_back(v);
                }
            }
        }
        else{
            for(int i=0;i<n;i++){
                if (G[i].size() == 3){
                    importantList.push_back(i);
                }
            }
        }
        for(int i=0;i<importantList.size();i++)
            buildImportant(i);
    }
}

bool cyclevisited[N];
int dfsCycle(int u){
    cyclevisited[u] = 1;
    int cnt = 1;
    if (G[u].size() != 2)   cnt = -1;
    for(auto v: G[u]){
        if (cyclevisited[v]) continue;
        int val = dfsCycle(v);
        if (val == -1 || cnt == -1) cnt = -1;
        else cnt += val;
    }
    return cnt;
}
int CountCritical(){
    if (noCritical) return 0;

    if (importantList.empty()){
        // chain and cycle
        // count chain (n0 deg 1 / 2)
        // count cycle
        int numChain = cntAllDeg[0][1] / 2;
        int numCycle = numSubGraph[0] - cntAllDeg[0][0] - numChain;
        //cout << "ask " << numCycle << endl;
        if (numCycle >= 2){
            noCritical = 1;
            return 0;
        }
        else if (numCycle == 1){
            static int cycleSize = 0;
            if (!cycleSize){
                for(int i=0;i<n;i++){
                    if (!cyclevisited[i]){
                        cycleSize = dfsCycle(i);
                        if (cycleSize > 0)  break;
                    }
                }
            }
            return cycleSize;
        }
        else{
            return n;
        }
    }
    else{
        set <int> res;
        for(int i=0;i<importantList.size();i++){
            if (cntAllDeg[i+1][3] || cntAllDeg[i+1][4]){
                continue;
            }
            int numChain = cntAllDeg[i+1][1] / 2;
            int numCycle = numSubGraph[i+1] - cntAllDeg[i+1][0] - numChain;
            if (!numCycle)
                res.insert(importantList[i]);
        }
        return res.size();
    }
}

//int main(){
//    int mjk;
//    int q;
//    cin >> mjk >> q;
//    Init(mjk);
//    while(q--){
//        int a;
//        cin >> a;
//        if (a == -1){
//            cout << CountCritical() << endl;
//        }
//        else{
//            int b;
//            cin >> b;
//            Link(a,b);
//        }
////        cout << importantList.size() << endl;
////        for(auto v: importantList)  cout << v << ' '; cout << endl;
//    }
//}

