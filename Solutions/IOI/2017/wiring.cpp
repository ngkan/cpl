#include "wiring.h"
#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> ii;
ll dp[200005], prefixSum[200005], rem[200005];
ll min_total_length(vector<int> r, vector<int> b) {
    vector <ii> lst;
    int piR = 0, piB = 0;
    while(piR < r.size() || piB < b.size()){
        if (piR == r.size())
            lst.push_back(ii(b[piB++], 2));
        else if (piB == b.size())
            lst.push_back(ii(r[piR++], 1));
        else{
            if (r[piR] < b[piB])
                lst.push_back(ii(r[piR++], 1));
            else
                lst.push_back(ii(b[piB++], 2));
        }
    }
    piR = 0, piB = 0;
    int slope = 0, lrange = 0, rrange = 0;
    r.push_back((int)2e9+5);
    b.push_back((int)2e9+5);
    for(int i=0;i<lst.size();i++){
        dp[i+1] = (ll) 1e18;

        prefixSum[i+1] = prefixSum[i] + (lst[i].second == 1 ? 1 : -1) * lst[i].first;
        slope += (lst[i].second == 1 ? 1 : -1);

        while(r[piR+1] <= lst[i].first)  piR++;
        while(b[piB+1] <= lst[i].first)  piB++;

        if (lst[i].second == 1)
            dp[i+1] = dp[i] + min(abs(lst[i].first - b[piB]),  abs(lst[i].first - b[piB+1]));
        else
            dp[i+1] = dp[i] + min(abs(lst[i].first - r[piR]),  abs(lst[i].first - r[piR+1]));

        if (lrange <= slope && slope <= rrange)
            dp[i+1] = min(dp[i+1], dp[rem[slope+100000]] + abs(prefixSum[i+1] - prefixSum[rem[slope+100000]]));

        lrange = min(lrange, slope);
        rrange = max(rrange, slope);
        rem[slope+100000] = i+1;
    }
	return dp[lst.size()];
}
