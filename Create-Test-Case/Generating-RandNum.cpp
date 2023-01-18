#include <bits/stdc++.h>
using namespace std;
/*/------------------------------------------------------------------/*/
int randNum() {return (rand() % 100);} // Generating-Random-Numbers in range
void out(vector <int> a) {for (auto &it : a) cout << it << ' ';}
/*/-----------------------------------------------------------------/*/
int main(){
    int n; cin >> n;
    srand(time(NULL));
    vector <int> a(n);
    generate(a.begin(), a.end(), randNum);
    // sort(a.begin(), a.end());
    out(a);
    return 0;
}