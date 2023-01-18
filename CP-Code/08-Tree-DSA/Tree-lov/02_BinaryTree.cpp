/*/ Author: ShAiDSk /*/
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
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
/*/--------------------Helping Functions------------------------------/*/
struct Help{
    vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> a; for (int i = 2; i <= n; i++)if (arr[i] == 0) {a.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return a;}
    void google(int t) {cout << "Case #" << t << ": ";}
    bool revsort(ll a, ll b) {return a > b;}
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
    // Power of a number.
    ll power(int base, int pow){
        if (pow == 0) return 1;
        else if (base == 1) return base;
        else return base * power(base, pow - 1);
    }
    // DFS on Tree
    void dfs(int root, vector <int> *edges, int parent){
        cout << (root + 1) << ' ';
        for (auto &it : edges[root]){
            if (it != parent){ // make sure it is not the parent of root.
                dfs(it, edges, root); // it is a child of root and our current parent become.
            }
        }
    }
};
/*/-----------------------------Code begins----------------------------------/*/
/*/---------------------------Binary Tree-----------------------------------------------/*/
/*/ 
    # Binary Tree - Binary tree is a tree 
        which has at most two children for all the nodes.
            1. Tree is made up of node and edges!
            2. n nodes => (n - 1) edges.
            3. Degree => no of direct children(for a node).
            4. Degree of a tree is the highest degree of 
                a node among all the nodes present in a tree.
            5. Binary tree <= tree of degree 2, nodes can have 0, 1 or 2
                children.
            ///// Ham do Hamare Do! /////
        - Tree - Non-linear -> Ideal for representing hierarchical data.
        - Array, stack, Queue, Linked list -> Linear dsa.
        - In a tree with n nodes -> n - 1 edges!
    # Types of Binary Tree:
        1. Full or Strict binary tree - A full binary tree is a binary tree 
                in which all of the nodes have either 0 or 2 offspring.
            &) A binary tree of height h that contains exactly (2^h)-1
                 elements is called a full binary tree.
                  1
                /   \
               2     3
              / \   / \
             4   5 6   7
            - It also Strict/Full Binary Tree
                    x
                  /   \
                 /     \
                x       x
               / \ 
              x   x 
                 / \
                x   x 
        2. Perfect Binary Tree - Internal node have 2 children + 
                                  all leaf nodes are on same level.
                  1
                /   \
               2     3
              / \   / \
             4   5 6   7
            - Perfect Binary Tree
                   x
                 /   \
                /     \
               x       x
              / \     / \
             x   x   x   x
            / \ / \ / \ / \
            x x x x x x x x
        3. Complete Binary Tree - All levels are completely filled except 
            possible the last level + last level must its keys as left as
            possible.
                  1
                /   \
               2     3
              / \   / 
             4   5 6   
        4. Degenerate Tree - Every parent node has exactly one child.
             i.  1   ii. 1
               /        /
              2        2
               \      /
                3    3
        5. Skewed Tree - i. Right Tree, ii. Left Tree
             i.  1   ii. 1
               /          \
              2            2
            /               \
           3                 3
/*/
/*/------------------------------Representation of Binary Tree--------------------------------------------/*/
/* 
# Representation of a Binary Tree - 
    1. Array Representation:
        Index -    0  1  2  3  4   5    6
        a[size] = [1, 5, 3, 4, 8, NULL, 9]
                     1(0)
                    /    \
                  /       \
                /          \
              5(1)         3(2)
             /   \         /   \
           /      \       /     \ 
         4(3)     8(4) NULL(5)  9(6)
    2. Linked Representation:
        We use a double linked list to represent a binary tree. In a double
            linked list every node consists of three fields. First field
            for storing left child address, second for storing actual data
            and third for storing right child address.
        - The above example of the binary tree represented using Linked
             list representation is shown as follows...
            http://www.btechsmartclass.com/data_structures/ds_images/Binary_Tree_Linked_List_Representation.png
*/
/*/--------------------------------------------------------------------------/*/
// Syntax.
struct Node{
    int data;
    struct Node *left_child;
    struct Node *right_child;
    // struct Node *right_child, *left_child;
};
struct Node *CreateNode(int data){
    struct Node *n;
    n = (struct Node *) malloc(sizeof(struct Node));
    n -> data = data;
    n -> left_child = NULL;
    n -> right_child = NULL;
    return n;
}
// Binary Tree Struct.
struct BinaryTree{
    
};
struct Answer{
    int get(char c){
        return (int(c) - 'a' + 1);
    }
    void Solve(){
        Help h; BinaryTree bt;
        // Constructing the root node.
        struct Node *tree = CreateNode(2);
        struct Node *tree_child1 = CreateNode(1);
        struct Node *tree_child2 = CreateNode(4);
        // Linking the root node with the left and right children.
        tree -> left_child = tree_child1;
        tree -> right_child = tree_child2;
        
    }
};
/*/--------------------------------------------------------------------------/*/
/*/ ShAiDSk_Solve() Definition /*/
void ShAiDSk_Solve(){
    int tc = 1; // cin >> tc;
    while (tc--){Answer a; a.Solve();}
}
/*/ MainFunction() /*/
signed main(){
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