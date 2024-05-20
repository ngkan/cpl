#define ll long long

mt19937_64 rd(chrono::system_clock::now().time_since_epoch().count());

ll Rand(ll lo,ll hi){
    return rd() % (hi - lo + 1) + lo;
}

struct point{
    ll x, y;
    point(ll x=0,ll y=0): x(x), y(y) {}
    const point operator + (const point &X){
        return {x + X.x, y + X.y};
    }
    const point operator - (const point &X){
        return {x - X.x, y - X.y};
    }
    const bool operator == (const point &X){
        return x == X.x && y == X.y;
    }
};

ll crossProd(point a,point b){
    return a.x*b.y - a.y*b.x;
}

vector <point> convexHull(vector <point> &p){
	sort(p.begin(), p.end(), [&](point x,point y){
        if (x.x == y.x)	return x.y < y.y;
		return x.x < y.x;
	});

	vector <point> result;

	for(int i=0;i<(int)p.size();i++){
		#define sz (result.size())
		while(result.size() >= 2 && crossProd(result[sz-1] - result[sz-2], p[i] - result[sz-2]) >= 0)	result.pop_back();
		result.push_back(p[i]);
		#undef sz
	}	int pi = (int)result.size();
	for(int i=(int)p.size()-1;i>=0;i--){
		#define sz (result.size())
		while((int)result.size() >= pi+1 && crossProd(result[sz-1] - result[sz-2], p[i] - result[sz-2])  >= 0)	result.pop_back();
		result.push_back(p[i]);
		#undef sz
	}	result.pop_back();

	return result;
}

// clockwise order
void createTest(ofstream &input, int testId){
    int n = Rand(50, 100);
    const ll LIMCORDINATE = (ll) 2000;
    const ll LIMVECTOR = LIMCORDINATE / n;

    vector <point> vectorLst;
    for(int i=1;i<=n;i++){
        point ahihi = {0, 0};
        while(ahihi == point(0,0)){
            ahihi = {Rand(0, LIMVECTOR*2) - LIMVECTOR, Rand(0, LIMVECTOR*2) - LIMVECTOR};
        }
        vectorLst.push_back(ahihi);
    }
    sort(vectorLst.begin(), vectorLst.end(), [&](point &x, point &y){
            if (x.y >= 0 && y.y < 0)	return 1;
            if (x.y < 0 && y.y >= 0)	return 0;
            if (x.y == 0 && y.y == 0)
                return int(x.x > y.x);
            return int(crossProd(x, y) > 0);
        });

    for(int i=1;i<n;i++){
        vectorLst[i] = vectorLst[i] + vectorLst[i-1];
    }
    vector <point> fin = convexHull(vectorLst);

    input << fin.size() << '\n';
    for(int i=0;i<fin.size();i++){
        input << fin[i].x << ' ' << fin[i].y << '\n';
    }
}
