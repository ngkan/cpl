/*  
    ┬┴┬┴┤(･_├┬┴┬┴ hiding from those WAs
*/

#include <bits/stdc++.h>
using namespace std;

int temp[5005];
int g[5005];

void prep(){
	for(int i=2;i<=5000;i++){
		for(int j=0;j<=5000;j++)
			temp[j] = 0;
			
		for(int j=0;j<=i-2;j++){
			temp[g[j] ^ g[i-2-j]] = 1;
		}
			
		for(int j=0;j<=5000;j++)
			if (!temp[j]) {g[i] = j; break;}
	}
}

void ngk(){
	int n;
	cin >> n;
	if (g[n])	cout << "First\n";
	else cout << "Second\n";
}

int main(int argc, char *argv[]){
    iostream::sync_with_stdio(0);
    prep();
    int test = 1;
    cin >> test;
    while(test--){
        ngk();
    }
    return 0;
}

