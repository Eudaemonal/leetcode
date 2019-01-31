#include <iostream>
#include <sstream>
#include <string>
#include <deque>

std::string simplifyPath(std::string path) {
    std::istringstream ss(path);
    std::deque<std::string> sub_path_stack;
    std::string sub_path;
    std::string res;

    while(std::getline(ss, sub_path, '/')){
        if(sub_path == "." || sub_path == ""){
            continue;
        }
        if(sub_path == ".." && !sub_path_stack.empty()){
            sub_path_stack.pop_front();
        }else if(sub_path != "..") {
            sub_path_stack.push_front(sub_path);
        }
    }
    while(!sub_path_stack.empty()){
        res += "/" + sub_path_stack.back();
        sub_path_stack.pop_back();
    }
    return res.empty() ? "/": res;
}

int main(int argc, char *argv[]){
    std::string s;
    std::cin >> s;

    std::cout << simplifyPath(s) << "\n";
}
