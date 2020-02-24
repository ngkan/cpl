/*  
    ┬┴┬┴┤(･_├┬┴┬┴ hiding from those WAs
    Status: AC
    Simple nim problem
    Basically check if n xor 2n xor 3n equals to 0
*/

#include <bits/stdc++.h>
using namespace std;

void ngk(){
	int cnt = 0;
	for(int i=1;i<=(1<<30);i++){
		if (!((3ll * i) ^ (2ll * i) ^ (1ll * i)))
			cnt ++;
	}    
	cout << cnt;
}

int main(int argc, char *argv[]){
    iostream::sync_with_stdio(0);
    int test = 1;
    while(test--){
        ngk();
    }
    return 0;
}
