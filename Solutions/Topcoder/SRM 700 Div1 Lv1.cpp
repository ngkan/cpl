#include <bits/stdc++.h>
using namespace std;
class FindingFriend{
public:
    int find(int roomSize, vector <int> leaders, int friendPlace){
        for(int i=0;i<leaders.size();i++)
            if (leaders[i] == friendPlace) return 1;
        sort(leaders.begin(),leaders.end(),greater<int>());
        int last = roomSize * leaders.size();
        int total = 0,cnt = 0,ans=0;
        for(int i=0;i<leaders.size();i++){
            total += abs(leaders[i] - last);
            cnt++;
            last = leaders[i];
            if (friendPlace < leaders[i]){
                last = leaders[i];
                continue;
            }
            ans++;
            if (cnt * roomSize > total) break;
        }
        return ans;
    }
};

int main(){
}
