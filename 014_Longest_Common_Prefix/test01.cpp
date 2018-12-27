#include <iostream>
#include <string>
#include <vector>


std::string longestCommonPrefix(std::vector<std::string>& strs) {
    std::string prefix = "";
    for(int idx = 0; strs.size() > 0; prefix += strs[0][idx], idx++){
        for(int i = 0; i < strs.size(); ++i){
            if(idx >= strs[i].size() || (i > 0 && strs[i][idx] != strs[i-1][idx])){
                return prefix;
            }
        }
    }
    return prefix;
}

int main(int argc, char *argv[]){
    int n;
    std::cin >> n;
    std::vector<std::string> v(n);
    for(int i = 0; i < n; ++i){
        std::cin >> v[i];
    }

    std::cout << longestCommonPrefix(v) << "\n";
    return 0;
}
