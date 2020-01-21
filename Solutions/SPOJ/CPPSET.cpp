#include <bits/stdc++.h>
using namespace std;
set <int> a;
set <int>::iterator it;
int x,type;
int main(){
    while(scanf("%d",&type) == 1){
        if (!type) break;
        else if (type == 1){
            scanf("%d",&x);
            a.insert(x);
        }
        else if (type == 2){
            scanf("%d",&x);
            if (a.count(x)) a.erase(a.find(x));
        }
        else if (type == 3){
            if (a.empty()) printf("empty\n");
            else printf("%d\n",*a.begin());
        }
        else if (type == 4){
            it = a.end();
            if (a.empty()) printf("empty\n");
            else it--,printf("%d\n",*it);
        }
        else if (type == 5){
            scanf("%d",&x);
            it = a.upper_bound(x);
            if (a.empty()) printf("empty\n");
            if (it == a.end()) printf("no\n");
            else printf("%d\n",*it);
        }
        else if (type == 6){
            scanf("%d",&x);
            it = a.lower_bound(x);
            if (a.empty()) printf("empty\n");
            if (it == a.end()) printf("no\n");
            else printf("%d\n",*it);
        }
        else if (type == 7){
            scanf("%d",&x);
            it = a.lower_bound(x);
            if (a.empty()) printf("empty\n");
            if (it == a.begin()) printf("no\n");
            else it--,printf("%d\n",*it);
        }
        else{
            scanf("%d",&x);
            it = a.upper_bound(x);
            if (a.empty()) printf("empty\n");
            if (it == a.begin()) printf("no\n");
            else it--,printf("%d\n",*it);
        }
    }
}
