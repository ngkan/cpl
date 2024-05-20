/**
 * Convex Hull 
 * Author: ngkan
 * Description: Find the convex hull of the points, using monotone-chain. The 
 * result is counter-clockwise
 * Status: Tested
 *   > Kattis: convexhull
 */

#include "point.h"

typedef Point<long long> P;

vector<P> ConvexHull(vector<P> pts){
    sort(pts.begin(), pts.end(), greater<P>());
    pts.resize(unique(pts.begin(), pts.end()) - pts.begin());
    vector<P> ch;
    for (int _ = 2, s = 0; _ ; _ --, s = ch.size(), reverse(pts.begin(), pts.end())){
        for (P p: pts) {
            while(ch.size() >= s + _ && ch[ch.size()-2].cross(ch[ch.size()-1], p) <= 0) 
                ch.pop_back();
            ch.push_back(p);
        }
    }
    return {ch.begin(), ch.end() - 1};
}
