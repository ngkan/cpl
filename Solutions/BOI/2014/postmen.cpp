#include <stdio.h>
int ctrl[500005];
int nxt[1000005], prv[1000005], id[1000005];
int head[500005], en[500005];
bool visited[500005];
int n,m;
int euler[1000005], eulersize;
int q[1000005], qsize;
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
void dfs(){
    q[qsize++] = 1;
    while(qsize){
        int u = q[qsize-1];
        bool mjk = 0;
        for(;ctrl[u];ctrl[u] = nxt[ctrl[u]]){
            int v = (u ^ head[id[ctrl[u]]] ^ en[id[ctrl[u]]]);
            if (visited[id[ctrl[u]]]) continue;
            mjk = 1;
            visited[id[ctrl[u]]] = 1;
            q[qsize++] = v;
            break;
        }

        if(mjk) continue;

        euler[eulersize++] = u;
        --qsize;
    }
}
int st[1000005], stsize;
bool used[1000005];
int main(){
    n = read_int();
    m = read_int();
    int cnt = 0;
    for(int i=1;i<=m;++i){
        int x = read_int(),y = read_int();

        if (!ctrl[x])   ctrl[x] = ++cnt;
        else    nxt[prv[x]] = ++cnt;
        id[cnt] = i;
        prv[x] = cnt;

        if (!ctrl[y])   ctrl[y] = ++cnt;
        else    nxt[prv[y]] = ++cnt;
        id[cnt] = i;
        prv[y] = cnt;

        head[i] = x;
        en[i] = y;
    }

    dfs();

    for(int i=0;i<eulersize;++i){
        if (used[euler[i]]){
            while(st[stsize-1] != euler[i]){
                printf("%d ",st[stsize-1]);
                used[st[stsize-1]] = 0;
                --stsize;
            };
            printf("%d\n",euler[i]);
        }
        else{
            st[stsize++] = euler[i];
            used[euler[i]] = 1;
        }
    }
}
