/*/ Author: ShAiDSk /*/
#include "bits/stdc++.h"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
/*/---------------------------Defines && Typedefs----------------------/*/
#define PI       3.14159265358979323846264338327950288419716939937510
#define rall(x)  ((x).rbegin()),((x).rend())
#define all(x)   ((x).begin()),((x).end())
typedef unsigned long long ull; 
#define pb       push_back
#define ppb      pop_back
typedef long double lld;
#define newline  '\n'
#define INF      1e18
typedef long long ll;
/*/--------------------------------------------------------------------------/*/
// Two Pointers Method in Competetive Programming
vector <int> margeTwoArr (int n, int m, vector <int> a, vector <int> b){
    int i = 0, j = 0;
    vector <int> res;
    while (i < n || j < m){
        if ((i < n || j == m) && (a[i] < b[j])) res.pb(a[i]), i++;
        else res.pb(b[j]), j++;
    }
    return res;
}
/*/--------------------------------------------------------------------/*/
void ShAiDSk_Solve(){
    int n, m; cin >> n >> m;
    vector <int> a(n), b(m);
    for (auto &it : a) cin >> it;
    for (auto &it : b) cin >> it;
    vector <int> ans = margeTwoArr(n, m, a, b);
    for (auto &it : ans) cout << it << ' ';
}
/*/--------------------------------------------------------------------/*/
/*/ MainFunction() /*/
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifdef ShAiDSk
    freopen("Error.txt", "w", stderr);
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#endif 
    auto start1 = high_resolution_clock::now();
    cout << setprecision(15) << fixed;
    cerr << setprecision(10) << fixed;
/*/ TestCases /*/
    int t = 1; // cin >> t;    
/*/ ShAiDSk_Solve() Call /*/
    while (t--) ShAiDSk_Solve();
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
#ifdef ShAiDSk
    cerr << "Time: " << duration . count() / 1000 << newline;
#endif
    return 0;
}