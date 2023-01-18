#include <bits/stdc++.h>
using namespace std;

int f(int n){
	if (n == 0) return 1;
	return n * f(n - 1);
}

void ShAiDSk_Solve(void){
	int n; cin >> n;
	cout << (f(n)) << endl;
}

// Main Function Call
int main(){
	ShAiDSk_Solve();
return 0;
}