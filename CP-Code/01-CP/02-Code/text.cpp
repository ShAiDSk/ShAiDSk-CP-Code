#include <bits/stdc++.h>
using namespace std;
// https://medium.com/swlh/tracing-code-in-c-fd9470e3bf5
static void fooBar() {
    std::cout << "Calling " << __func__;
}

template<typename dataTypeName>
dataTypeName mod_add(dataTypeName a, dataTypeName b, dataTypeName m){
        a = a % m;
        b = b % m; 
        return (((a + b) % m) + m) % m;
    }

int main(){
    // fooBar();
    // int a = 2, b = 5, mod = 5;
    long long a = 2, b = 5, mod = 5;
    cout << mod_add(a, b, mod);
}