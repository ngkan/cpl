/*  
    ┬┴┬┴┤(･_├┬┴┬┴ hiding from those WAs
    Status: AC
    Basically list all the primes and count the number of
    satisfying pairs
*/

#include <bits/stdc++.h>
using namespace std;

const int N = (int) 1e8;
bool isprime[N + 5];

void sieve(){
    for(int i=2;i<=N;i++)
        isprime[i] = 1;
        
    for(int i=2;i<=N;i++){
        if (isprime[i])
			for(int j=i;j<=N/i;j++)
    			isprime[i*j] = 0;
    }
}

vector <int> prime;
void ngk(){
    sieve();
    for(int i=2;i<=N;i++)
    	if (isprime[i])
    		prime.push_back(i);
    
    int pivot = prime.size() - 1;
    long long ans = 0;
    for(int i=0;i<=pivot;i++){
    	while(prime[i] * prime[pivot] >= N)
    		pivot--;
    	ans += max(pivot - i + 1, 0);
    }
    cout << ans;
}

int main(int argc, char *argv[]){
    iostream::sync_with_stdio(0);
    int test = 1;
    while(test--){
        ngk();
    }
    return 0;
}
