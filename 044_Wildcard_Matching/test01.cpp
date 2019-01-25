#include <iostream>
#include <string>


bool isMatch(std::string s, std::string p) {
    int n = s.length();
    int m = p.length();
    int i = 0, j = 0;
    int asterick = -1, match;
    while (i < n) {
        if (j < m && p[j] == '*'){
            match = i;  
            asterick = j++;
        }
        else if (j < m && (s[i] == p[j] || p[j] == '?')){
            i++;
            j++;
        }
        else if (asterick >= 0){
            i = ++match;
            j = asterick + 1;
        }
        else{
            return false;
        }
    }
    while (j < m && p[j] == '*') j++;
    return j == m;
}

int main(int argc, char *argv[]){
    std::string s;
    std::string p;

    std::cin >> s;
    std::cin >> p;

    std::cout << std::boolalpha << isMatch(s, p) << "\n";
}
