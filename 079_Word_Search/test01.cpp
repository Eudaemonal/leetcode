#include <iostream>
#include <vector>
#include <queue>

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


bool search(int i, int j, std::vector<std::vector<char>>& board, std::string word){
    int n = board.size();
    int m = board[0].size();

    if(!word.length()) return true;

    if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[0]){
        return false;
    }
    char c = board[i][j];
    board[i][j] = '*';
    std::string s = word.substr(1);
    bool ret = search(i-1, j, board, s) || search(i+1, j, board, s) || search(i, j-1, board, s) || search(i, j+1, board, s);
    board[i][j] = c;
    return ret;
}

bool exist(std::vector<std::vector<char>>& board, std::string word){
    int n = board.size();
    int m = board[0].size();    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(search(i, j, board, word)){
                return true;
            }
        }
    }
    return false;
}


int main(int argc, char *argv[]){
    std::string s;
    std::cin >> s;
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<char>> v(n, std::vector<char>(m));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			std::cin >> v[i][j];
		}
	}
	
	std::cout << std::boolalpha << exist(v, s) << "\n";
	return 0;
}
