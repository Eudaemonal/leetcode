#include <iostream>
#include <string>

std::string convert(std::string s, int numRows){
    if(numRows == 1) return s;
    std::string ret;
    int n = s.length();
    int cycleLen = 2 * numRows - 2;
    for(int i = 0; i < numRows; ++i){
        for(int j = 0; j + i < n; j += cycleLen){
            ret += s[j + i];
            if(i != 0 && i != numRows -1 && j + cycleLen - i < n)
                ret += s[j + cycleLen -i];
        }
    }
    return ret;
}

int main(int argc, char *argv[]){
    int n;
    std::cin >> n;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string s;
    std::getline(std::cin, s);

    std::cout << convert(s, n) << "\n";

    return 0;
}
