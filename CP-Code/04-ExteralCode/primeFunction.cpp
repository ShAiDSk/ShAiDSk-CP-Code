#include <bits/stdc++.h>
using namespace std;

bool prime(int x){
	int cnt = 1;
	if (x <= 1) return false;
	for (int i = 2; i <= x; i++){
		if (x % i == 0){
		    cnt++;
		    debug(i)
		}
	}
	debug(cnt)
	if (cnt == 3) return true;
	return false;
}

bool primeSqrtN(int n){
    int cnt = 1;
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0) cnt++;
    }
    if (cnt == 3) return true;
    else return false;
}

void ShAiDSk_Solve(){
	int n; cin >> n;
	prime(n);
}

// Main Function Call
int main(){
	ShAiDSk_Solve();
return 0;
}