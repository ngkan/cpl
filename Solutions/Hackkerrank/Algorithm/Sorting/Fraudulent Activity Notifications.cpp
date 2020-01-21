#include <bits/stdc++.h>
using namespace std;
int n,d,sz1,sz2,ans,mid,a[200005];
int in[200005];
bool marked[200005];
struct cmp1{
    bool operator ()(int x,int y){
        return a[x] < a[y];
    }
};
struct cmp2{
    bool operator ()(int x,int y){
        return a[x] > a[y];
    }
};
priority_queue <int,vector<int>,cmp1> pq1;
priority_queue <int,vector<int>,cmp2> pq2;
vector <int> tmp;
int main(){
    //freopen("input02.txt","r",stdin);
    scanf("%d %d",&n,&d);
    for(int i=1;i<=n;i++)   scanf("%d",&a[i]);
    for(int i=1;i<=d;i++) tmp.push_back(i);
    sort(tmp.begin(),tmp.end(),cmp1());
    for(int i=1;i<=d/2;i++)         pq1.push(tmp[i-1]),++sz1,in[tmp[i-1]] = 1;
    for(int i=(d+1)/2+1;i<=d;i++)   pq2.push(tmp[i-1]),++sz2,in[tmp[i-1]] = 2;
    if (d%2)    mid = tmp[d/2];
    for(int i=d+1;i<=n;i++){
        marked[i-d] = 1;
        if (d%2 == 0){
            if (a[i] >= a[pq1.top()] + a[pq2.top()]) ans++;
            if (in[i-d] == 1) sz1--; else sz2--;
            while(pq1.size() && marked[pq1.top()]) pq1.pop();
            while(pq2.size() && marked[pq2.top()]) pq2.pop();
            if (sz1 < sz2){
                sz1++;
                if (a[i] < a[pq2.top()])
                    pq1.push(i),
                    in[i] = 1;
                else
                    in[pq2.top()] = 1,
                    pq1.push(pq2.top()),
                    pq2.pop(),
                    in[i] = 2,
                    pq2.push(i);
            }
            else{
                sz2++;
                if (a[pq1.top()] < a[i])
                    in[i] = 2,
                    pq2.push(i);
                else
                    in[pq1.top()] = 2,
                    pq2.push(pq1.top()),
                    pq1.pop(),
                    in[i] = 1,
                    pq1.push(i);
            }
            while(pq1.size() && marked[pq1.top()]) pq1.pop();
            while(pq2.size() && marked[pq2.top()]) pq2.pop();
        }
        else{
            if (a[i] >= 2*a[mid]) ans++;
            if (in[i-d] == 1)      sz1--;
            else if (in[i-d] == 2) sz2--;
            else mid = -1;
            while(pq1.size() && marked[pq1.top()]) pq1.pop();
            while(pq2.size() && marked[pq2.top()]) pq2.pop();
            if (sz1 == sz2){
                if (!sz1) mid = i;
                else if (a[i] < a[pq1.top()])
                    in[pq1.top()] = 0,
                    mid = pq1.top(),
                    pq1.pop(),
                    in[i] = 1,
                    pq1.push(i);
                else if (a[i] < a[pq2.top()])
                    mid = i;
                else
                    in[pq2.top()] = 0,
                    mid = pq2.top(),
                    pq2.pop(),
                    in[i] = 2,
                    pq2.push(i);
            }
            else if (sz1 < sz2){
                sz1++;
                if (a[i] < a[mid])
                    in[i] = 1,
                    pq1.push(i);
                else if (a[i] < a[pq2.top()])
                    in[mid] = 1,
                    pq1.push(mid),
                    mid = i;
                else
                    in[mid] = 1,
                    pq1.push(mid),
                    in[pq2.top()] = 0,
                    mid = pq2.top(),
                    pq2.pop(),
                    in[i] = 2,
                    pq2.push(i);
            }
            else{
                sz2++;
                if (a[i] < a[pq1.top()])
                    in[mid] = 2,
                    pq2.push(mid),
                    in[pq1.top()] = 0,
                    mid = pq1.top(),
                    pq1.pop(),
                    in[i] = 1,
                    pq1.push(i);
                else if (a[i] < a[mid])
                    in[mid] = 2,
                    pq2.push(mid),
                    mid = i;
                else
                    in[i] = 2,
                    pq2.push(i);
            }
            while(pq1.size() && marked[pq1.top()]) pq1.pop();
            while(pq2.size() && marked[pq2.top()]) pq2.pop();
        }
    }
    printf("%d",ans);
}
