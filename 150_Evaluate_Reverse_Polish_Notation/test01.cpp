#include <iostream>
#include <string>
#include <vector>
#include <stack>

bool isDigit(std::string s){
    int i = 0;
    if(s[i] == '-' && s.length() > 1) i++;
    while(s[i] >= '0' && s[i] <= '9') i++;
    if(i != s.length()) return false;
    return true;
}

bool isOperator(std::string s){
    if(s.length() == 1 && (s == "+" || s == "-" || s == "*" || s == "/")){
        return true;
    }
    return false;
}

int calculate(int lhs, int rhs, char op){
    int res;
    switch(op){
        case '+': res = lhs + rhs;
            break;
        case '-': res = lhs - rhs;
            break;
        case '*': res = lhs * rhs;
            break;
        case '/': res = lhs / rhs;
            break;
        default:
            break;
    }
    return res;
}

int evalRPN(std::vector<std::string>& tokens){
    std::stack<std::string> s;
    for(std::string token: tokens){
        if(isDigit(token)){
            s.push(token);
        }
        else if(isOperator(token) && s.size() > 1){
            int rhs = std::stoi(s.top());
            s.pop();
            int lhs = std::stoi(s.top());
            s.pop();
            s.push(std::to_string(calculate(lhs, rhs, token[0])));
        }
        else{
            std::cout << "Error\n";
        }
    }
    return std::stoi(s.top());
}

int main(int argc, char *argv[]){
    int n;
    std::cin >> n;
    std::vector<std::string> v(n);
    for(int i = 0; i < n; ++i){
        std::cin >> v[i];
    }

    std::cout << evalRPN(v) << "\n";
    return 0;
}
