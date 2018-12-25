#include <iostream>


bool isPalindrome(int x){
    int rev = 0;
    if(x < 0 || (x % 10==0 && x !=0))
        return false;
    while(x){
        rev = rev * 10 + x % 10;
        x /= 10;
    }
    std::cout << x << " - " << rev << "\n";
    return x== rev || x == rev / 10;
}

int main(int argc, char *argv[]){
    int n;
    std::cin >> n;

    std::cout << std::boolalpha << isPalindrome(n) << "\n";
}
