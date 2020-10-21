/*
    Status: works very slow, need to upgrade
*/

string bigadd(string a,string b){
    string res;
    int nho = 0;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    while(a.size() < b.size()) a.push_back('0');
    while(b.size() < a.size()) b.push_back('0');
    for(int i=0;i<a.size();i++){
        int cal = a[i] + b[i] + nho - '0' - '0';
        res.push_back(cal%10 + '0');
        nho = cal/10;
    }
    if (nho) res.push_back('1');
    reverse(res.begin(),res.end());
    return res;
}
string bigmin(string a,string b){
    string res;
    int nho = 0;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    while(a.size() < b.size()) a.push_back('0');
    while(b.size() < a.size()) b.push_back('0');
    for(int i=0;i<a.size();i++){
        int cal = a[i] - b[i] + nho;
        if (cal < 0)
            res.push_back(cal + 10 + '0'),
            nho = -1;
        else
            res.push_back(cal + '0'),
            nho = 0;
    }
    while(res.size() > 1 && res[res.size()-1] == '0') res.erase(res.end()-1);
    if (nho) res.push_back('-');
    reverse(res.begin(),res.end());
    return res;
}
string bigmul(string a,string b){
    vector<int> res(a.size()+b.size()+5);
    int nho = 0;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    for(int i=0;i<a.size();i++){
        for(int j=0;j<b.size();j++){
            res[i+j] += (a[i]-'0')*(b[j]-'0');
        }
    }
    for(int i=0;i<res.size();i++){
        int tmp = res[i];
        res[i] = (tmp + nho)%10;
        nho = (tmp+nho)/10;
    }
    while(res[res.size()-1] == 0) res.erase(res.begin()+res.size()-1);
    string res2;
    for(int i=0;i<res.size();i++)
        res2.push_back(res[i] + '0');
    reverse(res2.begin(),res2.end());
    return res2;
}
//string bigmul_kara(string a,string b){
//    if (a.size() == 1  || b.size() == 1) return bigmul(a,b);
//    int m = max(a.size(),b.size());
//    int m2 = m/2;
//    string x0,x1,y0,y1;
//    for(int i=m-a.size();i<m2;i++) x1.push_back(a[i-m+a.size()]);
//    for(int i=max(m2,(int)m-(int)a.size());i<m;i++) x0.push_back(a[i-m+a.size()]);
//    for(int i=m-b.size();i<m2;i++) y1.push_back(b[i-m+b.size()]);
//    for(int i=max(m2,(int)m-(int)b.size());i<m;i++) y0.push_back(b[i-m+b.size()]);
//    if (!x1.size()) x1 = "0";
//    if (!y1.size()) y1 = "0";
//
//    string z0 = bigmul_kara(x0,y0);
//    string z1 = bigmul_kara(bigadd(x0,x1), bigadd(y0,y1));
//    string z2 = bigmul_kara(x1,y1);
//
//    string tmp0 = "1", tmp1 = "1", tmp2 = "1";
//    for(int i=0;i<m-m2;i++) tmp1 += "0", tmp2 += "0";
//    for(int i=0;i<m-m2;i++) tmp2 += "0";
//    return bigadd(bigadd(bigmul_kara(z2,tmp2), bigmul_kara(bigmin(z1,bigadd(z0,z2)), tmp1)), z0);
//}
