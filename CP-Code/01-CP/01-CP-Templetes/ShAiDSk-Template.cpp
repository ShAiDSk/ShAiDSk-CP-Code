/*/--ShAiDSk--/*/
/*---------------------------------------------------------------------Optimizations------------------------------------------------------------------------------------------------*/
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC target ("arch=native")
// #pragma GCC target ("arch=skylake-avx512")
// #pragma GCC optimize("O3,Ofast,unroll-loops")
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------Headerfiles & Namespaces-------------------------------------------------------------------------------------------------------*/
#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------Typedef------------------------------------------------------------------------------------------------*/
typedef long long ll; typedef unsigned long long ull; typedef long double lld;
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------#Debug Function---------------------------------------------------------------------------------------*/
// #ifdef ShAiDSk
#define debug(x) cerr << #x<<" "; _cerr(x); cerr << endl;
// #else
// #define debug(x);
// #endif
/*---------------------------------------------------------------------#Define Function---------------------------------------------------------------------------------------*/
#define rall(x)  ((x).rbegin()),((x).rend())
#define all(x)   ((x).begin()),((x).end())
#define PI       3.141592653589793238462
#define pb       push_back
#define ppb      pop_back
#define newline  '\n'
#define INF      1e18
#define fir first
#define sec second
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------Debug Fuction---------------------------------------------------------------------*/
void _cerr(ll t) {cerr << t;} /*-long long-*/ void _cerr(int t) {cerr << t;} /*-int-*/ void _cerr(string t) {cerr << t;} /*-string-*/ void _cerr(char t) {cerr << t;} /*-char-*/ void _cerr(lld t) {cerr << t;} /*-long long double-*/ void _cerr(double t) {cerr << t;} /*-double-*/ void _cerr(ull t) {cerr << t;} /*-unsigned long long-*/
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
template <class T, class V> void _cerr(pair <T, V> p); template <class T, class V> void _cerr(map <T, V> v); template <class T> void _cerr(multiset <T> v);
template <class T> void _cerr(vector <T> v); template <class T> void _cerr(set <T> v);
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
template <class T, class V> void _cerr(pair <T, V> p) {cerr << "{"; _cerr(p.fir); cerr << ","; _cerr(p.sec); cerr << "}";}
template <class T, class V> void _cerr(map <T, V> v) {cerr << "[ "; for (auto i : v) {_cerr(i); cerr << " ";} cerr << "]";}
template <class T> void _cerr(multiset <T> v) {cerr << "[ "; for (T i : v) {_cerr(i); cerr << " ";} cerr << "]";}
template <class T> void _cerr(vector <T> v) {cerr << "[ "; for (T i : v) {_cerr(i); cerr << " ";} cerr << "]";}
template <class T> void _cerr(set <T> v) {cerr << "[ "; for (T i : v) {_cerr(i); cerr << " ";} cerr << "]";}
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll Ceil(ll a, ll b) {/* return (a + b - 1) / b; */ return (a / b) + ((a % b) != 0);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll gcd(ll a, ll b) {if (b == 0) return a; return gcd(b, a % b);}
void swap(ll &a, ll &b) {a = (a ^ b); b = (a ^ b); a = (a ^ b);}
// void swap(ll &x, ll &y) {ll temp = x; x = y; y = temp;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll lcm(ll a, ll b) {return ((a * b) / gcd(a, b));}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);} 
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/* ShAiDSk_Solve() Defination */
void ShAiDSk_Solve() {
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        
    }
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#ifdef ShAiDSk
    freopen("Error.txt", "w", stderr);
#endif 
    ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
    auto start1 = high_resolution_clock::now();
    cout << setprecision(15) << fixed;
    cerr << setprecision(10) << fixed;
/* ShAiDSk_Solve() Call */
    ShAiDSk_Solve();
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
#ifdef ShAiDSk
    cerr << "Time: " << duration . count() / 1000 << endl;
#endif
    return 0;
}