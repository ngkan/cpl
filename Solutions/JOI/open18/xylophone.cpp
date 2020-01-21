#include "xylophone.h"
#include <bits/stdc++.h>
using namespace std;

int ask[5005][5005];
int sign[5005][5005];
int val[5005];
void solve(int n) {

    for(int i=1;i<n;i++)
        ask[i][i+1] = query(i, i+1);
    for(int i=1;i<n-1;i++)
        ask[i][i+2] = query(i, i+2);

    // let a[2] - a[1] = ask[1][2]
    val[1] = 1;
    val[2] = ask[1][2] + 1;
    sign[1][2] = 1;

    for(int i=3;i<=n;i++){
        cerr << ask[i-2][i-1] << ' ' << ask[i-1][i] << ' ' << ask[i-2][i] << endl;
        if (ask[i-2][i-1] == ask[i-2][i]){
            // i-2 ... i ... i-1
            sign[i-1][i] = - sign[i-2][i-1];
            val[i] = val[i-1] + sign[i-1][i] * ask[i-1][i];
        }
        else if (ask[i-2][i] == ask[i-1][i]){
            // i ... i-2 ... i-1
            sign[i-1][i] = - sign[i-2][i-1];
            val[i] = val[i-1] + sign[i-1][i] * ask[i-1][i];
        }
        else{
            // i-2 ... i-1 ... i
            sign[i-1][i] = sign[i-2][i-1];
            val[i] = val[i-1] + sign[i-1][i] * ask[i-1][i];
        }
    }
    for(int i=1;i<=n;i++)   cerr << val[i] << ' '; cerr << endl;
    int mi = 1;
    for(int i=1;i<=n;i++)   mi = min(mi, val[i]);
    for(int i=1;i<=n;i++)   val[i] += 1 - mi;
    int pos1,posn;
    for(int i=1;i<=n;i++)   {if (val[i] == 1)    pos1 = i;   if (val[i] == n)    posn = i;}
    if (pos1 > posn){
        for(int i=1;i<=n;i++)   val[i] = n+1 - val[i];
    }
    for(int i=1;i<=n;i++)   cerr << val[i] << ' '; cerr << endl;
    for(int i=1;i<=n;i++)   answer(i, val[i]);
}
