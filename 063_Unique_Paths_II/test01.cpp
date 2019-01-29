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

int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
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
            if(obstacleGrid[i][j]){
                dp[i][j] = 0;
            }
        }
    }
    return dp[m-1][n-1];
}

int main(int argc, char *argv[]){
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> v(n, std::vector<int>(m));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			std::cin >> v[i][j];
		}
	}
	
	std::cout << uniquePathsWithObstacles(v) << "\n";
	return 0;
}
