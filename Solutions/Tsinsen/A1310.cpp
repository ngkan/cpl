#include <bits/stdc++.h>
using namespace std;

int n,m,q;
int a[205][205], cntBig[205][205][205], valBig[205], numBig;
map <int,int> cnt;
vector <int> nen;
vector <pair<int,int> > prep[50000];
vector <pair<int,int> > all[205][205];
vector <pair<pair<int,int>,int> > ask[205][205];
int res[100005];

int bit2d[205][205];
void upd(int x,int y,int val){
    for(;x<=n;x+=x&-x){
        int Y = y;
        for(;Y<=m;Y+=Y&-Y){
            bit2d[x][Y] += val;
        }
    }
}
int get(int x,int y){
    int res = 0;
    for(;x;x-=x&-x){
        int Y = y;
        for(;Y;Y-=Y&-Y){
            res += bit2d[x][Y];
        }
    }
    return res;
}
int main(){
    iostream::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
            nen.push_back(a[i][j]);
        }
    }

    sort(nen.begin(), nen.end());
    nen.resize(unique(nen.begin(), nen.end()) - nen.begin());
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cnt[a[i][j] = lower_bound(nen.begin(), nen.end(), a[i][j]) - nen.begin() + 1]++;
        }
    }

    vector <pair<int,int> > lst;
    for(auto v: cnt)    lst.push_back(v);
    sort(lst.begin(),lst.end(),greater<pair<int,int> >());
    numBig = min(200, (int)lst.size());

    for(int k=1;k<=numBig;k++){
        valBig[k] = lst[k-1].first;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cntBig[k][i][j] = cntBig[k][i][j-1] + cntBig[k][i-1][j] - cntBig[k][i-1][j-1] + (a[i][j] == lst[k-1].first);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int pos = lower_bound(lst.begin(), lst.end(), pair<int,int>(a[i][j], (int)1e9), greater<pair<int,int> >()) - lst.begin();
            if (pos < numBig)   continue;
            prep[pos+1].push_back({i, j});
        }
    }
    for(int k=numBig+1;k<=(int)lst.size();k++){
        for(int i=0;i<prep[k].size();i++){
            for(int j=0;j<prep[k].size();j++){
                int mix = min(prep[k][i].first, prep[k][j].first);
                int miy = min(prep[k][i].second, prep[k][j].second);
                int maX = max(prep[k][i].first, prep[k][j].first);
                int may = max(prep[k][i].second, prep[k][j].second);
                all[mix][maX].push_back({miy, may});
            }
        }
    }

    cin >> q;
    for(int i=1;i<=q;i++){
        int xx, xX, yy, yY;
        cin >> xx >> yy >> xX >> yY;
        if (xx > xX)    swap(xx, xX);
        if (yy > yY)    swap(yy, yY);
        ask[xx][xX].push_back({{yy, yY}, i});
    }

    vector <int> rem[205][205];

    for(int row1=n;row1>=1;row1--){
        int pivotAsk[n+5];
        int pivotAll[n+5];
        memset(pivotAsk, 0, sizeof(pivotAsk));
        memset(pivotAll, 0, sizeof(pivotAll));
        memset(bit2d, 0, sizeof(bit2d));
        for(int row2=row1;row2<=n;row2++){
            sort(ask[row1][row2].begin(), ask[row1][row2].end(), [](pair<pair<int,int>,int> p,pair<pair<int,int>,int> q){
                    if (p.first.second != q.first.second)
                        return p.first.second < q.first.second;
                    return p.second < q.second;
                 });
            sort(all[row1][row2].begin(), all[row1][row2].end(), [](pair<int,int> p,pair<int,int> q){
                    return p.second < q.second;
                 });
        }

        for(int col=1;col<=m;col++){
//            for(int row2=row1;row2<=n;row2++){
//                sum[row2][col] = sum[row2][col-1];
//            }
            for(int row2=row1;row2<=n;row2++){
                for(auto v: rem[row2][col]){
                    upd(row2, v, 1);
                    //for(int i=v;i<=col;i++) // slow
                    //    sum[row2][i] ++;
                }
            }

            for(int row2=row1;row2<=n;row2++){
                while(pivotAll[row2] < all[row1][row2].size() && all[row1][row2][pivotAll[row2]].second <= col){
                    //for(int i=all[row1][row2][pivotAll[row2]].first;i<=all[row1][row2][pivotAll[row2]].second;i++)// slow
                    //    sum[row2][i]++;
                    upd(row2, all[row1][row2][pivotAll[row2]].first, 1);

                    rem[row2][all[row1][row2][pivotAll[row2]].second].push_back(all[row1][row2][pivotAll[row2]].first);

                    //cout << all[row1][row2][pivotAll].first << ' ' << all[row1][row2][pivotAll].second << endl;
                    pivotAll[row2]++;
                }
            }
            for(int row2=row1;row2<=n;row2++){
                while(pivotAsk[row2] < ask[row1][row2].size() && ask[row1][row2][pivotAsk[row2]].first.second <= col){
                    int id = ask[row1][row2][pivotAsk[row2]].second;
                    int col1 = ask[row1][row2][pivotAsk[row2]].first.first;
                    int col2 = ask[row1][row2][pivotAsk[row2]].first.second;

                    for(int i=1;i<=numBig;i++){
                        res[id] +=  (cntBig[i][row2][col2] - cntBig[i][row2][col1-1] - cntBig[i][row1-1][col2] + cntBig[i][row1-1][col1-1])
                                    * (cntBig[i][row2][col2] - cntBig[i][row2][col1-1] - cntBig[i][row1-1][col2] + cntBig[i][row1-1][col1-1]);
                    }
                    res[id] += get(row2, col2) - get(row2, col1-1);
                    //for(int ez=row2;ez>=row1;ez--)
                    //    res[id] += sum[ez][col2] - sum[ez][col1-1];
                    pivotAsk[row2]++;
                }
            }

        }
    }
    for(int i=1;i<=q;i++){
        cout << res[i] << '\n';
    }
}
/*
3 4
1 3 2 1
1 3 2 4
1 2 3 4
1
1 2 2 1

1 1 2 1
1 1 3 4
1 1 1 1
2 2 3 3
3 4 2 2
1 3 3 1
2 4 3 4
*/
