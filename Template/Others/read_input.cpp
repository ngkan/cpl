int read_int(){
    char c;
    bool check = 0;
    int res = 0;
    while(1){
        c = getchar();
        if (c == '-') {check = 1; continue;}
        if (c == ' ' || c == '\n') break;
        res = res*10 + c - '0';
    }
    if (check) return -res;
    return res;
}
int read_int(){
    char c;
    bool check = 0, ok = 0;
    int res = 0;
    while(1){
        c = getchar();
        if (c == '-') {check = 1; continue;}
        if (c < '0' || c > '9') {if (!ok)    continue; else break;}
        ok = 1;
        res = (res<<3) + (res<<1) + c - '0';
    }
    if (check) return -res;
    return res;
}
ll read_ll(){
    char c;
    bool check = 0;
    ll res = 0;
    while(1){
        c = getchar();
        if (c == '-') {check = 1; continue;}
        if (c == ' ' || c == '\n') break;
        res = res*10ll + c - '0';
    }
    if (check) return -res;
    return res;
}
void put_int(int x){
    if (x < 10)
        putchar(x + '0');
    else
        put_int(x/10),
        putchar(x%10 + '0');
}
