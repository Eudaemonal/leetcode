#include <iostream>
#include <vector>

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

std::vector<int> findMinHeightTrees(int n, std::vector<std::pair<int, int>>& edges) {
    std::vector<int> result;
    if(n == 1){
        result.push_back(0);
        return result;
    }
    std::vector<std::vector<int>> graph(n, std::vector<int>());
    std::vector<int> degree(n, 0);
    for(int i = 0; i < edges.size(); i++){
        graph[edges[i].first].push_back(edges[i].second);
        graph[edges[i].second].push_back(edges[i].first);
        degree[edges[i].first]++;
        degree[edges[i].second]++;
    }
    int count = n;
    while(count > 2){
        std::vector<int> records;
        for(int i = 0; i < n; i++){
            if(degree[i] == 1){
                records.push_back(i);
                degree[i] = -1;
                count--;
            }
        }
        for(int i = 0; i < records.size(); i++){
            for(auto it: graph[records[i]]){
                degree[it]--;
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(degree[i] == 1 || degree[i] == 0){
            result.push_back(i);
        }
    }
    return result;
}

int main(int argc, char *argv[]){
    int num, n, a, b;
    std::cin >> num;
    std::cin >> n;
    std::vector<std::pair<int, int>> v(n);
    for(int i = 0; i < n; ++i){
        std::cin >> a;
        std::cin >> b;
        v.push_back(std::make_pair(a, b));
    }

    std::cout << findMinHeightTrees(num, v);
    return 0;
}
