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
/*/-----------------------------Traversal In Binary Tree----------------------------------/*/
/*
    1. Pre-Order Traversal:-
        Root -> Left subtree -> Right subtree
                  4
                /   \
               1     6
              / \   
             5   2 
            - 4 -> [1 5 2] -> 6
        res - [4, 1, 5, 2, 6];
    2. Post-Order Traversal:
        Left subtree -> Right subtree -> Root
        
    3. In-Order Traversal:
        Left subtree -> Root -> Right subtree
*/
/*/-----------------------------Code begins----------------------------------/*/
class Node{
    public:
        int data;
        Node *left_child;
        Node *right_child;
    Node(int d){
        this -> data = d;
        this -> left_child = NULL;
        this -> right_child = NULL;
    }
};
// Create Tree
Node *createTree(Node *root){
    cout << "Enter the data: " << endl;
    int data; cin >> data;
    root = new Node(data);
    if (data == -1) return NULL;
    cout << "Enter data for inserting in left_child of " << data << endl;
    root -> left_child = createTree(root -> left_child);
    cout << "Enter data for inserting in right_child of " << data << endl;
    root -> right_child = createTree(root -> right_child);
    return root;
}
// Level order Traversal - BFS(Breath First Search)
void bfs(Node *root){
    queue <Node*> a;
    a.push(root);
    a.push(NULL);
    while (!a.empty()){
        Node *temp = a.front();
        a.pop();
        if (temp == NULL){
            cout << newline;
            if (!a.empty()) a.push(NULL);
        }
        else {
            cout << temp -> data << ' ';
            if (temp -> left_child) a.push(temp -> left_child);
            if (temp -> right_child) a.push(temp -> right_child);
        }
    }
}
// Reverse Order Traversal
void reverseOrderTraversal(Node *root){
    queue <Node *> q;
    q.push(root);
    vector <int> ans;
    while (!q.empty()){
        Node *temp = q.front();
        q.pop();
        ans.pb(temp -> data);
        if (temp -> right_child) q.push(temp -> right_child);
        if (temp -> left_child) q.push(temp -> left_child);
    }
    reverse(all(ans));
    for (auto &it : ans) cout << it << ' ';
    cout << newline;
}
// In-Order Traversal.
void inOrder(Node *root){
    if (root == NULL) return;
    // LNR - left_child -> Node -> right_child
    inOrder(root -> left_child);
    cout << (root -> data) << ' ';
    inOrder(root -> right_child);
}
// InOrder Traversal - iterative approach
void inOrderIterative(Node *root){
    stack <Node *> s;
    Node *curr = root;
    while (curr != NULL || !s.empty()){
        while (curr != NULL){
            s.push(curr);
            curr = curr -> left_child;
        }
        curr = s.top();
        s.pop();
        cout << (curr -> data) << ' ';
        curr = curr -> right_child;
    }
}
// PreOrder Traversal.
void preOrder(Node *root){
    if (root == NULL) return;
    // NLR - Node -> left_child -> right_child
    cout << (root -> data) << ' ';
    preOrder(root -> left_child);
    preOrder(root -> right_child);
}
// preOrder Traversal - iterative approach
void preOrderIterative(Node *root){
    if (root == NULL) return;
    stack <Node *> s;
    Node *curr = root;
    while (curr != NULL || !s.empty()){
        while (curr != NULL){
            cout << (curr -> data) << ' ';
            if (curr -> right_child) s.push(curr -> right_child);
            curr = curr -> left_child;
        }
        if (!s.empty()){
            curr = s.top();
            s.pop();
        }
    }
}
// Postorder Traversal.
void postOrder(Node *root){
    if (root == NULL) return;
    // LRN - left_child -> right_child -> Node
    postOrder(root -> left_child);
    postOrder(root -> right_child);
    cout << (root -> data) << ' ';
}
// Post Order Traversal - iterative approach
void postOrderIterative(Node *root){
    if (root == NULL) return;
    stack <Node *> s1, s2;
    s1.push(root);
    Node *node;
    while (!s1.empty()){
        node = s1.top();
        s1.pop();
        s2.push(node);
        if (node -> left_child) s1.push(node -> left_child);
        if (node -> right_child) s1.push(node -> right_child);
    }
    while (!s2.empty()){
        node = s2.top();
        s2.pop();
        cout << (node -> data) << ' ';
    }
}
struct Answer{
    int get(char c){
        return (int(c) - 'a' + 1);
    }
    void Solve(){
        Help h;
        // Input - 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
        Node *root = NULL;
        root = createTree(root);
        // bfs(root); // Or Level Order Traversal
        /*
        Output - 1
                3 5
                7 11 17
        */
        reverseOrderTraversal(root); // 7 11 17 3 5 1
        // Input - 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
        cout << "In-Order Traversal: ";
        inOrder(root); // 7 3 11 1 17 5 
        cout << newline;
        cout << "PreOrder Traversal: ";
        preOrder(root); // 1 3 7 11 5 17 
        cout << newline;
        cout << "post Order Traversal: ";
        postOrder(root); // 7 11 3 17 5 1
        cout << newline;
        inOrderIterative(root); // 7 3 11 1 17 5 
        cout << newline;
        preOrderIterative(root); // 1 3 7 11 5 17 
        cout << newline;
        postOrderIterative(root); // 7 11 3 17 5 1
        cout << newline;
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