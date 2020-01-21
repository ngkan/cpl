#include <iostream>
#include <cstdio>
using namespace std;

int n, m;
char A[1002][1002];
int get(int x, int y) {
    if (1 <= x && x <= n && 1 <= y && y <= m) return (A[x][y] == '*');
    return 0;
}
short M[1002][1002], S[1002][1002], hitL_S[1002][1002], hitL_M[1002][1002], hitU_S[1002][1002], hitU_M[1002][1002];
short f[1002][1002]; int cnt[1002][1002];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("test.inp", "r", stdin);
    freopen("sol.out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) {
        cin >> A[i][j];
        M[i][j] = M[i - 1][j - 1] + get(i, j);
        S[i][j] = S[i - 1][j + 1] + get(i, j);
        hitL_S[i][j] = hitL_S[i - 1][j + 1] + (get(i, j) && get(i, j - 1));
        hitU_S[i][j] = hitU_S[i - 1][j + 1] + (get(i, j) && get(i - 1, j));
        hitL_M[i][j] = hitL_M[i - 1][j - 1] + (get(i, j) && get(i, j - 1));
        hitU_M[i][j] = hitU_M[i - 1][j - 1] + (get(i, j) && get(i - 1, j));
    }
    int mx = get(1, 1), X = 1, Y = 1, R = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (j == 1) {
                    f[i][j] = 0; cnt[i][j] = get(i, j);
                    if (mx < cnt[i][j]) {
                        mx = cnt[i][j]; X = i, Y = j, R = f[i][j];
                    }
                    continue;
            }
            int Rbound = j - 1 + f[i][j - 1], Ubound = i - f[i][j - 1], Dbound = i + f[i][j - 1], Lbound = j - 1 - f[i][j - 1];
            int corr = 1;
            f[i][j] = f[i][j - 1];
            if (f[i][j - 1] > 0) {
                if (j + f[i][j - 1] > m) corr = 0;
                if (corr && ((hitU_M[i][Rbound] - hitU_M[Ubound][j - 1]) || (hitU_S[Dbound][j] - hitU_S[i][Rbound + 1]))) corr = 0;
                if (corr && ((hitL_M[i][Rbound + 1] - hitL_M[Ubound][j]) || (hitL_S[Dbound - 1][j + 1] - hitL_S[i][Rbound + 1]))) corr = 0;
                if (!corr) { f[i][j] = max(f[i][j - 1] - 1, 0); }
            }
            if (corr) {
                if (j + f[i][j - 1] + 1 > m || i + f[i][j - 1] + 1 > n || i - f[i][j - 1] - 1 < 1) corr = 0;
                if (corr && ((hitU_M[i][Rbound] - hitU_M[Ubound][j - 1]) || (hitU_S[Dbound][j] - hitU_S[i][Rbound + 1]))) corr = 0;
                if (corr && ((hitL_M[i][Rbound + 1] - hitL_M[Ubound - 1][j - 1]) || (hitL_S[Dbound][j] - hitL_S[i][Rbound + 1]))) corr = 0;
                if (corr && ((hitU_M[i][Rbound + 1] - hitU_M[Ubound - 1][j - 1]) || (hitU_S[Dbound + 1][j] - hitU_S[i][Rbound + 2]))) corr = 0;
                if (corr && ((hitL_M[i][Rbound + 2] - hitL_M[Ubound - 1][j]) || (hitL_S[Dbound][j + 1] - hitL_S[i][Rbound + 2]))) corr = 0;
                if (corr) f[i][j] = f[i][j - 1] + 1;
            }
            cnt[i][j] = cnt[i][j - 1];
            if (f[i][j] == f[i][j - 1]) {
                cnt[i][j] += M[i][Rbound + 1] - M[Ubound - 1][j - 1] + S[Dbound][j] - S[i][Rbound + 1];
                cnt[i][j] -= M[Dbound][j - 1] - M[i][Lbound] + S[i][Lbound] - S[Ubound - 1][j];
            }
            else if (f[i][j] == f[i][j - 1] - 1) {
                cnt[i][j] -= M[Dbound][j - 1] - M[i][Lbound] + S[i][Lbound] - S[Ubound - 1][j];
                cnt[i][j] -= M[Dbound - 1][j - 1] - M[i][Lbound + 1] + S[i][Lbound + 1] - S[Ubound][j];
            } else {
                cnt[i][j] += M[i][Rbound + 1] - M[Ubound - 1][j - 1] + S[Dbound][j] - S[i][Rbound + 1];
                cnt[i][j] += M[i][Rbound + 2] - M[Ubound - 2][j - 1] + S[Dbound + 1][j] - S[i][Rbound + 2];
            }
            if (mx < cnt[i][j]) {
                mx = cnt[i][j]; X = i, Y = j, R = f[i][j];
            }
            //cerr << i << ' ' << j << ' ' << f[i][j] << ' ' << cnt[i][j] << endl;
        }
    }
    cout << mx << ' ' << X << ' ' << Y << ' ' << R << endl;
}
