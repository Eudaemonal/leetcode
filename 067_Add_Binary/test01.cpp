#include <iostream>
#include <string>

std::string addBinary(std::string a, std::string b){
    int i = a.length()-1;
    int j = b.length()-1;

    std::string s = "";
    int carry = 0;
    int sum;
    while(i >= 0 && j >= 0){
        sum = a[i]-'0' + b[j]-'0' + carry;
        if(sum >= 2){
            s = char(sum % 2 + '0') + s;
            carry = 1;
        }else{
            s = char(sum + '0') + s;
            carry = 0;
        }
        i--;
        j--;
    }
    while(i >= 0){
        sum = a[i]-'0' + carry;
        if(sum == 2){
            carry = 1;
            s = '0' + s;
        }else{
            s = char(sum + '0') + s;
            carry = 0;
        }
        i--;
    }
    while(j >= 0){
        sum = b[j]-'0' + carry;
        if(sum == 2){
            carry = 1;
            s = '0' + s;
        }else{
            s = char(sum + '0') + s;
            carry = 0;
        }
        j--;
    }

    if(carry) {
        s = '1' + s;
    }
    return s;
}

int main(int argc, char *argv[]){
    std::string a;
    std::string b;

    std::cin >> a;
    std::cin >> b;
    
    std::cout << addBinary(a, b) << "\n";
}
