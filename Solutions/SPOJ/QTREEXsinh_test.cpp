#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("test.inp","w",stdout);
    srand(time(NULL));
    printf("1\n");
    int n = 100, q = 100;
    printf("%d\n",n);
    for(int i=2;i<=n;i++)
        printf("%d %d %d\n",i,rand()%(i-1)+1,rand()%100000);
    while(q--){
        int type = rand()%3;
        if (type == 0)
            printf("QUERY %d %d\n",rand()%n+1,rand()%n+1);
        else if (type == 1)
            printf("CHANGE %d %d\n",rand()%(n-1)+1,rand()%n+1);
        else
            printf("NEGATE %d %d\n",rand()%n+1,rand()%n+1);
    }
    printf("DONE\n");
}
