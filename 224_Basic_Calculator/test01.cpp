#include <iostream>
#include <vector>
#include <string>
#include <stack>

int calculate(std::string s) {
    std::stack<char> ops;
    std::stack<int> nums;
    int curnum = 0;
    for(int i = 0; i < s.size(); ++i){
        char c = s[i];
        if(c == ' ') continue;
        if(c == '(' || c == '+' || c == '-') { ops.push(c); continue;}
        if(c == ')') ops.pop(); 
        
        else if(isdigit(c)) {
            curnum = curnum * 10 + c -'0';
            if (i+1 < s.size() && isdigit(s[i+1])) continue;
            nums.push(curnum);
            curnum = 0;
        }
        
        if (ops.empty() || ops.top()=='(') continue;
        int n2 = nums.top(); nums.pop();                
        if (ops.top() == '+') nums.top() += n2;
        else if (ops.top() == '-') nums.top() -= n2;
        ops.pop();
    }
    return nums.top();
}


int main(int argc, char *argv[]){
    std::string str;
    std::getline(std::cin, str);

    std::cout << calculate(str) << "\n";
}
