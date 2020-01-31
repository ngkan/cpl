#include <bits/stdc++.h>
using namespace std;
/*-------------------*/

const double EPS = 1e-9;
const double PI  = acos(-1);

template <class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator <(P p) const { return tie(x,y) <tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
    T operator^(P p) const { return x*p.y - y*p.x; }    // cross product
	T operator%(P p) const { return x*p.x + y*p.y; }    //   dot product
	
	T cross(P a, P b) const { return (a-*this)^(b-*this); } 
	T dist2() const { return x*x + y*y; }
	double dist()  const { return sqrt((double)dist2()); }
	double angle() const { return atan2(y, x); }        // [-pi, pi)
	P unit()   const { return *this/dist(); }             
	P normal() const { return P(-y, x).unit(); }        // normal vector
	P rotate(double a) const {return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
};

typedef Point<double> P;							