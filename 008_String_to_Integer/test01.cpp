#include <iostream>
#include <string>

int myAtoi(std::string str){
    long res = 0;
    int sign = 1;

    while(str.front() == ' '){
        str.erase (0, 1);
    }
    if(str.front()== '-'){
        sign = -1;
        str.erase (0, 1);
    }
    else if(str.front()== '+'){
        str.erase (0, 1);
    }
    
    while(str.front()>='0' && str.front() <='9'){
        res = res * 10 + str.front() - '0';
        if (res > INT_MAX)
            return (sign == 1) ? INT_MAX : INT_MIN;  
        str.erase (0, 1);
    }
    return res*sign;
}

int main(int argc, char *argv[]){
    std::string str;
    std::getline(std::cin, str);

    std::cout << myAtoi(str) << "\n";
}
