#include <iostream>
#include <string>
#include <unordered_map>


int lengthOfLongestSubstring(std::string s){
    std::unordered_map<char, int> m;
    int max_len = 0, start = 0;
    for(int i = 0; i < s.length(); ++i){
        if(m.count(s[i]) && m[s[i]] >= start) {
            start = m[s[i]] + 1;
        }
        m[s[i]] = i;
        max_len = std::max(max_len, i - start + 1);
    }
    return max_len;
}


int main(int argc, char *argv[]){
    std::string s;
    std::getline(std::cin, s);
	
	std::cout <<lengthOfLongestSubstring(s) << "\n";
	return 0;
}
