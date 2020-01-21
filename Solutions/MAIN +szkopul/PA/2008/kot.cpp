#include <bits/stdc++.h>
using namespace std;
string s;
int out(char &c){
    if (c == '`') return 1;
    if ('0' <= c && c <= '9') return 1;
    if (c == '-' || c == '=') return 1;
    if (c == 'Q') return 2;
    if (c == 'W') return 2;
    if (c == 'E') return 2;
    if (c == 'R') return 2;
    if (c == 'T') return 2;
    if (c == 'Y') return 2;
    if (c == 'U') return 2;
    if (c == 'I') return 2;
    if (c == 'O') return 2;
    if (c == 'P') return 2;
    if (c == '[') return 2;
    if (c == ']') return 2;
    if (c == '\\') return 2;
    if (c == 'A') return 3;
    if (c == 'S') return 3;
    if (c == 'D') return 3;
    if (c == 'F') return 3;
    if (c == 'G') return 3;
    if (c == 'H') return 3;
    if (c == 'J') return 3;
    if (c == 'K') return 3;
    if (c == 'L') return 3;
    if (c == ';') return 3;
    if (c == '\'') return 3;
    if (c == 'Z') return 4;
    if (c == 'X') return 4;
    if (c == 'C') return 4;
    if (c == 'V') return 4;
    if (c == 'B') return 4;
    if (c == 'N') return 4;
    if (c == 'M') return 4;
    if (c == ',') return 4;
    if (c == '.') return 4;
    if (c == '/') return 4;
    if (c == ' ') return 5;
}
int main(){
    getline(cin,s);
    for(int i=0;i<s.size();i++)
        cout << out(s[i]);
}
