#include <iostream>
#include <string>
#include <vector>

template <typename T, typename U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {
    os << "[" << p.first << ", " << p.second << "]";
    return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& c){
    for(const auto& v : c){
        os << v << ' ';
    }
    os << '\n';
    return os;
}

void backtrack(std::vector<std::string> &v, std::string cur, int open, int close, int max){
	if(cur.length() == max*2){
		v.push_back(cur);
		return;
	}
	if(open < max){
		backtrack(v, cur+"(", open+1, close, max);
    }
	if(close < open){
		backtrack(v, cur+")", open, close+1, max);
    }
}

std::vector<std::string> generateParenthesis(int n){
    std::vector<std::string> v;
    backtrack(v, "", 0, 0, n);
    return v;
}

int main(int argc, char *argv[]){
    int n;
    std::cin >> n;

    std::cout << generateParenthesis(n);
    return 0;
}
