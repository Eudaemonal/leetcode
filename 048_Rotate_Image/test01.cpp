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

void rotate(std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();
    std::reverse(matrix.begin(), matrix.end());
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }
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
	
    rotate(v);
	std::cout << v;
	return 0;
}
