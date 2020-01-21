#include "bubblesort2.h"
#include <bits/stdc++.h>
using namespace std;

struct fwTree2D{
    int limX, limY;
    map <int,int> node[500005];
    fwTree(int limX=0,int limY=0): limX(limX), limY(limY) {}

    void upd(int posX, int posY, int val){
        for(;posX<=limX;posX+=posX&-posX){
            int y = powY;
            for(;y<=limY;y+=y&-y)
                node[posX][y] += val;
        }
    }

    int get(int posX,int posY){
        int res = 0;
        for(;posX;posX-=posX&-posX){
            int y = powY;
            for(;y;y-=y&-y)
                res += node[posX][y];
        }
        return res;
    }
};

int n, q;
int a[500005];
vector <int> lst;
fwTree2D fwCnt;
vector<int> countScans(std::vector<int> A,std::vector<int> X,std::vector<int> V){
	n = A.size();
	q = X.size();

	for(auto v: A)  lst.push_back(v);
    for(auto v: V)  lst.push_back(v);
    sort(lst.begin(), lst.end());
    lst.resize(lst.unique(lst.begin(), lst.end()) - lst.begin());

    for(int i=0;i<n;i++)    A[i] = lower_bound(lst.begin(), lst.end(), A[i]) - lst.begin() + 1;
    for(int i=0;i<q;i++)    V[i] = lower_bound(lst.begin(), lst.end(), V[i]) - lst.begin() + 1;
    for(int i=0;i<q;i++)    X[i]++;

    for(int i=1;i<=n;i++)   a[i] = A[i-1];

	fwCnt.limX = n;
	fwCnt.limY = lst.size();
    for(int i=1;i<=n;i++){
        fwCnt.upd()
    }

	return result;
}
