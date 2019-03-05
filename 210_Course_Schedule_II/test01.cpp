#include <iostream>
#include <vector>
#include <unordered_set>
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

std::vector<std::unordered_set<int>> make_graph(int numCourses, std::vector<std::pair<int, int>>& prerequisites) {
    std::vector<std::unordered_set<int>> graph(numCourses);
    for(auto pre: prerequisites){
        graph[pre.second].insert(pre.first);
    }
    return graph;
}

std::vector<int> compute_indegree(std::vector<std::unordered_set<int>>& graph){
    std::vector<int> degree(graph.size());
    for(auto neighbors: graph){
        for(int neigh: neighbors){
            degree[neigh]++;
        }
    }
    return degree;
}


std::vector<int> findOrder(int numCourses, std::vector<std::pair<int, int>>& prerequisites) {
    std::vector<std::unordered_set<int>> graph = make_graph(numCourses, prerequisites);
    std::vector<int> degrees = compute_indegree(graph);
    std::queue<int> zeros;
    for(int i = 0; i < numCourses; ++i){
        if(!degrees[i]) zeros.push(i);
    }
    std::vector<int> toposort;
    for(int i = 0; i < numCourses; ++i){
        if(zeros.empty()) return {};
        int zero = zeros.front();
        zeros.pop();
        toposort.push_back(zero);
        for(int neigh: graph[zero]){
            if(!--degrees[neigh]){
                zeros.push(neigh);
            }
        }
    }
    return toposort;
}

int main(int argc, char *argv[]){
    int k, n;
    std::cin >> k >> n;
    std::vector<std::pair<int, int>> v(n);
    for(int i = 0; i < n; ++i){
        std::cin >> v[i].first;
        std::cin >> v[i].second;
    }

    std::cout << findOrder(k, v);
    return 0;
}
