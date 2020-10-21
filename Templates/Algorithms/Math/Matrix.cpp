#include <bits/stdc++.h>
using namespace std;

/*
    Struct for matrix
    Status: Untested
*/

template <typename T>
struct Matrix{
    int n, m;
    vector<vector<T>> ele;
    Matrix (int n=0,int m=0): n(n), m(m), ele(n, vector<T>(m, 0)) {}
    
    bool operator == (Matrix M) { return ele == M.ele; }
    void operator  = (Matrix M) { ele == M.ele, n = M.n, m = M.m; }

    Matrix operator * (Matrix M){
        T p = M.m;
        Matrix res(n, p);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                for(int k=1;k<=p;k++)
                    res.ele[i][k] += ele[i][j] * M.ele[j][k];
        return res;
    }
    Matrix pow(long long p){
        assert(n == m);

        Matrix res(n, m), tmp = *this;

        for(int i=0;i<64;i++){
            if (((p>>i)&1)) res = res * tmp;
            tmp = tmp * tmp;
        }

        return res;
    }
};
