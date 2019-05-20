#include <iostream>
#include <vector>

int getSum(int a, int b) {
    long carry; 
    while (b != 0) {
        carry = a & b;
        a = a ^ b;
        b = ((carry & 0xffffffff) << 1);
    }
    
    return a;
}


int main(int argc, char *argv[]){
    int a, b;
    std::cin >> a >> b;

    std::cout << getSum(a, b) << "\n";
    return 0;
}
