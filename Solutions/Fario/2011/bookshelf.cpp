#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
int n,m,q,a[100005];
bool visited[100005];
void goleft(int x){
    if (visited[x]) return;
    visited[x] = 1;
    if (x>1 && a[x-1] >= a[x])
        goleft(x-1);
}
void goright(int x){
    if (visited[x]) return;
    visited[x] = 1;
    if (x<n && a[x] <= a[x+1])
        goright(x+1);
}
int main(){
    scanf("%d %d %d",&n,&m,&q);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    while(m--){
        int x;
        scanf("%d",&x);
        visited[x] = 1;
        if (x>1 && a[x-1] >= a[x]) goleft(x-1);
        if (x<n && a[x+1] >= a[x]) goright(x+1);
    }
    while(q--){
        int x;
        scanf("%d",&x);
        m+=visited[x];
    }
    printf("%d",m+1);
}
