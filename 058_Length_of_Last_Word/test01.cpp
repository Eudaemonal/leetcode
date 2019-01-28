#include <iostream>
#include <string>

int lengthOfLastWord(std::string s) {
    int n = s.length();
    while(s[n-1] == ' ' && n > 0) {
        s = s.substr(0, --n);
    }
    if(n == 0) return 0;
    int len = 0;
    while(n > 0) {
        n--;
        if(s[n] == ' '){ 
            break;
        }
        else{
            len++;
        }
    }
    return len;
}

int main(int argc, char *argv[]){
    std::string s;
    std::getline(std::cin, s);

    std::cout << lengthOfLastWord(s);
}
