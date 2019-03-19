#include <iostream>
#include <sstream>
#include <set>
#include <unordered_map>
#include <vector>
#include <string>

std::vector<std::string> split(std::string str) {
    std::istringstream buf(str);
    std::istream_iterator<std::string> beg(buf), end;
    std::vector<std::string> tokens(beg, end);
    return tokens;
}


bool wordPattern(std::string pattern, std::string str){
    std::vector<std::string> tokens;
    tokens = split(str);
    if(pattern.length() != tokens.size()) return false;

    std::unordered_map<char, std::string> m;
    std::set<std::string> s;
    for(int i = 0; i < pattern.length(); ++i){
        char p = pattern[i];
        std::string& w = tokens[i];

        if(! m.count(p)){
            if(s.find(w) != s.end()) return false;
            
            m[p] = w;
            s.insert(w);
            continue;
        }

        if(m[p] != w) return false;
    }
    return true;
}


int main(int argc, char *argv[]){
    std::string pattern;
    std::string str;

    std::getline(std::cin, pattern);
    std::getline(std::cin, str);

    std::cout << std::boolalpha << wordPattern(pattern, str) << "\n";
    return 0;
}
