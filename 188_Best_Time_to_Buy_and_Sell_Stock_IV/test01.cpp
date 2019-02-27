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

int findMinMax(std::vector<int>& prices, std::vector<int>& minP, std::vector<int>& maxP){
    int n = prices.size(), res = 0;
    for(int i = 0; i < n-1; i++){
        while(i < n-1 && prices[i+1] <= prices[i]) i++;
        if(i < n-1) minP.push_back(prices[i]);
        else break;
        while(i < n-1 && prices[i+1] >= prices[i]) i++;
        maxP.push_back(prices[i]);
        res += maxP.back() - minP.back();
    }
    return res;
}

int FSM_stock(std::vector<int>& minP, std::vector<int>& maxP, int k){
    int states[2][1+2*k], cur = 0, next = 1, res = 0, numMax = maxP.size();
    std::fill_n(&states[0][1], 2*k, INT_MIN/2);
    states[0][0] = states[1][0] = 0;
    for(int i = 0; i < numMax; i++){
        for(int j= 0; j < k; j++){
            states[next][j*2+1] = std::max(states[cur][j*2+1], states[cur][j*2] - minP[i]);
            states[next][j*2+2] = states[cur][j*2+2];
        }
        std::swap(cur, next);
        for(int j = 1; j <= k; ++j){
            states[next][j*2] = std::max(states[cur][j*2], states[cur][j*2-1] + maxP[i]);
            states[next][j*2-1] = states[cur][j*2-1];
        }
        std::swap(cur, next);
    }
    for(int i = 1; i <= k; ++i) res = std::max(res, states[cur][i*2]);
    return res;
}

int maxProfit(int k, std::vector<int>& prices) {
    std::vector<int> minP, maxP;
    int res = findMinMax(prices, minP, maxP);

    if(maxP.size() <= k) return res;
    else{
        return FSM_stock(minP, maxP, k);
    }
}

int main(int argc, char *argv[]){
    int k, n;
    std::cin >> k;
    std::cin >> n;
    std::vector<int> v(n);
    for(int i = 0; i < n; ++i){
        std::cin >> v[i];
    }

    std::cout << maxProfit(k, v) << "\n";
    return 0;
}
