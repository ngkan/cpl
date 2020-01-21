#include <bits/stdc++.h>
using namespace std;
int n,m,rad[1005][1005],cal[1005][1005],tcd[2005][2005];
bool bull[1005][1005],nbull[2005][2005];
int ans,row=1,col=1,radius;
string s;
void minimize(int &x,int y){
    x = min(x,y);
}
void resetrad(void){
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            rad[i][j] = (1<<30);
}
void resetcal(void){
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cal[i][j] = (1<<30);
}
void pre0(void){
    resetcal();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            minimize(cal[i][j],min(i,j));
            if (i != 0 && j != 0){
                if (bull[i][j] && (bull[i][j-1] || bull[i-1][j])) minimize(cal[i][j],0);
                else minimize(cal[i][j],min(cal[i-1][j],cal[i][j-1]) + 1);
            }
            minimize(rad[i][j],cal[i][j]);
        }
    }
}
void pre1(void){
    resetcal();
    for(int i=0;i<n;i++){
        for(int j=m-1;j>=0;j--){
            minimize(cal[i][j],min(i,m-1-j));
            if (i != 0 && j != m-1){
                if (bull[i][j] && (bull[i][j+1] || bull[i-1][j])) minimize(cal[i][j],0);
                else minimize(cal[i][j], min(cal[i-1][j],cal[i][j+1]) + 1);
            }
            minimize(rad[i][j],cal[i][j]);
        }
    }
}
void pre2(void){
    resetcal();
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            minimize(cal[i][j],min(n-1-i,m-1-j));
            if (i != n-1 && j != m-1){
                if (bull[i][j] && (bull[i+1][j] || bull[i][j+1])) minimize(cal[i][j],0);
                else minimize(cal[i][j], min(cal[i+1][j],cal[i][j+1]) + 1);
            }
            minimize(rad[i][j],cal[i][j]);
        }
    }
}
void pre3(void){
    resetcal();
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<m;j++){
            minimize(cal[i][j], min(n-1-i,j));
            if (i != n-1 && j != 0){
                if (bull[i][j] && (bull[i+1][j] || bull[i][j-1])) minimize(cal[i][j],0);
                else minimize(cal[i][j], min(cal[i+1][j],cal[i][j-1]) + 1);
            }
            minimize(rad[i][j],cal[i][j]);
        }
    }
}
void build_new(void){
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            nbull[i-j+1000][i+j] = bull[i][j];
}
void pre_new(void){
    for(int i=0;i<=2000;i++)
        for(int j=0;j<=2000;j++){
            if (!i && !j)
                tcd[i][j] = nbull[i][j];
            else if (!i)
                tcd[i][j] = tcd[i][j-1] + nbull[i][j];
            else if (!j)
                tcd[i][j] = tcd[i-1][j] + nbull[i][j];
            else
                tcd[i][j] = tcd[i-1][j] + tcd[i][j-1] - tcd[i-1][j-1] + nbull[i][j];
        }
}
int get(int x1,int y1,int x2,int y2){
    return tcd[x2][y2] - (x1 > 0 ? tcd[x1-1][y2] : 0) - (y1 > 0 ? tcd[x2][y1-1] : 0) + ((x1 > 0 && y1 > 0) ? tcd[x1-1][y1-1] : 0);
}
void solve(void){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int nrad = rad[i][j];
            if (get(i-j-nrad+1000,i+j-nrad,i-j+nrad+1000,i+j+nrad) > ans){
                ans = get(i-j-nrad+1000,i+j-nrad,i-j+nrad+1000,i+j+nrad);
                radius = rad[i][j];
                row = i+1;
                col = j+1;
            }
        }
    }
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        int cnt = m;
        s.clear();
        while(cnt--){
            char c = getchar();
            if (c == '.' || c== '*') s.push_back(c);
            else cnt++;
        }
        for(int j=0;j<m;j++)
            bull[i][j] = (s[j] == '*');
    }
    resetrad();
    pre0();
    pre1();
    pre2();
    pre3();
    build_new();
    pre_new();
    solve();
    printf("%d %d %d %d",ans,row,col,radius);
}
