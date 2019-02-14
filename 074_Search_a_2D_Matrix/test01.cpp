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

bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    int row = 0, col = matrix[0].size() -1;
    while(row < matrix.size() && col >= 0){
        if(matrix[row][col] > target){
            col--;
        }else if(matrix[row][col] < target){
            row++;
        }else{
            return true;
        }
    }
    return false;
}

int main(int argc, char *argv[]){
	int n, m, t;
    std::cin >> t;
	std::cin >> n >> m;
	std::vector<std::vector<int>> v(n, std::vector<int>(m));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			std::cin >> v[i][j];
		}
	}
	
	std::cout << std::boolalpha << searchMatrix(v, t) << "\n";
	return 0;
}
