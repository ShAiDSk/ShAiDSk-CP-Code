#include <iostream>
using namespace std;

int createPalindrome(int input, int b, bool isOdd){
    int n = input;
    int palin = input;
    if (isOdd) n /= b;
    while (n > 0){
        palin = palin * b + (n % b);
        n /= b;
    }
    return palin;
}

void generatePalindromes(int n){
    int number;
    for (int j = 0; j < 2; j++){
        int i = 1;
        while ((number = createPalindrome(i, 10, j % 2)) < n){
            cout << number << " ";
            i++;
        }
    }
}

// Driver Program to test above function
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        generatePalindromes(n);
    }
    return 0;
}
