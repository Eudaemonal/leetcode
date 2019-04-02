#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

void dfs(std::vector<std::string>& result, std::unordered_set<std::string> &visited, std::string s, int &maxLength, int pos, int cnt){
	if(s.length() < maxLength || visited.find(s) != visited.end()) return;
    visited.insert(s);
	
    std::string tmp = s;
	for(; pos < s.length(); pos++){
		if(s[pos] == '(' || s[pos] == ')'){
		    char deleted = s[pos];
		    tmp.erase(tmp.begin() + pos);
		    dfs(result, visited, tmp, maxLength, pos, cnt);
		    tmp.insert(tmp.begin() + pos, deleted);
		}
	
		if(s[pos] == '(') cnt++;
		else if(s[pos] == ')') cnt--;
		
        if(cnt < 0) break; 
	}
	
	if(!cnt){
	    if(s.length() > maxLength){
	        result.clear();
	        maxLength = s.length();
	    }
	    result.push_back(s);
	}
}


std::vector<std::string> removeInvalidParentheses(std::string s) {
    if(s.length() == 0) return std::vector<std::string>{s};
	
	std::vector<std::string> result;
	std::unordered_set<std::string> visited;
	int maxLength = 0;
	dfs(result, visited, s, maxLength, 0, 0);
	return result;
}


int main(int argc, char *argv[]){
    std::string s;
    std::getline(std::cin, s);
    
    std::vector<std::string> res = removeInvalidParentheses(s);
    for(auto c: res)
        std::cout << c << "\n";
    
    return 0;
}
