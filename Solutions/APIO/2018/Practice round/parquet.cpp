#include <bits/stdc++.h>
using namespace std;
string s[55];
string t[55];
int n,m;
vector <pair<int,int> > trace;
bool canFlip(int x,int y){
    return (s[x][y] == 'U' && s[x+1][y] == 'D' && s[x][y+1] == 'U' && s[x+1][y+1] == 'D')
            || (s[x][y] == 'L' && s[x+1][y] == 'L' && s[x][y+1] == 'R' && s[x+1][y+1] == 'R');
}
void flip(int x,int y){
    //cout << x << ' ' << y << endl;
    assert(canFlip(x, y));
    if (s[x][y] == 'U'){
        s[x][y] = 'L', s[x+1][y] = 'L' , s[x][y+1] = 'R', s[x+1][y+1] = 'R';
    }
    else{
        s[x][y] = 'U', s[x+1][y] = 'D' , s[x][y+1] = 'U', s[x+1][y+1] = 'D';
    }
}
void fix(int x,int y){
    if (s[x][y] == t[x][y] || t[x][y] == 'R' || t[x][y] == 'D') return;// && s[x+1][y] == t[x+1][y] && s[x][y+1] == t[x][y+1]) return;
    //cout << "check " << x << ' ' << y << endl;
    for(int _=0;;_++){
        if (x == n || y == m){
            cout << 0;
            exit(0);
        }

        if (canFlip(x, y)){
            for(;_>=0;_--){
                flip(x, y);
                trace.push_back({x,y});
                if (s[x][y] == 'L') x --;
                else y--;
//                for(int i=1;i<=n;i++){
//                    cout << s[i] << endl;
//                }cout << endl;
            }
            return;
        }
        else{
            if (s[x][y] == 'U')
                y++;
            else
                x++;
        }
    }
}
int main(){
    iostream::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> s[i];
        s[i] = '0' + s[i];
    }
    for(int i=1;i<=n;i++){
        cin >> t[i];
        t[i] = '0' + t[i];
    }

    int ok = 0;
    do{
        ok = - (int) trace.size();
        for(int i=1;i<=n-1;i++){
            for(int j=1;j<=m-1;j++){
                if (s[i][j] == 'U'){
                    if (s[i][j+1] == 'U' || s[i][j+1] == 'L')
                        fix(i,j);
                }
                else if (s[i][j] == 'L'){
                    if (s[i+1][j] == 'U' || s[i+1][j] == 'L')
                        fix(i,j);
                }
            }
        }
        ok += (int)trace.size();
        //cerr << ok << endl;
    }while(ok > 0);

    cout << trace.size() << endl;
    for(auto v: trace)  cout << v.first << ' ' << v.second << '\n';
}
/*
4 4
ULRU
DUUD
UDDU
DLRD
LRLR
ULRU
DLRD
LRLR
4 4
LRLR
ULRU
DLRD
LRLR
ULRU
DUUD
UDDU
DLRD
*/
