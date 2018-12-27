#include <iostream>
#include <string>
#include <vector>

std::string intToRoman(int num){
    const int value[13] = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };
    const std::string symbol[13] = { "I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M" };

	std::string ret;
	int i = 12;

    while (i >= 0) {
        int leftover = num - value[i];
        if (leftover >= 0) {
            ret.append(symbol[i]);
            num -= value[i];
        }else {
            i--;
        }
    }
    return ret;
}

int main(int argc, char *argv[]){
    int n;
    std::cin >> n;
    std::cout << intToRoman(n) << "\n";
}
