#include <iostream>
#include <vector>
#include <queue>
#include <utility>

template <typename T, typename U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {
    os << "[" << p.first << ", " << p.second << "]";
    return os;
}

template <template <typename, typename...> class ContainerType, 
          typename ValueType, typename... Args>
std::ostream& operator<<(std::ostream& os, const ContainerType<ValueType, Args...>& c){
    for(const auto& v : c){
        os << v << ' ';
    }
    os << '\n';
    return os;
}

bool canFinish(int numCourses, std::vector<std::pair<int, int>>& prerequisites) {
    std::vector<std::vector<int>> adj(numCourses, std::vector<int>());
    std::vector<int> degree(numCourses, 0);
    for(auto &pre: prerequisites){
        adj[pre.second].push_back(pre.first);
        degree[pre.first]++;
    }
    std::queue<int> q;
    for(int i = 0; i < numCourses; ++i){
        if(degree[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        numCourses--;
        for(auto next: adj[curr]){
            if(--degree[next] == 0){
                q.push(next);
            }
        }
    }
    return numCourses==0;
}

int main(int argc, char *argv[]){
    int k, n;
    std::cin >> k >> n;
    std::vector<std::pair<int, int>> v(n);
    for(int i = 0; i < n; ++i){
        std::cin >> v[i].first;
        std::cin >> v[i].second;        
    }

    std::cout << std::boolalpha << canFinish(k, v) << "\n";
    return 0;
}
