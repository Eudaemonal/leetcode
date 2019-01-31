#include <iostream>
#include <vector>
#include <set>

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

void setZeroes(std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    if(n * m == 0) return;

    std::set<int> row, col;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(matrix[i][j] == 0){
                row.insert(i);
                col.insert(j);
            }
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(row.count(i) || col.count(j)){
                matrix[i][j] = 0;
            }
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
	
    setZeroes(v);
	std::cout << v;
	return 0;
}
