#include <iostream>
#include <string>
#include <vector>

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

bool isPalindrome(std::string s, int start, int end){
    while(start < end){
        if(s[start] != s[end]) return false;
        start++;
        end--;
    }
    return true;
}

void partition(std::string s, int start, std::vector<std::string>& curr, std::vector<std::vector<std::string>>& res){
    int n = s.length();
    if(start == n){
        res.push_back(curr);
        return;
    }
    for(int i = start; i < n; ++i){
        if(isPalindrome(s, start, i)){
            curr.push_back(s.substr(start, i+1-start));
            partition(s, i+1, curr, res);
            curr.pop_back();
        }
    }
}


std::vector<std::vector<std::string>> partition(std::string s) {
    int n = s.length();
    std::vector<std::vector<std::string>> res;
    if(n == 0) return res;
    std::vector<std::string> v;
    partition(s, 0, v, res);
    return res;
}


int main(int argc, char *argv[]){
	std::string s;
	std::cin >> s;
	
	std::cout << partition(s);
	return 0;
}
