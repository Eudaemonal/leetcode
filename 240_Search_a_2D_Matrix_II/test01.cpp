#include <iostream>
#include <vector>
#include <queue>

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

bool searchMatrix(std::vector<std::vector<int>>& matrix, int target){
    int n = matrix.size();
    if(n == 0) return false;
    int m = matrix[0].size();

    int i = 0, j = m - 1;
    while (i < n && j >= 0) {
        if (matrix[i][j] == target) {
            return true;
        }
        if(matrix[i][j] > target) j--; 
        else i++;
    }
    return false;
}

int main(int argc, char *argv[]){
	int k, n, m;
    std::cin >> k;
	std::cin >> n >> m;
	std::vector<std::vector<int>> v(n, std::vector<int>(m));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			std::cin >> v[i][j];
		}
	}
	
	std::cout << std::boolalpha << searchMatrix(v, k) << "\n";
	return 0;
}
