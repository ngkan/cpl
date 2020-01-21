#include <bits/stdc++.h>
using namespace std;
int main(){
   int n;
   scanf("%d",&n);
   if (n%2==0) printf("-1");
   else{
      for(int i=0;i<n;i++) printf("%d ",i); printf("\n");
      for(int i=0;i<n;i++) printf("%d ",i); printf("\n");
      for(int i=0;i<n;i++) printf("%d ",2*i%n);
   }
}
