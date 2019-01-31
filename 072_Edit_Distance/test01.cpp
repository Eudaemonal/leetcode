#include <iostream>
#include <string>
#include <vector>

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

int minDistance(std::string word1, std::string word2) {
    int n = word1.length();
    int m = word2.length();
    std::vector<std::vector<int>> dp(n+1, std::vector<int>(m+1));

    for(int i = 0; i < n+1; ++i){
        for(int j = 0; j < m+1; ++j){
            if(i == 0 && j == 0) {
                dp[i][j] = 0;
            }
            else if(i == 0) {
                dp[i][j] = j;
            }
            else if(j == 0) {
                dp[i][j] = i;
            }
            else if(word1[i-1] != word2[j-1]){
                dp[i][j] = 1 + std::min(dp[i-1][j-1], std::min(dp[i][j-1], dp[i-1][j]));
            }
            else if(word1[i-1] == word2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
        }
    }
    return dp[n][m];
}

int main(int argc, char *argv[]){
    std::string word1, word2;
    std::cin >> word1 >> word2;

	std::cout << minDistance(word1, word2) << "\n";
	return 0;
}
