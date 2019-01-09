#include <iostream>
#include <stack>
#include <string>

bool isMatch(char lhs, char rhs){
    if(lhs == '(' && rhs == ')'){
        return true;
    }
    else if(lhs == '[' && rhs == ']'){
        return true;
    }
    else if(lhs == '{' && rhs == '}'){
        return true;
    }
    return false;
}

bool isLeft(char c){
    if(c == '(' || c == '[' || c == '{'){
        return true;
    }
    return false;
}

bool isRight(char c){
    if(c == ')' || c == ']' || c == '}'){
        return true;
    }
    return false;
}

bool isValid(std::string s){
    int n = s.length();
    std::stack<char> stack;

    if(n % 2){
        return false;
    }

    for(int i = 0; i < n; ++i){
        if(isLeft(s[i])){
            stack.push(s[i]);
        }
        else if(isRight(s[i])){
            if(!stack.empty() && isMatch(stack.top(), s[i])){
                stack.pop();
            }else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    if(!stack.empty()){
        return false;
    }
    return true;
}


int main(int argc, char *argv[]){
    std::string s;
    std::cin >> s;

    std::cout << std::boolalpha << isValid(s) << "\n";
}
