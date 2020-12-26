---
layout: default
title: Point
parent: Geometry
---
# Point
{: .no_toc}

## Table of contents
{: .no_toc .text-delta }

1. TOC
{:toc}
---

## Point 2D

Template cho điểm 2 chiều.

```cpp
const double EPS = 1e-9;
const double PI  = acos(-1);

template <class T>
struct Point {
    typedef Point P;
    T x, y;
    Point(T x=0, T y=0) : x(x), y(y) {}

    #define comp(op) bool operator op (P p) const { return tie(x,y) op tie(p.x,p.y); }
    comp(<) comp(<=) comp(>) comp(>=) comp(==) comp(!=)

    P operator+(P p) const { return P(x+p.x, y+p.y); }
    P operator-(P p) const { return P(x-p.x, y-p.y); }
    P operator*(T d) const { return P(x*d, y*d); }
    P operator/(T d) const { return P(x/d, y/d); }
    T operator%(P p) const { return x*p.x + y*p.y; }
    T operator^(P p) const { return x*p.y - y*p.x; }

    T cross(P a, P b) const { return (a-*this)^(b-*this); } 
    T dist2() const { return x*x + y*y; }
    double dist()  const { return sqrt((double)dist2()); }
    double angle() const { double a = atan2(y, x); return a > 0 ? a : PI*2 + a; }
    P unit()   const { return *this/dist(); }             
    P normal() const { return P(-y, x).unit(); }
    P rotate(double a) const {return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
};
```
