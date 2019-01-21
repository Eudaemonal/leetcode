#include <iostream>
#include <string>
#include <stack>


int longestValidParentheses(std::string s){
    std::stack<int> stack;
    stack.push(-1);

    int max = 0;
    for(int i = 0; i < s.size(); ++i){
        int t = stack.top();
        if(t != -1 && s[i] == ')' && s[t] == '('){
            stack.pop();
            max = std::max(max, i - stack.top());
        }
        else{
            stack.push(i);
        }
    }
    return max;
}

int main(int argc, char *argv[]){
    std::string s;
    std::cin >> s;

    std::cout << longestValidParentheses(s) <<"\n";
    return 0;
}
