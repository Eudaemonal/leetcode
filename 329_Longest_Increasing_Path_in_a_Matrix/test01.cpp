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

int dfs(std::vector<std::vector<int>>& matrix, int i, int j, int m, int n, std::vector<std::vector<int>>& cache){
    if(cache[i][j] != 0) return cache[i][j];
    int max = 1;

    std::vector<std::pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    for(std::pair<int, int> dir : dirs){
        int x = i + dir.first;
        int y = j + dir.second;
        if(x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] <= matrix[i][j]) continue;
        int len = 1 + dfs(matrix, x, y, m, n, cache);
        max = std::max(max, len);
    }
    cache[i][j] = max;
    return max;
}

int longestIncreasingPath(std::vector<std::vector<int>>& matrix) {
	int n = matrix.size();
    if(n == 0) return 0;
	int m = matrix[0].size();
    int res = 1;
    std::vector<std::vector<int>> cache(n, std::vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int len = dfs(matrix, i, j, m, n, cache);
            res = std::max(res, len);
        }
    }
    return res;
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
	
	std::cout << longestIncreasingPath(v) << "\n";
	return 0;
}
