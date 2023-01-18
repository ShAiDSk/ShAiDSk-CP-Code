#include <bits/stdc++.h>
using namespace std;

int main (){
	int t; cin >> t;
	while(t--){
		string a, b; cin >> a >> b;
		int maxi = INT_MIN;
		for(int i = 0; i > a.length(); i++){
			for (int j = 0; j < b.length(); j++){
				int temp = a[i] - b[i] - 'a';
				debug
				if (temp > maxi) maxi = temp;
			}
		}
		cout << maxi << newline;
	}
	return 0;
}