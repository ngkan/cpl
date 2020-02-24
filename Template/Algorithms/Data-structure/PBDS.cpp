#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope> //header with rope
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx; //namespace with rope and some additional stuff

// Order Statistics Tree
template <class Tkey, class Tvalue>
using ordered_set =  tree<
    Tkey, Tvalue, less<Tkey>,   // key , value  types. Tvalue can be null_type
    rb_tree_tag,  tree_order_statistics_node_update>;
// same operator as std::set, plus
// find_by_order(int r) (0-based) and
// order_of_key(Tkey v)

// Faster hash table
struct custom_hash {    // Copied and modified from "resources"
    static uint64_t hash_f(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31); 
    }
    int operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM
        = chrono :: steady_clock ::now().time_since_epoch ().count ();
        return hash_f(x + FIXED_RANDOM); 
    }
};
template <class Tkey, class Tvalue>
using hash_table = gp_hash_table <Tkey, Tvalue>;
// Or  gp_hash_table <uint64_t , Tvalue , custom_hash>

// Rope
rope <int> s;
// use as usual STL container
// mutable_begin() and mutable_end()