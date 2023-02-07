/*/ Author: ShAiDSk /*/
#ifndef __LOCAL_ShAiDSk__
    #pragma GCC optimize("03")
    // #pragma GCC target("avx,avx2,sse4.2,bmi,bmi2,popcnt,lzcnt") // Gives SIGILL on SPOJ
#endif
#include <bits/stdc++.h>
// https://atcoder.github.io/ac-library/document_en/modint.html (included in grader)
// #include <atcoder/modint>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
// using namespace atcoder;
// using mint = modint;
/*/---------------------------From(PBDS)----------------------/*/
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;

template<class T>
using min_heap = priority_queue<T,vector<T>,greater<T>>; 

/*/---------------------------IO(Debugging)----------------------/*/
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> 
istream& operator >> (istream &is, T_container &v) { 
   for (T &it : v) is >> it; return is;
}
template<typename A, typename B> 
ostream& operator<<(ostream &os, const pair<A, B> &p) { 
   return os << '(' << p.first << ", " << p.second << ')'; 
}
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> 
ostream& operator << (ostream &os, const T_container &v) { 
   os << '{'; string sep; 
   for (const T &x : v) os << sep << x, sep = ", "; 
   return os << '}'; 
}
template<class P, class Q = vector<P>, class R = less<P> > ostream& operator << (ostream& out, priority_queue<P, Q, R> const& M){
    static priority_queue<P, Q, R> U;
    U = M;
    out << "{ ";
    while(!U.empty())
        out << U.top() << " ", U.pop();
    return (out << "}");
}
template<class P> ostream& operator << (ostream& out, queue<P> const& M){
    static queue<P> U;
    U = M;
    out << "{"; string sep;
    while(!U.empty()){
        out << sep << U.front(); sep = ", "; U.pop();
    }
    return (out << "}");
}
// Comparator: comparing two elements
struct comp{
    template <typename T>
    bool operator()(const T &a, const T &b) const{
        if (a.second != b.second) return a.second < b.second;
        return a.first < b.first;
    }
};
// Sort by second element
template <class T1, class T2, class Pred = std::less<T2> >
struct sort_pair_second {
    bool operator()(const std::pair<T1,T2>&left, const std::pair<T1,T2>&right) {
        Pred p;
        return p(left.second, right.second);
    }
};
/*/---------------------------Traces(Debug)----------------------/*/
#define TRACE
#define ShAiDSk TRACE
#ifdef ShAiDSk
    #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " : " << arg1 << '\n';
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
         int count_open = 0, len = 1;
         for(int k = 1; ; ++k){
            char cur = *(names + k);
            count_open += (cur == '(' ? 1 : (cur == ')' ? -1: 0));
            if (cur == ',' && count_open == 0){
               const char* comma = names + k;
               cerr.write(names, len) << " : " << arg1 << " | ";
               __f(comma + 1, args...);
               return;
            }
            len = (cur == ' ' ? len : k + 1);
         }
    }
#else
    #define trace(...) 1
