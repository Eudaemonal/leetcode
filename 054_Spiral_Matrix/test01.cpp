#include <iostream>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T> &v){
	for(size_t i=0; i < v.size(); ++i){
		os << v[i] << " ";
	}
    os << "\n";
	return os;
}

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

std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
    std::vector<int> res;
    if(matrix.size() == 0){
        return res;
    }
    int n = matrix.size();
    int m = matrix[0].size();
    int r1 = 0, r2 = n - 1;
    int c1 = 0, c2 = m - 1;
    while(r1 <= r2 && c1 <= c2) {
        for(int c = c1; c <= c2; ++c){
            res.push_back(matrix[r1][c]);
        }
        for(int r = r1 + 1; r <= r2; ++r) {
            res.push_back(matrix[r][c2]);
        }
        if(r1 < r2 && c1 < c2) {
            for(int c = c2 - 1; c > c1; --c){
                res.push_back(matrix[r2][c]);
            }
            for(int r = r2; r > r1; --r){
                res.push_back(matrix[r][c1]);
            }
        }
        r1++;
        r2--;
        c1++;
        c2--;
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
	
	std::cout << spiralOrder(v) << "\n";
	return 0;
}
