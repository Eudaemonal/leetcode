#include <iostream>
#include <vector>
#include <string>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<T>> &v){
	for(size_t i=0; i < v.size(); ++i){
		for(size_t j=0; j < v[0].size(); ++j){
			os << v[i][j] << " ";
		}
		os << "\n";
	}
	return os;
}

std::string longestPalindrome(std::string s){
    int n = s.length();
    std::vector<std::vector<bool>> dp(n, std::vector<bool>(n));
    std::string res;
    int start = 0, max = 0;
    for(int j = 0 ; j < n; ++j){
        for(int i = 0 ; i <= j; ++i){
            bool judge = (s[i]==s[j]);
            if(j - i > 2){
                dp[i][j] = dp[i + 1][j - 1] && judge;
            }else{
                dp[i][j] = judge;
            }
            if(dp[i][j] && j - i + 1 > max){
                max = j - i + 1;
                start = i;
            }
        }
    }
    res = s.substr(start, max);
    return res;
}


int main(int argc, char *argv[]){
    std::string s;
    std::getline(std::cin, s);

    std::cout << longestPalindrome(s) << "\n";
    return 0;
}
