#include <iostream>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<T>> &v){
	for(auto row: v){
		for(auto it: row){
			os << it << " ";
		}
		os << "\n";
	}
	return os;
}

int maximalSquare(std::vector<std::vector<char>>& matrix) {
    int n = matrix.size();
    if(n == 0) return 0;
    int m = matrix[0].size();

    std::vector<std::vector<int>> dp(n+1, std::vector<int>(m+1));
    int len = 0;
    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < m+1; j++){
            if(matrix[i-1][j-1] == '1'){
                dp[i][j] = std::min(std::min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]) + 1;
                len = std::max(len, dp[i][j]);
            }
        }
    }
    return len * len;
}



int main(int argc, char *argv[]){
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<char>> v(n, std::vector<char>(m));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			std::cin >> v[i][j];
		}
	}
	
	std::cout << maximalSquare(v) << "\n";
	return 0;
}
