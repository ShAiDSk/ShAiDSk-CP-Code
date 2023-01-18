#include<bits/stdc++.h>
using namespace std;

// Notmal reversing string
string reverse(string &s, int n){
    string ans = "";
    while (n > 0){
        ans += s[n - 1];
        n--;
    }
    return ans;
}

int main(){
    string s; cin >> s;
    cout << (reverse(s, s.length())); // Time Complexcity - O(n)
    return 0;
}