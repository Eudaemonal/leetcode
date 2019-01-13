#include <iostream>

int divide(int dividend, int divisor) {
    if(!divisor || (dividend == INT_MIN && divisor == -1)){
        return INT_MAX;
    }
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1: 1;
    long dvd = labs((long)dividend);
    long dvs = labs((long)divisor);
    int res = 0;
    while(dvd >= dvs){
        long temp = dvs, multiple = 1;
        while(dvd >= (temp << 1)){
            temp <<= 1;
            multiple <<= 1;
        }
        dvd -= temp;
        res += multiple;
    }
    return sign == 1 ? res: -res;
}

int main(int argc, char *argv[]){
    int dividend;
    int divisor;

    std::cin >> dividend;
    std::cin >> divisor;

    std::cout << divide(dividend, divisor) << "\n";
}
