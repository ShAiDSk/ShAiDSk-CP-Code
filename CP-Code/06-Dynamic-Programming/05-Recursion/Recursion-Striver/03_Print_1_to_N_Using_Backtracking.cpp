#include <bits/stdc++.h>
using namespace std;

// Print 1 to N in incresing order using Recursion
void f(int n){
    if (n == 0) return;
    f(n - 1);
    cout << n << ' ';
}

void ShAiDSk_Solve(void){
	int n; cin >> n;
    f(n);
}

// Main Function Call
int main(){
	ShAiDSk_Solve();
return 0;
}