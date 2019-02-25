#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
    int n = s.length();
    std::vector<bool> dp(n+1);
    dp[0] = true;

    std::unordered_map<std::string, int> dict;
    for(std::string word: wordDict){
        dict[word] = 1;
    }

    for(int i = 0; i < n+1; ++i){
        for(int j = 0; j < i; ++j){
            if(dict.find(s.substr(j, i-j)) != dict.end() && dp[j]){
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}

int main(int argc, char *argv[]){
    int n;
    std::string s;
    std::cin >> s;
    std::cin >> n;
    std::vector<std::string> v(n);
    for(int i = 0; i < n; ++i){
        std::cin >> v[i];
    }

    std::cout << std::boolalpha << wordBreak(s, v) << "\n";
    return 0;
}