#endif
/*/---------------------------------RNG--------------------------------/*/
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int64_t random_long(long long l = LLONG_MIN,long long r = LLONG_MAX){
    uniform_int_distribution<int64_t> generator(l,r);
    return generator(rng);
}
struct custom_hash { // Credits: https://codeforces.com/blog/entry/62393
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
    template<typename L, typename R>
    size_t operator()(pair<L,R> const& Y) const{
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(Y.first * 31ull + Y.second + FIXED_RANDOM);
    }
};
/*/---------------------------Defines && Typedefs----------------------/*/
#define PI       3.14159265358979323846264338327950288419716939937510
#define rall(x)  ((x).rbegin()),((x).rend())
#define all(x)   ((x).begin()),((x).end())
#define INF      9223372036854775807LL
typedef unsigned long long ull; 
#define pb       push_back
#define ppb      pop_back
typedef long double lld;
#define nln  '\n'
typedef long long ll;
/*/---------------------------Helping Functions------------------------------/*/
struct Help{
    template<typename dataType>
    void swap(dataType &a, dataType &b) {a = (a ^ b); b = (a ^ b); a = (a ^ b);}
    template<typename dataType>
    void google(dataType t) {cout << "Case #" << t << ": ";}
    template<typename dataType>
    dataType lcm(dataType a, dataType b) {return ((a * b) / __gcd(a, b));}
    template<typename dataType>
    bool revsort(dataType a, dataType b) {return a > b;}
    // Sieve of Eratosthenes to check is prime or not
    template<typename dataType>
    vector<dataType> sieve(dataType n){
        dataType*arr = new dataType[n + 1]();
        vector<dataType> vect;
        for (dataType i = 2; i <= n; i++){
            if (arr[i] == 0){
                vect.push_back(i);
                for (dataType j = 2 * i; j <= n; j += i){
                    arr[j] = 1;
                }
            }
        }
        return vect;
    }
    // Decimal to Binary Converter
    template<typename dataType>
    string to_binary(dataType n){
        string s;
        while (n > 0){
            // if (n % 2) s += '1';
            // else s += '0';
            s += (n % 2 ? '1' : '0');
            n >>= 1; // n /= 2;
        }
        reverse(all(s));
        return s;
    }
    // Power of a number.
    template<typename dataType>
    dataType power(dataType base, dataType pow){
        if (pow == 0) return 1;
        else if (base == 1) return base;
        else return base * power(base, pow - 1);
    }
    // Binary Exponentiation
    template<typename dataType>
    dataType binExpo(dataType a, dataType b){
        if (b == 0) return 1;
        dataType x = binExpo(a, b/2);
        if (b % 2 == 0) return (x * x);
        return (x * x * a);
    }
    // getUnique Number.
    template<typename dataType>
    void getUnique(vector <dataType> &a) {
        sort(all(a));
        a.erase(unique(all(a)), a.end());
    }
    template<typename dataType>
    dataType x(dataType n, dataType digit){
        if (n == 1) return digit;
        digit *= digit;
        return x(n - 1, digit);
    }
    template<typename dataType>
    dataType gcd(dataType a, dataType b){
        dataType temp = a + b;
        a = (a > b)? a : b;
        b = temp - a;
        if (a % b == 0) return b;
        return gcd(b, a % b);
    }
    /** Computes a^b modulo MOD in O(log MOD) time.**/
    template<typename dataType>
    dataType expo(dataType a, dataType b, dataType mod){
        a %= mod;
        dataType res = 1;
        while (b > 0){
            if (b & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }
    template<typename dataType>
    dataType mminvprime(dataType a, dataType b){
        return expo(a, b - 2, b);
    }
    template<typename dataType>
    dataType mod_add(dataType a, dataType b, dataType mod){
        a = a % mod;
        b = b % mod;
        return (((a + b) % mod) + mod) % mod;
    }
    template<typename dataType>
    dataType mod_mul(dataType a, dataType b, dataType mod){
        a = a % mod;
        b = b % mod;
        return (((a * b) % mod) + mod) % mod;
    }
    template<typename dataType>
    dataType mod_sub(dataType a, dataType b, dataType mod){
        a = a % mod;
        b = b % mod;
        return (((a - b) % mod) + mod) % mod;
    }
    template<typename dataType>
    dataType mod_div(dataType a, dataType b, dataType mod){
        a = a % mod;
        b = b % mod;
        return (mod_mul(a, mminvprime(b, mod), mod) + mod) % mod;
    } //only for prime m
    template<typename dataType>
    dataType binomial(dataType a, dataType b, dataType mod){
        if (a == 0 || b == a) return 1;
        return(binomial(a - 1, b - 1, mod) + binomial(a - 1, b, mod)) % mod;
    }
};
/*/-----------------------------Code begins----------------------------------/*/
template <typename T> void out(T t){cerr << t << nln;}
template <typename T, typename... Args>
void out(T t, Args... args){
    cerr << t << nln;
    out(args...);
}
struct range{
    int l, r, ind;
    bool operator < (const range &other){
        if (l == other.l) return r > other.r;
        return l < other.l;
    }
};
/*/---------------------Debug or TRACE Interactive problems------------------------/*/
//* Debug or TRACE Interactive problems
struct Interator{
    int n;
    vector <int> a;
    int limitQueries = 0, queries = 0;
    Interator(int nGiven){
        n = nGiven;
        a.resize(n);
        for (int i = 0; i < n; i++){
            a[i] = random_long(1, 100);
        }
        cout << "Hidden Array: ";
        for (auto &it : a) cout << it << ' ';
        cout << endl;
    }
    // Queries or Input form codeforces
    int query(int l, int r){
        assert(l >= 1 && r <= n && l < r);
        int sum = 0;
        for (int i = l; i <= r; i++) sum += a[i - 1];
        return sum;
    }
    // Checking the output is correct or not.
    bool correctOutput(vector <int> output){
        assert(output.size() == n && output == a);
        return true;
    }
};
/*/------------------------------Global-Defines-------------------------------/*/
const int N = 1e6;
const ll MOD = 1e9 + 7;
ll fact[N + 1];
/*/--------------------------------------------------------------------------/*/
struct Answer{
    Help H; // Interator codeforces = Interator(5);
    int get(char c){
        return (int(c) - 'a' + 1);
    }
    int getInt(char c){
        return (c - '0');
    }
    void getSum(ll &ans, int n){
        ans += (n * 1LL * (n + 1)) / 2;
    }
    // Predicate fuction
    bool check(void){
        return false;
    }
    //! Number Hashing
    void NumHashing(){
        //* Input: 5
        //        1 2 1 3 2
        //! Hashing in integer
        int n; cin >> n;
        vector <int> a(n);
        for (auto &it : a) cin >> it;
        // int Hash[n + 1] = {0};
        vector <int> Hash(n + 1, 0);
        // cout << Hash ;
        for (int i = 0; i < n; i++){
            Hash[a[i]]++;
        }
        // for (int i = 0; i < n; i++) cout << Hash[i] << ' ';
        int q; cin >> q;
        while (q--){
            int x; cin >> x;
            cout << x << ": " << Hash[x] << nln;
        }
    }
    //! Hashing in a Lower case string.
    void HashingLowerCaseString(){
        //* Input: shaidbrishtiiloveyou
            //    6
            //    a b d i o r
        string s; cin >> s;
        vector <int> Hash(26, 0);
        for (auto &it : s){
            Hash[it - 'a']++;
        }
        // cout << Hash;
        int q; cin >> q;
        while (q--){
            char c; cin >> c;
            cout << c << ": " << Hash[c - 'a'] << ", ";
        }
        //? Output:- a: 1, b: 1, d: 1, i: 4, o: 2, r: 1,
    }
    //! Hashing in any string.
    void HashingInAnyString(){
        //* Input:
        //     shaidbrishtiiloveyou
        //     6
        //     a b d i o r
        string s; cin >> s;
        vector <int> Hash(256, 0);
        for (auto &it : s){
            Hash[it]++;
        }
        // cout << Hash;
        int q; cin >> q;
        while (q--){
            char c; cin >> c;
            cout << c << ": " << Hash[c] << ", ";
        }
        //? Output:- a: 1, b: 1, d: 1, i: 4, o: 2, r: 1,
        //* Input: 2
        //     AAABBBBCabc
        //     6
        //     A B C a b c
        //? Output2:- A: 3, B: 4, C: 1, a: 1, b: 1, c: 1,
    }
    void Solve(){
        // `{`:∀:x:∀:`}`
        // NumHashing();
        // HashingLowerCaseString();
        // HashingInAnyString();
    }
};
/*/--------------------------------------------------------------------------/*/
/*/ ShAiDSk_Solve() Definition /*/
void ShAiDSk_Solve(){
    int tc = 1; // cin >> tc;
    while (tc--){Answer a; a.Solve();}
}
/*/ MainFunction() /*/
signed main(int argc, char **argv, char **envp){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifdef ShAiDSk
    freopen("cerr.txt", "w", stderr);
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#endif
    auto start1 = high_resolution_clock::now();
    cout << setprecision(15) << fixed; cerr << setprecision(10) << fixed;
/* ShAiDSk_Solve() Call */
    ShAiDSk_Solve();
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
#ifdef ShAiDSk
    cerr << "Time: " << duration.count() / 1000 << " milliseconds" << nln;
#endif
    return 0;
}