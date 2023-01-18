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
#define INF      9223372036854775807LL
typedef unsigned long long ull; 
#define pb       push_back
#define ppb      pop_back
typedef long double lld;
#define newline  '\n'
typedef long long ll;
/*/--------------------------------------------------------------------------/*/
// using Binary exponentiation to find the number odd or even
void checkEvenOdd(int a){
    if (a & 1^1) cout << "Even";
    if (a & 1) cout << "Odd";
    // else cout << "Odd";
    cout << (a & 1^1);
}
void shift(int n){
// Using Shift Operator to devid and multiplies
    n = n >> 1; // n >>= 1; // n = n / 2; // n /= 2;
    n = n << 1; // n <<= 1; // n = n * 2; // n *= 2;
    cout << n;
}
// Gray Code
vector <int> grayCode(int n){
    vector <int> ans;
    for (int i = 0; i < 1 << n; i++){
        ans.pb(i^(i >> 1));
    }
    return ans;
}
// Decimal to Binary Converter
string to_binary(int n){
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

ll power(int base, int pow){
    if (pow == 0) return 1;
    else if (base == 1) return base;
    else return base * power(base, pow - 1);
}
 void genSubseq(int n, vector <int> a){
    // if length of the n then the total subsequence (2^n - 1)
    for (int i = 0; i < (1 << n); i++){
        
    }
}
// Binary Search Implementation
int binarySearch(int n, vector <int> a, int key){
    int i = 0, j = n - 1;
    int mid = i + (j - i) / 2;
    while (i <= j){
        if (a[mid] == key) return mid;
        if (key > a[mid]) i = mid + 1;
        else j = mid - 1;
        // mid = (i + j) / 2;
        mid = i + (j - i) / 2;
    }
    return -1;
}
// Two Pointers Method in Competitive Programming
vector <int> margeTwoArr (int n, int m, vector <int> a, vector <int> b){
    int i = 0, j = 0;
    vector <int> res;
    while (i < n || j < m){
        if ((i < n || j == m) && (a[i] < b[j])) res.pb(a[i]), i++;
        else res.pb(b[j]), j++;
    }
    return res;
}
// Bit-Shifts
void BitsShifts(){
    // x << k means multiplying x by 2^k
    cout << double(14 << 2) << newline; // 14*2*2 = 56
    // x >> k means dividing x by 2^k round down to an integer.
    cout << double(49 >> 3) << newline; // 49 / 2 / 2 / 2 = 6
}
void BitsMasking(int x){
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
    // Additional Function of Bit-Masking
    // Print the numbers of Zeros at the beginning of the bit representation.
    cout << "__builtin_clz: " << __builtin_clz(x) << newline;
    // Print the numbers of Zeros at the end of the bit representation.
    cout << "__builtin_ctz: " << __builtin_ctz(x) << newline;
    // printing the number of set bits or ones of the bit representation.
    cout << "__builtin_popcount: " << __builtin_popcount(x) << newline;
    // printing the parity(even or odd) of the number of ones in the bit representation.
    cout << "__builtin_parity: " << __builtin_parity(x) << newline;
    cout << newline << newline;

    int y = 5328; // 00000000000000000001010011010000
    cout << __builtin_clz(y) << "\n"; // 19
    cout << __builtin_ctz(y) << "\n"; // 4
    cout << __builtin_popcount(y) << "\n"; // 5
    cout << __builtin_parity(y) << "\n"; // 1
}
// Sliding Window Technique Brute Forces Solution
void slidingWindowTechnique_Brute_Solution(){
    // Input array --> a = {1, 9, -1, -2, 7, 3, -1, 2}; k = 4
                                        //  Output - 13
    // Print the SubArray with maximum sum
    // Brute forces solution
    vector <int> a = {1, 9, -1, -2, 7, 3, -1, 2};
    int k = 4;
    int maxiSum = 0;
    for (int i = 0; i <= a.size() - k; i++){
        int windowSum = 0;
        for (int j = i; j < i + k; j++){
            windowSum += a[j];
        }
        maxiSum = max(maxiSum, windowSum);
    }
    cout << maxiSum << newline;
    /// TC - O(n * k)
}
// Sliding Window Technique Optimal Solution
void slidingWindowTechnique_Opt_Solution(){
    vector <int> a = {1, 9, -1, -2, 7, 3, -1, 2};
    int k = 4, maxiSum = 0, windowSum = 0;
    for (int i = 0; i < k; i++) windowSum += a[i];
    for (int i = k; i < a.size(); i++){
        windowSum += a[i] - a[i - k];
        maxiSum = max(maxiSum, windowSum);
    }
    cout << maxiSum << newline;
    // TC - O(n)
}
// Occurrence counting Implementation.
void cntOccurrence(){
    int n;
    if (cin >> n){
        int cnt = 1, x;
        while (cin >> x){
            
        }
    }

// Printing all the Subsequence.
void out(vector <int> &res){
    for (auto &it : res) cout << it << ' ';
    cout << newline;
}
void subSeq(int ind, vector <int> &a, vector <int> &res, int n){
    if (ind == n){
        out(res);
        if (res.size() == 0) cout << ' ' << newline;
        return;
    }
    res.pb(a[ind]);
    subSeq(ind + 1, a, res, n);
    res.ppb();
    subSeq(ind + 1, a, res, n);
}
/*/--------------------------------------------------------------------/*/
void ShAiDSk_Solve(){
    
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