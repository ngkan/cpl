#include <bits/stdc++.h>
using namespace std;
int read_int(){
    char c;
    bool negative = 0;
    bool check = 0;
    int res = 0;
    while(1){
        c = getchar();
        if (c == '-')   {negative = 1; continue;}
        if (c == ' ' || c == '\n') {if (check) break; else continue;}
        check = 1;
        res = res*10 + c - '0';
    }
    if (negative)   res = -res;
    return res;
}
int query, len, maxP;
inline int fix2(int x){
    return x = (x % (2*len) + (2*len)) % (2*len);
}
int dataSize;
int sum[1005][2005];
int diff[2005][2005];
int nxt[2005][2005];
int prv[2005][2005];

inline int getSum(int val,int l,int r){
    if (l <= r){
        if (l == 0) return sum[val][r];
        else return sum[val][r] - sum[val][l-1];
    }
    else{
        return sum[val][2*len-1] - sum[val][l-1] + sum[val][r];
    }
}
pair<int,int> rember[1000005];

int ask(int t,int queryL,int queryR){
    int ans = 0;
    int normL = fix2(-t);
    int normR = fix2(len-1-t);
    queryL = fix2(queryL-t);
    queryR = fix2(queryR-t);

    for(int val = 0; val <= maxP; val ++){
        if (queryL != normL && queryL != prv[normL][1] && diff[prv[queryL][1]][normL] >= val)
            ans += getSum(val, normL, prv[queryL][val+1]);
        if (queryR != normR && queryR != nxt[normR][1])
            ans += getSum(val, nxt[queryR][1], normR);
    }

    queryL = fix2(2*len - fix2(queryL+t) -t);
    queryR = fix2(2*len - fix2(queryR+t) -t);
    swap(queryL, queryR);

    for(int val = 0; val <= maxP; val ++){
        if (queryL != nxt[normR][1] && queryL != normR)
            ans += getSum(val, nxt[normR][1], prv[queryL][1]);
        if (queryR != prv[normL][1] && queryR != normL && diff[prv[normL][1]][nxt[queryR][1]] >= val)
            ans += getSum(val, nxt[queryR][val+1], prv[normL][1]);
    }
    return dataSize - ans;
}
int main(){
    query = read_int();
    len = read_int();

    for(int i=0;i<2*len;i++){
        for(int j=0;j<2*len;j++){
            if (i > j)  diff[i][j] = i - j;
            else        diff[i][j] = i - j + 2 * len;

            if (i > j)  nxt[i][j-i+2*len] = j;
            else        nxt[i][j-i]   = j;

            if (i > j)  prv[i][i-j] = j;
            else        prv[i][i-j+2*len]   = j;
        }
    }


    while(query--){
        int type = read_int(), t, c, l, r, d;

        if (type == 1){
            dataSize ++;
            t = read_int(), c = read_int(), l = read_int(), r = read_int(), d = read_int();
            int val = r - l;
            if (d == -1)    l = 2*len-l;
            l = fix2(l - t);
            for(int i = l; i < 2*len; i ++)   sum[val][i]++;
            maxP = max(maxP, val);
            rember[c] = pair<int,int> (val, l);
        }
        else if (type == 2){
            t = read_int(), l = read_int(), r = read_int();
            printf("%d\n", ask(t, l, r));
        }
        else{
            dataSize --;
            t = read_int(), c = read_int();
            for(int i = rember[c].second; i < 2*len; i ++)    sum[rember[c].first][i] --;
        }
    }
}
