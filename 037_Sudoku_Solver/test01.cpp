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

bool check(std::vector<std::vector<char>> &board, int i, int j, char val){
    int row = i - i%3, column = j - j%3;
    for(int x = 0; x < 9; ++x) if(board[x][j] == val) return false;
    for(int y = 0; y < 9; ++y) if(board[i][y] == val) return false;
    for(int x = 0; x < 3; ++x)
    for(int y = 0; y < 3; ++y) if(board[row+x][column+y] == val) return false;
    return true;
}

bool solver(std::vector<std::vector<char>>& board, int i, int j){
    if(i == 9) return true;
    if(j == 9) return solver(board, i+1, 0);
    if(board[i][j] != '.') return solver(board, i, j+1);

    for(char c = '1'; c <= '9'; ++c){
        if(check(board, i, j, c)){
            board[i][j] = c;
            if(solver(board, i, j+1)) return true;
            board[i][j] = '.';
        }
    }
    return false;
}

void solveSudoku(std::vector<std::vector<char>>& board) {
    solver(board, 0, 0);
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
	
    solveSudoku(v);

	std::cout << v;
	return 0;
}
