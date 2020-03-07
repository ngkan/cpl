/*  
    ┬┴┬┴┤(･_├┬┴┬┴ hiding from those WAs
*/

#include <bits/stdc++.h>
using namespace std;

int n, k;
int w[250005];
long long dp[250005][3][10][10];

void ngk(){
    cin >> n >> k;
    for(int i=1;i<=n;i++)
    	cin >> w[i];
    
    for(int i=0;i<=n;i++)	for(int j=0;j<=2;j++)	for(int l=0;l<=k;l++)	for(int m=0;m<=k;m++)
    	dp[i][j][l][m] = (long long) 1e16;
    	
    dp[0][1][0][0] = 0;
    
    for(int i=0;i<n;i++){
		for(int l=0;l<=k;l++){
			for(int m=0;m<=k;m++){
				// j = 0 -> must put light at [i+1][2]
				dp[i+1][2][l][m] = min(dp[i+1][2][l][m], dp[i][0][l][m] + w[i+1]);
				// j = 0 -> must put light at [i+1][2] but swap it
				if (m < k)
				dp[i+1][2][l][m+1] = min(dp[i+1][2][l][m+1], dp[i][0][l][m]);
				
				// j = 1
				// not putting light i+1
				dp[i+1][0][l][m] = min(dp[i+1][0][l][m], dp[i][1][l][m]);
				// not putting light i+1 and swap it
				if (l < k)
				dp[i+1][0][l+1][m] = min(dp[i+1][0][l+1][m], dp[i][1][l][m] + w[i+1]);
				// putting light i+1
				dp[i+1][2][l][m] = min(dp[i+1][2][l][m], dp[i][1][l][m] + w[i+1]);
				// putting light i+1 and swap it
				if (m < k)
				dp[i+1][2][l][m+1] = min(dp[i+1][2][l][m+1], dp[i][1][l][m]);
				
				// j == 2
				// not putting light i+1
				dp[i+1][1][l][m] = min(dp[i+1][1][l][m], dp[i][2][l][m]);
				// not putting light i+1 + swap it
				if (l < k)
				dp[i+1][1][l+1][m] = min(dp[i+1][1][l+1][m], dp[i][2][l][m] + w[i+1]);
				// putting light i+1
				dp[i+1][2][l][m] = min(dp[i+1][2][l][m], dp[i][2][l][m] + w[i+1]);
				// putting light i+1 and swap it
				if (m < k)
				dp[i+1][2][l][m+1] = min(dp[i+1][2][l][m+1], dp[i][2][l][m]);
			}
		}
    }
    long long ans = (long long) 1e18;
    for(int j=1;j<=2;j++)
    	for(int m=0;m<=k;m++)
    		ans = min(ans, dp[n][j][m][m]);
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
