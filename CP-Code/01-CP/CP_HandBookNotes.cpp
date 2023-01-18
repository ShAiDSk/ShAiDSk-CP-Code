/*/ Author: ShAiDSk /*/
// #pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include "ext/pb_ds/tree_policy.hpp"
#include "ext/pb_ds/assoc_container.hpp"
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

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

/*/---------------------------Traces(Debug)----------------------/*/
// #define ShAiDSk
// #ifdef ShAiDSk
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
// #else
    // #define trace(...) 1
// #endif

/*/---------------------------RNG----------------------/*/
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int64_t random_long(long long l = LLONG_MIN,long long r = LLONG_MAX){
    uniform_int_distribution<int64_t> generator(l,r);
    return generator(rng);
}
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
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
#define newline  '\n'
typedef long long ll;
/*/-----------------------------Code begins----------------------------------/*/
/*/-----------------Bit-Manipulation-------------------------/*/
// Bit-Shifts
void BitsShifts(){
    // x << k means multiplying x by 2^k
    cout << double(14 << 2) << newline; // 14*2*2 = 56
    // x >> k means dividing x by 2^k round down to an integer.
    cout << double(49 >> 3) << newline; // 49 / 2 / 2 / 2 = 6
}
/*/ Bit-Mask / Bits Masking /*/
void BitsMasking(int x){
    // trace(x);
    string s = "";
    /*/ Bit-Mask / Bits Masking /*/
    for(int i = 31; i >= 0; i--){
        // Some Formula - Modification
        // x | (1 << k) - Set the kth bit x to one.
        // x & (1 << k) - Set the kth bit x to zero.
        // x ^ (1 << k) - Inverts the kth bit of x.
        if (x & (1 << i)) cout << '1';
        else cout << '0';
        // if (x & (1 << i)) s += '1';
        // else s += '0';
    }
    // Only print actual binary string - Testing.
    // for (int i = __builtin_clz(x); i < s.length(); i++){
    //     cout << s[i];
    // }
    cout << newline << newline;

    // Builtin Function of Bit-Manipulation
    // Printing the numbers of Zeros at the beginning of the bit representation.
    cout << "__builtin_clz: " << __builtin_clz(x) << newline;
    // Printing the numbers of Zeros at the end of the bit representation.
    cout << "__builtin_ctz: " << __builtin_ctz(x) << newline;
    // printing the number of set bits or ones of the bit representation.
    cout << "__builtin_popcount: " << __builtin_popcount(x) << newline;
    // printing the parity(even or odd) of the number of ones in the bit representation.
    cout << "__builtin_parity: " << __builtin_parity(x) << newline;
    cout << newline << "---------------" << newline;
    
    // Example from cp_HandBook
    int y = 5328; // 00000000000000000001010011010000
    cout << __builtin_clz(y) << "\n"; // 19
    cout << __builtin_ctz(y) << "\n"; // 4
    cout << __builtin_popcount(y) << "\n"; // 5
    cout << __builtin_parity(y) << "\n"; // 1
}
// Representing Sets
void Representing_Sets(int x){
    x = 0;
    x |= (1 << 1);
    x |= (1 << 3);
    x |= (1 << 4);
    x |= (1 << 8);
    // cout << x << newline; // 282
    // 
    cout << "__builtin_popcount: " << __builtin_popcount(x) << newline;
    for (int i = 0; i < 32; i++){
        if (x & (1 << i)) cout << i << ' ';
    } // Output - 1 3 4 8
    cout << newline << "---------------" << newline;
    int a = (1 << 1) | (1 << 3) | (1 << 4) | (1 << 8);
    int b = (1 << 3) | (1 << 6) | (1 << 8) | (1 << 9);
    int c = a|b;
    // trace(c);
    cout << c << newline;
    cout << "__builtin_popcount: " << __builtin_popcount(c) << newline;
}
// BitSets - c++ STL function
void Bitset(){
    bitset <10> bt;
    bt[1] = 1;
    bt[3] = 1;
    bt[4] = 1;
    bt[7] = 1;
    cout << bt[4] << newline; // 1
    cout << bt[5] << newline; // 0
    cout << "count: " << bt.count() << newline;
    // Bitset Manipulate
    bitset <2> a, b;
    a[1] = 1;
    b[3] = 1;
    b[4] = 1;
    a[7] = 1;
    bitset <2> c = (a & b);
    bitset <2> d = (a | b);
    bitset <2> e = (a ^ b);
    trace(a, b, c, d, e);
}
/*/-----------------Sorting and Searching-------------------------/*/
// Bubble Sort Implementation.
vector <int> BubbleSort(int n, vector <int> &a){
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n - 1; j++){
            if (a[j] > a[j + 1]){
                swap(a[j], a[j + 1]);
            }
        }
    }
    // printing sorted array.
    for(auto &it : a) cout << it << ' ';
    cout << newline;
    // return sorted array.
    return a;
}
// Pair wise sorting
void pairWiseSort(){
    vector <pair<int, int>> a;
    a.pb({1, 5});
    a.pb({2, 3});
    a.pb({1, 2});
    cout << a << newline;
    sort(all(a));
    cout << a << newline;
}
// Tuple wise sorting
void tupleWiseSort(){
    vector <tuple<int, int, int>> a;
    a.pb({2, 1, 4});
    a.pb({1, 5, 3});
    a.pb({2, 1, 3});
    for (auto &it : a) cout << get<0>(it) << ' ' << get<1>(it) << ' ' << get<2>(it) << newline;
    cout << newline;
    sort(all(a));
    for (auto &it : a) cout << get<0>(it) << ' ' << get<1>(it) << ' ' << get<2>(it) << newline;
    cout << newline;
}
// Struct point
struct point{
    int x, y;
    bool operator <(const point &p){
        if (x == p.x) return y < p.y;
        else return x < p.x;
    }
};
// Comparison Function:
bool comp(string a, string b){
    if(a.size() == b.size()) return (a < b);
    else return (a.size() < b.size());
}
// Binary Search
int binarySearch(int n, vector <int> a, int key){
    int i = 0, j = n - 1;
    while (i <= j){
        int mid = (i + j) >> 2; // mid = (i + j) / 2
        if (a[mid] == key) return mid;
        if (key > a[mid]) i = mid + 1;
        else j = mid - 1;
    }
    return -1;

    // Implementation Binary Search using Right making Jumps.
    // int x = 0;
    // for (int i = n / 2; i >= 1; i /= 2){
    //     while(x + i < n && a[x + i] <= key) x += i;
    // }
    // if(a[x] == key) return x;
    // else return -1;
}
/*/-----------------Data Structures-------------------------/*/
// Vector
void vectorDataStructure(){
    vector <int> a;
    a.pb(3);
    a.pb(2);
    a.pb(5);
    cout << a[0] << newline;
    cout << a[1] << newline;
    cout << a[2] << newline;
    cout << newline << "---------------" << newline;
    vector <int> b = {2, 4, 2, 5, 1};
    vector <int> c(5); // c : {0, 0, 0, 0, 0}
    // trace(c);
    vector <int> d(5, 2); // d : {2, 2, 2, 2, 2}
    // trace(d);
    // print vector 
    for (int i = 0; i < d.size(); i++){
        cout << d[i] << ' ';
    } cout << newline;
    // Print vector through iterate way
    for (auto it : d){
        cout << it << ' ';
    } cout << newline;
    // back() and pop_back() function
    vector <int> e = {1, 3, 5, 6, 7, 8, 10, 13};
    cout << e.back() << newline; // 13
    e.ppb();
    cout << e.back() << newline; // 10
    cout << newline << "-------Iterators and Ranges--------" << newline;
    vector <int> it = {5, 2, 3, 1, 2, 5, 7, 1};
    // Sort Function.
    sort(it.begin(), it.end()); // it : {1, 1, 2, 2, 3, 5, 5, 7}
    // trace(it);
    // Reverse Function.
    reverse(it.begin(), it.end()); // it : {7, 5, 5, 3, 2, 2, 1, 1}
    // trace(it);
    // Random Shuffle Function
    random_shuffle(it.begin(), it.end()); // it : {2, 5, 1, 5, 7, 2, 1, 3}
    // trace(it);
    // Iterator Point to accessed
    cout << *it.begin() << newline; // 2
    // Lower Bound and Upper Bound Function
    int key = 5;
    auto x = lower_bound(it.begin(), it.end(), key);
    auto y = upper_bound(it.begin(), it.end(), key);
    // trace(*x, *y); // *x : 5 |  *y : 7
    cout << *x << ' ' << *y << newline; // 5 7
    // Remove duplicate element.
    sort(it.begin(), it.end());
    it.erase(unique(it.begin(), it.end()));
    // trace(it); // it : {1, 2, 3, 5, 7, 5, 7}
    cout << newline << "-------End--------" << newline;
}
// Deque, Stack, queue.
void otherDataStructures(){
    // All function of Deque.
    // push_back(x), push_front(x), pop_back(), pop_front()...etc.
    deque <int> a;
    a.pb(5); // a : {5}
    a.pb(2); // a : {5, 2}
    a.push_front(3); // a : {3, 5, 2}
    a.ppb(); // a : {3, 5}
    a.pop_front(); // a : {5}
    // trace(a);
    // Stack
    stack <int> s;
    s.push(2); // 2
    s.push(5); // 2, 5
    cout << s.top() << newline; // 5
    s.pop(); // 2
    cout << s.top() << newline;
    // Queue
    queue <int> q;
    q.push(2); // 2
    q.push(5); // 2, 5
    cout << q.front() << newline; // 2
    q.pop(); // 5
    cout << q.back() << newline;
}
// Set-Data-Structures
void setDataStructure(){
    set <int> a;
    a.insert(3);
    a.insert(2);
    a.insert(5);
    cout << a.count(3) << newline; // 1
    cout << a.count(4) << newline; // 0
    a.erase(3);
    a.insert(4);
    cout << a.count(3) << newline; // 0
    cout << a.count(4) << newline; // 1
    // An important property of sets is that all their elements are distinct.
    a.insert(3);
    a.insert(3);
    a.insert(3);
    cout << a.count(3) << newline; // 1
    cout << a.size() << newline; // 4
    // Printing Set
    for (auto &it : a) cout << it << ' '; // 2 3 4 5
    cout << newline;
    // Find function
    int x = 5;
    auto it = a.find(x);
    if (it == a.end()) cout << "The element not found." << newline;
    // Finding the smallest and largest value in a set.
    auto first = a.begin();
    auto last = a.end(); last--;
    cout << *first << ' ' << *last << newline; // 2 5
    // trace(*first, *last); // *first : 2 |  *last : 5
    // Unordered set also similar to ordinary set but main difference
    //    between one is ordered while unordered_set is not.
    // lower_bound(), and upper_bound(); Function
    trace(a); // a : {2, 3, 4, 5}
    cout << *a.lower_bound(x) << newline; // 5
    cout << *a.upper_bound(x) << newline; // 4
    // Multiset
    multiset <int> ms;
    ms.insert(5);
    ms.insert(5);
    ms.insert(3);
    ms.insert(6);
    ms.insert(7);
    ms.insert(6);
    ms.insert(4);
    ms.insert(3);
    cout << ms.count(5) << newline; // 3
    ms.erase(5); // it will erase the all copies of value.
    cout << ms.count(5) << newline; // 0
    trace(ms); // ms : {3, 3, 4, 6, 6, 7}
    ms.erase(ms.find(6)); // It will erase only one value.
    trace(ms); // ms : {3, 3, 4, 6, 7}
}
// Map-Data-Structure
void mapDataStructure(){
    // A map is a set that consists of key-value pairs.
    map <int> mp;
    
}
/*/--------------------------------------------------------------------/*/
void ShAiDSk_Solve(){
    setDataStructure();
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