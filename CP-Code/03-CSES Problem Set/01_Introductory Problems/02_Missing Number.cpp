#include<bits/stdc++.h>
#define newline '\n';
using namespace std;
typedef long long ll;
 
int main(){
    ll n; cin >> n;
    ll sum = n * (n + 1) / 2;
    for (ll i = 0; i < n - 1; i++){
        ll x; cin >> x;
        sum -= x;
    }
    cout << sum << newline;
    return 0;
}
