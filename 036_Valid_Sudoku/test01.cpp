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

bool isValidSudoku(std::vector<std::vector<char>>& board) {
    std::vector<int> col(9, 0);
    std::vector<int> block(9, 0);
    std::vector<int> row(9, 0);
    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 9; ++j){
            if(board[i][j] != '.'){
                int idx = 1 << (board[i][j] - '0');
                if(row[i] & idx || col[j] & idx || block[i/3 * 3 + j / 3] & idx){
                    return false;
                }
                row[i] |= idx;
                col[j] |= idx;
                block[i/3 * 3 + j / 3] |= idx;
            }
        }
    }
    return true;
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
	
	std::cout << std::boolalpha << isValidSudoku(v) << "\n";
	return 0;
}
