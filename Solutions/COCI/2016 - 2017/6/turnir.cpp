#include <bits/stdc++.h>
using namespace std;
int n,N,a[(1<<20)+5],l0g2[(1<<20)+5];
vector <int> b;
int main(){
    for(int i=2;i<=(1<<20);i++)
        l0g2[i] = l0g2[i/2] + 1;
    scanf("%d",&N);
    n = (1<<N);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),
        b.push_back(a[i]);
    sort(b.begin(),b.end());
    for(int i=1;i<=n;i++){
        int x = upper_bound(b.begin(),b.end(),a[i]) - b.begin();
        printf("%d ",N - l0g2[x]);
    }
}
