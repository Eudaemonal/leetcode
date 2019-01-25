#include <iostream>
#include <string>

std::string multiply(std::string num1, std::string num2) {
    int n = num1.size();
    int m = num2.size();
    std::string sum(n + m, '0');
    for(int i = n-1; i >= 0; --i){
        for(int j = m-1; j >= 0; --j){
            int temp = (sum[i+j+1] - '0') + (num1[i] - '0') * (num2[j] - '0');
            sum[i+j+1] = temp % 10 + '0';
            sum[i+j] += temp / 10;
        }
    }
    for(int i = 0; i < n+m; ++i){
        if(sum[i] != '0'){
            return sum.substr(i);
        }
    }
    return "0";
}


int main(int argc, char *argv[]){
    std::string num1;
    std::string num2;
    
    std::cin >> num1;
    std::cin >> num2;

    std::cout << multiply(num1, num2) << "\n";
}
