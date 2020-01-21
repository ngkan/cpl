#include <stdio.h>
#include <iostream>
using namespace std;
const int N = (int) 1e5+5;
int n,q,xored;
int trie_id[30*N][2], trie_val[30*N], trie_next = 0;
int main(){
    for(int i=0;i<30*N;i++) for(int j=0;j<2;j++) trie_id[i][j] = -1;
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        int idnow = 0;
        for(int j=30;j>=0;j--){
            trie_val[idnow] ++;
            int ahi = (x & (1<<j)) > 0;
            if (trie_id[idnow][ahi] == -1)
                idnow = trie_id[idnow][ahi] = ++trie_next;
            else
                idnow = trie_id[idnow][ahi];
        }
        trie_val[idnow] ++;
    }

    while(q--){
        char c[10];
        int x;
        scanf("%s %d",c,&x);
        if (c[0] == 'F'){

            int idnow = 0, res = 0;
            for(int i=30;i>=0;i--){
                int ahi = 1 - ((xored & (1<<i)) > 0);
                if (trie_id[idnow][ahi] == -1)
                    res += (!ahi) * (1<<i),
                    idnow = trie_id[idnow][(!ahi)];
                else if (trie_val[trie_id[idnow][ahi]] >= x)
                    res += ahi * (1<<i),
                    idnow = trie_id[idnow][ahi];
                else
                    x -= trie_val[trie_id[idnow][ahi]],
                    res += (!ahi) * (1<<i),
                    idnow = trie_id[idnow][(!ahi)];
            }
            printf("%d\n",(res^xored));
        }
        else
            xored ^= x;
    }
}
