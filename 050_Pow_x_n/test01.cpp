#include <iostream>

double myPow(double x, int n) {
    double ans = 1;
    unsigned long long p;
    if(n < 0) {
        p = -n;
        x = 1 / x;
    }
    else {
        p = n;
    }

    while(p) {
        if(p & 1){
            ans *= x;
        }
        x *= x;
        p >>= 1;
    }
    return ans;
}

int main(int argc, char *argv[]){
    double x;
    int n;
    std::cin >> x;
    std::cin >> n;

    std::cout << myPow(x, n) << "\n"; 
}
