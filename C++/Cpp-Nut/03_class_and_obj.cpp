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
// Learning Basic class and objects.
class Phone{
    private:
        string p_name;
        string p_size;
    public:
        // Constructor.
        Phone(string name, string size){
            p_name = name;
            p_size = size;
        }
        void makeCall(){
            cout << "Making Call Using " << p_name << newline;
        }
        void receiveCall(){
            cout << "Receiving Call Using " << p_name << newline;
        }
};
void Solve(){
    // Here Phone is a class and iPhone is a Object.
    Phone iPhone("iPhone_14", "1000x500");
    iPhone.makeCall();
    iPhone.receiveCall();
    cout << newline;
    // Anathor Phone
    // Here Phone is a class and gPixel is a anathor exitObject.
    Phone gPixel("Google Pixel 2 XL", "2000x700");
    gPixel.makeCall();
    gPixel.receiveCall();
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