#include <bits/stdc++.h>
using namespace std;

namespace FastIO{
    template<typename T>
    T read(){
        char c; bool neg = 0, met = 0;
        T res = 0;
        while((c = getchar())){
            if (c == '-') 
                met = neg = 1;
            else if (c < 48 || c > 57) 
                if (!met)    continue; else break;
            else
                met = 1,
                res = (res<<3) + (res<<1) + c - '0';
        }
        if (neg)    res = -res;
        return res;
    }

    template<typename T>
    void write(T x){
        if (x < 0)          putchar('-'), write(-x);
        else if (x == 0)    putchar('0');
        else                putchar('0' + x%10), x /= 10;
    }
}
