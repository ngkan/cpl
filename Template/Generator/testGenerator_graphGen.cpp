// connected graph;
void print_graph(int n, int m, bool isWeighted,int lim){
    // index from 1 -> n

    map <int,bool> mp[n+5];
    #define ii pair<int,int>
    #define iII pair<int, ii>
    #define w first
    #define u second.first
    #define v second.second

    vector <iII> lst;

    // create a tree
    assert(m >= n-1);
    m -= n-1;
    for(int i=2;i<=n;i++){
        int p = Rand(1, i-1);
        int w = Rand(1, lim);

        mp[i][p] = mp[p][i] = 1;
        lst.push_back({w, {i, p}});
    }
    while(m --){
        int a, b, w;
        while(1){
            a = Rand(1, n);
            b = a;
            do{
                b = Rand(1, n);
            }while(a == b);

            if (mp[a][b])   continue;
            else break;
        }
        w = Rand(1, lim);
        mp[a][b] = mp[b][a] = 1;
        lst.push_back({w, {a, b}});
    }

    vector <int> perm;
    for(int i=1;i<=n;i++)   perm.push_back(i);
    shuffle(perm.begin(), perm.end(), rd);

    input << n << ' ' << lst.size() << '\n';
    for(auto e: lst){
        if (Rand(0, 1))
            input << perm[e.u-1] << ' ' << perm[e.v-1];
        else
            input << perm[e.v-1] << ' ' << perm[e.u-1];

        if (isWeighted)
            input << ' ' << e.w;
        input << '\n';
    }
    #undef ii
    #undef iII
    #undef w
    #undef u
    #undef v
}

