#include <iostream>
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


int uniquePaths(int m, int n) {
    std::vector<std::vector<int>> dp(m, std::vector<int>(n));
    if(m == 0) return 0;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(i == 0 && j == 0){
                dp[i][j] = 1;
            }
            else if(i == 0){
                dp[i][j] = dp[i][j-1];
            }
            else if(j == 0){
                dp[i][j] = dp[i-1][j];
            }
            else {
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
    }
    return dp[m-1][n-1];
}

int main(int argc, char *argv[]){
	int n, m;
	std::cin >> m >> n;
	
	std::cout << uniquePaths(m, n) << "\n";
	return 0;
}
