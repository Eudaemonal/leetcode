#include <iostream>
#include <string>
#include <vector>


template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& c){
    for(const auto& v : c){
        os << v << ' ';
    }
    os << '\n';
    return os;
}

std::vector<std::string> letterCombinations(std::string digits){
    std::vector<std::string> res;
    if(digits.empty()) return res;
    res.push_back("");

    static const std::vector<std::string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    for(int i = 0; i < digits.length(); ++i){
        int num = digits.at(i) - '0';
        if(num < 0 || num > 9) break;
        std::string candidate = v[num];
        if(candidate.empty()) continue;
        std::vector<std::string> tmp;
        for(int j = 0; j < candidate.length(); ++j){
            for(int k =0; k < res.size(); ++k){
                tmp.push_back(res[k] + candidate[j]);
            }
        }
        res.swap(tmp);
    }
    return res;
}

int main(int argc, char *argv[]){
    std::string s;
    std::getline(std::cin, s);

    std::cout << letterCombinations(s);
    return 0;
}
