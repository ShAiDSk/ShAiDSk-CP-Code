/*/ Author: ShAiDSk /*/
// #pragma GCC optimize ("O3")
#include "bits/stdc++.h"
using namespace std;
using namespace chrono;
/*/---------------------------Defines && Typedefs----------------------/*/
#define PI       3.14159265358979323846264338327950288419716939937510
#define rall(x)  ((x).rbegin()),((x).rend())
#define all(x)   ((x).begin()),((x).end())
#define INF      9223372036854775807LL
typedef unsigned long long ull; 
#define pb       push_back
#define ppb      pop_back
typedef long double lld;
#define newline  '\n'
typedef long long ll;
/*/-----------------------------Code begins----------------------------------/*/
/* Constructor:-
    Type of Constructor:-
        1. Default Constructor.
        2. Paramiterize Constructor.
        3. Copy Constructor.
*/
class Point{
    double x;
    double y;
public:
    Point(){x = 0, y = 0;}
    Point(double X, double Y){x = X, y = Y;}
    Point(const Point &rhs){x = rhs.x; y = rhs.y;}
};
void Solve(){
    // Call default 
    Point p1;
    Point p2(1.3, 3.4);
    Point p3 = p1;
}
/*/--------------------------------------------------------------------------/*/
/*/ ShAiDSk_Solve() Defination /*/
void ShAiDSk_Solve(){
    int t = 1; // cin >> t;
    while (t--) Solve();
}
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
/* ShAiDSk_Solve() Call */
    ShAiDSk_Solve();
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
#ifdef ShAiDSk
    cerr << "Time: " << duration.count() / 1000 << newline;
#endif
    return 0;
}