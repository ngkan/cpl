#include <bits/stdc++.h>
using namespace std;
int n;
int a[200005];
int b[100005];
int mi,ma;
bool used[200005];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    mi = 1, ma = 2*n-1;
    a[1] = b[1];
    used[a[1]] = 1;
    for(int i=2;i<=n;i++){
        if (b[i] == b[i-1]){
            while(used[mi]) ++mi;
            a[2*i-2] = mi;
            used[mi] = 1;
            while(used[ma]) --ma;
            a[2*i-1] = ma;
            used[ma] = 1;
        }
        else if (b[i] < b[i-1]){
            if (used[b[i]]){
                while(used[mi]) ++mi;
                a[2*i-2] = mi;
                used[mi] = 1;
                while(used[mi]) ++mi;
                a[2*i-1] = mi;
                used[mi] = 1;
            }
            else{
                while(used[mi]) ++mi;
                a[2*i-2] = mi;
                used[mi] = 1;
                a[2*i-1] = b[i];
                used[b[i]] = 1;
            }
        }
        else{
            if (used[b[i]]){
                while(used[ma]) --ma;
                a[2*i-2] = ma;
                used[ma] = 1;
                while(used[ma]) --ma;
                a[2*i-1] = ma;
                used[ma] = 1;
            }
            else{
                while(used[ma]) --ma;
                a[2*i-2] = ma;
                used[ma] = 1;
                a[2*i-1] = b[i];
                used[b[i]] = 1;
            }
        }
    }
    for(int i=1;i<=2*n+-1;i++)
        printf("%d ",a[i]);
}
