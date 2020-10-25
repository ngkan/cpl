/**
 * Convex Hull 
 * Author: ngkan
 * Description: Find the convex hull of the points, using monotone-chain. The 
 * result is counter-clockwise
 * Status: Tested, Kattis-convexhull
 */

#include "point.h"

vector<P> ConvexHull(vector<P> &p){
    sort(p.begin(), p.end());
    vector<P> res;
    #define sz (int(res.size()))
    for(int i=0;i<(int)p.size();i++){
        while(sz >= 2 && ((res[sz-1] - res[sz-2]) ^ (p[i] - res[sz-2])) >= 0)   res.pop_back();
        res.push_back(p[i]);
    }   int tmp = (int)res.size();
    for(int i=(int)p.size()-1;i>=0;i--){
        while(sz >= tmp+1 && ((res[sz-1] - res[sz-2]) ^ (p[i] - res[sz-2])) >= 0)  res.pop_back();
        res.push_back(p[i]);
    }   res.pop_back();
    #undef sz
    reverse(res.begin(), res.end());
    return res;
}
