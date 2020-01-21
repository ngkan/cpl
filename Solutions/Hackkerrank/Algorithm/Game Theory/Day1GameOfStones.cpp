#include <iostream>
using namespace std;
int test,n;
int res[101];
int main(){
    cin >> test;
    res[0] = 0;res[1] = 0;res[2] = 1;res[3] = 1;res[4] = 1;res[5] = 1;
    for(int i=6;i<=100;i++) res[i] = !(res[i-2] & res[i-3] & res[i-5]);
    while(test--){
        cin >> n;
        if (res[n]) cout <<"First\n";
        else cout << "Second\n";
    }
}
