#include <bits/stdc++.h>
using namespace std;
class GridSortMax{
public:
    int a[50][50],x[2500],y[2500];
    bool fixedx[50],fixedy[50];
    void __col(int pos1,int pos2,int n){
        for(int i=0;i<n;i++){
            swap(y[a[i][pos1]],y[a[i][pos2]]);
            swap(a[i][pos1],a[i][pos2]);
        }
    }
    void __row(int pos1,int pos2,int m){
        for(int i=0;i<m;i++){
            swap(x[a[pos1][i]],x[a[pos2][i]]);
            swap(a[pos1][i],a[pos2][i]);
        }
    }
    string findMax(int n, int m, vector <int> grid){
        memset(fixedx,0,sizeof(fixedx));
        memset(fixedy,0,sizeof(fixedy));
        for(int i=0;i<grid.size();i++)
            a[i/m][i%m] = --grid[i],
            x[grid[i]] = i/m,
            y[grid[i]] = i%m;
        string res;
        for(int i=0;i<n*m;i++){

            int X = i/m, Y = i%m;
            if (X == x[i] && Y == y[i])
                fixedx[X]=1,
                fixedy[Y]=1,
                res.push_back('1');
            else if (X == x[i]){
                if (!fixedy[Y] && !fixedy[y[i]])
                    fixedy[Y]=1,
                    fixedx[X]=1,
                    res.push_back('1'),
                    __col(Y,y[i],n);
                else
                    res.push_back('0');
            }
            else if (Y == y[i]){
                if (!fixedx[X] && !fixedx[x[i]])
                    fixedx[X]=1,
                    fixedy[Y]=1,
                    res.push_back('1'),
                    __row(X,x[i],m);
                else
                    res.push_back('0');
            }
            else{
                if (!fixedy[Y] && !fixedy[y[i]] && !fixedx[X] && !fixedx[x[i]])
                    fixedy[Y]=1,
                    fixedx[X]=1,
                    res.push_back('1'),
                    __row(X,x[i],m),
                    __col(Y,y[i],n);
                else
                    res.push_back('0');
            }
//            for(int ii=0;ii<n;ii++){
//            for(int jj=0;jj<m;jj++)
//                cout << a[ii][jj] <<' ';cout << endl;
//            }
//            cout << endl;
        }
//        for(int i=0;i<n*m;i++)
//            cout << x[i] << ' ' << y[i] << endl;
        return res;
    }
};
int as[] = { 3,9, 5,1, 10,6, 2,7, 8,11, 12,4 };
int main(){
    GridSortMax a;
    vector <int> ez; //ez.push_back(4);ez.push_back(2);ez.push_back(3);ez.push_back(1);
    for(int i=0;i<12;i++)ez.push_back(as[i]);
    cout << a.findMax(6,2,ez);
}
