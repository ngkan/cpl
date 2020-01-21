/*
https://www.codechef.com/OCT16/problems/FENWITER
*/
#include <bits/stdc++.h>
using namespace std;
int test,n,res;
string l1,l2,l3;
int main(){
    iostream::sync_with_stdio(0);
    cin >> test;
    while(test--){
        res = 0;
        cin >> l1 >> l2 >> l3 >> n;
        string tmp = l2 + l3;
        reverse(tmp.begin(),tmp.end());
        tmp[0] ++;
        for(int i=0;i<tmp.size();i++){
            if (tmp[i] > '1'){
                tmp[i] = '0';
                if (i+1 < tmp.size()) tmp[i+1] ++;
            }
        }
        bool check = 0;
        for(int i=0;i<tmp.size();i++) if (tmp[i] == '1') check = 1;
        if (!check){
            reverse(l1.begin(),l1.end());
            l1[0] ++ ;
            for(int i=0;i<l1.size();i++){
                if (l1[i] > '1'){
                    l1[i] = '0';
                    if (i+1 < l1.size()) l1[i+1] ++;
                }
            }
            bool check2 = 0;
            for(int i=0;i<l1.size();i++) if (l1[i] == '1') check2 = 1;
            if (!check2) l1.push_back('1');
            for(int i=0;i<l1.size();i++)
                res += (l1[i] == '1');
            cout << res << endl;
        }
        else{
            for(int i=0;i<tmp.size();i++)
                res += (tmp[i] == '1');
            for(int i=0;i<l1.size();i++)
                res += (l1[i] == '1');
            for(int i=0;i<l2.size();i++)
                res += (n-1) * (l2[i] == '1');
            cout << res << endl;
        }
    }
}
