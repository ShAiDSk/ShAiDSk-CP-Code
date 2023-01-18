/*/ Author: ShAiDSk /*/
// #pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include "ext/pb_ds/tree_policy.hpp"
#include "ext/pb_ds/assoc_container.hpp"
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
#define newline '\n'

/*/---------------------------From(PBDS)----------------------/*/
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;

void Solve(){
    long long n, k; cin >> n >> k;
    ordered_set <long long> a;
    for (int i = 0; i < n; ++i){
        int x; cin >> x;
        a.insert(x);
    }
    // trace(a);
    // for(auto &it : a) cout << it << ' ';
    // cout << newline;
    bool okay = false;
    int index = -1;
    for (int i = 0; i < n; i++){
        if (*a.find_by_order(i) == k) {okay = true; index = i; break;}
        // trace(*a.find_by_order(i));
    }
    // cout << (okay? "Found" : "Not Found") << newline;
    if (okay){
        cout << "Found at index : " << index << newline;
    }
    else cout << "Not Found : " << index << newline;
}

void ShAiDSk_Solve(){
    int t = 1; // cin >> t;
    while (t--){
        Solve();
    }
}
int main(){
    ShAiDSk_Solve();
    return 0;
}