#include <bits/stdc++.h>
using namespace std;
struct matrix{
    int m,n;
    vector < vector<double> > ele;
    void init(int x,int y){
        m = x, n = y;
        ele.assign(m+1,vector<double>());
        for(int i=1;i<=m;i++)   ele[i].assign(n+1,0);
        return;
    }
    void operator = (matrix y){
        ele = y.ele;
        m = y.m;
        n = y.n;
    }
    matrix operator * (matrix y){
        int p = y.n;
        matrix res;
        res.init(m,p);
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
                for(int k=1;k<=p;k++)
                    res.ele[i][k] = res.ele[i][k] + ele[i][j] * y.ele[j][k];
        return res;
    }
    void mullog(int p){
        p-=1;
        p = max(p,0);
        matrix tmp, res;
        res.m = tmp.m = m;
        res.n = tmp.n = n;
        res.ele = tmp.ele = ele;
        for(int i=0;i<64;i++){
            if (((1ull<<i) & p)) res = res * tmp;
            tmp = tmp * tmp;
        }
        ele = res.ele;
    }
};
int test;
int n;
double ww,wb,lw,lb;
int main(){
	freopen("chess.txt","r",stdin);
	freopen("chess.out","w",stdout);
	cout << fixed << setprecision(9);
	iostream::sync_with_stdio(0);
	cin>> test;
	for(int t=1;t<=test;t++){
		cin >> n >> ww >> wb >> lw >> lb;
		if (n == 1)  
			cout << "Case #" << t << ": " << ww << '\n';
		else{
			matrix a;
			a.init(1,2);
			bool swaped = 0;
			if (lw < lb) swap(lb,lw),swaped = 1;
			a.ele[1][1] = max(ww,wb),
			a.ele[1][2] = min(ww,wb);
			matrix b;
			b.init(2,2);
			b.ele[1][1] = lw;
			b.ele[2][1] = 1.0 - lw;
			b.ele[1][2] = lb;
			b.ele[2][2] = 1.0 - lb;
			//cout << b.ele[1][1] << ' ' << b.ele[1][2] << endl;
			//cout << b.ele[2][1] << ' ' << b.ele[2][2] << endl;
			b.mullog(n-1);
			a = a * b;
			//cout << b.ele[1][1] << ' ' << b.ele[1][2] << endl;
			//cout << b.ele[2][1] << ' ' << b.ele[2][2] << endl;
			if (!swaped) cout << "Case #" << t << ": " << a.ele[1][1] << '\n';
			else cout << "Case #" << t << ": " << a.ele[1][2] << '\n';
			//cout << a.ele[1][1] << ' ' << a.ele[1][2] << '\n';
		}
	}
}
