#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string s; cin >> s;
    int cnt = 1, ans = INT_MIN;
    for (int i = 0; i < s.length(); i++){
        if (cnt > ans) ans = cnt;
        if (s[i] == s[i + 1]) cnt++;
        else cnt = 1;
    }
    cout << ans << endl;
    return 0;
}