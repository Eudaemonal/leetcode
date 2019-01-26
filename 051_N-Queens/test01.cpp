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

bool isValid(std::vector<std::string>& nQueens, int row, int col, int& n){
    for(int i = 0; i < row; ++i){
        if(nQueens[i][col] == 'Q'){
            return false;
        }
    }
    for(int i = row - 1, j = col-1; i >= 0 && j >= 0; --i, --j){
        if(nQueens[i][j] == 'Q'){
            return false;
        }
    }
    for(int i = row-1, j = col+1; i >=0 && j < n; --i, ++j){
        if(nQueens[i][j] == 'Q'){
            return false;
        }
    }
    return true;
}

void solveNQueens(std::vector<std::vector<std::string>>& res, std::vector<std::string> &nQueens, int row, int& n){
    if(row == n){
        res.push_back(nQueens);
        return;
    }

    for(int col = 0; col != n; ++col){
        if(isValid(nQueens, row, col, n)) {
            nQueens[row][col] = 'Q';
            solveNQueens(res, nQueens, row + 1, n);
            nQueens[row][col] = '.';
        }
    }
}

std::vector<std::vector<std::string>> solveNQueens(int n) {
    std::vector<std::vector<std::string>> res;
    std::vector<std::string> nQueens(n, std::string(n, '.'));
    solveNQueens(res, nQueens, 0, n);
    return res;
}

int main(int argc, char *argv[]){
	int n;
    std::cin >> n;

    std::cout << solveNQueens(n);
	return 0;
}
