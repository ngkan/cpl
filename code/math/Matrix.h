/**
 * Matrix
 * Author: ngkan
 * Description: Struct for matrices.
 * Status: Untested
 */


template <typename T>
struct Matrix{
    int n, m;
    vector<vector<T>> e;

    Matrix (int n=1, int m=1): n(n), m(m), e(n, vector<T>(m, 0)) {}
    Matrix (const Matrix &a): n(a.n), m(a.m), e(a.e) {}

    vector<T> operator [](int idx) { return (*this).e[idx]; }
    Matrix operator =  (Matrix M) { n=M.n; m = M.m; e = M.e; return (*this); }
    bool   operator == (Matrix M) const { return e == M.e; }

    Matrix operator * (Matrix M){
        int p = M.m;

        Matrix res(n, p);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                for(int k=0;k<p;k++)
                    e[i][k] += e[i][j] * M[j][k];

        return res;
    }

    Matrix binpow(long long p){
        assert(n == m);
        Matrix res = identity(n), tmp = *this;
        for(int i=0;i<64;i++){
            if (((p>>i)&1)) res = res * tmp;
            tmp = tmp * tmp;
        }
        return res;
    }

	T det(){
        T det = 1;
        Matrix a(*this);

        for (int i=0; i<n; ++i) {
            int k = i;
            for (int j=i+1; j<n; ++j) if (abs(a[j][i]) > abs(a[k][i]))  k = j;
            if (i != k) swap (a[i], a[k]), det = -det;
            det *= a[i][i];
            if (abs(det) < EPS) return 0;
            for (int j=0; j<n; ++j){
                a[i][j] /= a[i][i];
                if (j != i && abs (a[j][i]) > EPS)
                    for (int k=i+1; k<n; ++k)
                        a[j][k] -= a[i][k] * a[j][i];
            }
        }

        return det;
	}
	
	static Matrix identity(int n = 1){
		Matrix r(n, n);
		for(int i=0;i<n;i++)
			r.e[i][i] = 1;
		return r;
	}
};