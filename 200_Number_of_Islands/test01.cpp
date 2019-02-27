#include <iostream>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<T>> &v){
	for(auto row: v){
		for(auto it: row){
			os << it << " ";
		}
		os << "\n";
	}
	return os;
}

class UnionFind{
public:
    UnionFind(int n){
        count = n;
        id.resize(n);
        rank.resize(n);
        for(int i = 0; i < n; ++i){
            id[i] = i;
        }
    }

    int find(int p){
        while(p != id[p]){
            id[p] = id[id[p]];
            p = id[p];
        }
        return p;
    }

    int getCount(){
        return count;
    }

    bool connected(int p, int q){
        return find(p) == find(q);
    }

    void connect(int p, int q){
        int i = find(p);
        int j = find(q);

        if(i == j) return;
        if(rank[i] < rank[j]) id[i] = j;
        else if(rank[i] > rank[j]) id[j] = i;
        else{
            id[j] = i;
            rank[i]++;
        }
        count--;
    }

private:
    std::vector<int> id;
    std::vector<int> rank;
    int count;
};


int numIslands(std::vector<std::vector<char>>& grid) {
	int n = grid.size();
    if(n == 0) return 0;
	int m = grid[0].size();
    
    UnionFind uf(n*m+1);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(grid[i][j] == '1'){
                if(i-1 >= 0 && grid[i-1][j] == '1') uf.connect(i*m+j, (i-1)*m+j);
                if(i+1 < n &&  grid[i+1][j] == '1') uf.connect(i*m+j, (i+1)*m+j);
                if(j-1 >= 0 && grid[i][j-1] == '1') uf.connect(i*m+j, i*m+j-1);
                if(j+1 < m &&  grid[i][j+1] == '1') uf.connect(i*m+j, i*m+j+1);
            }
        }
    }

    std::vector<int> count(n*m);
    int res = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(grid[i][j] == '1'){
                int k = uf.find(i*m + j);
                if(count[k] == 0){
                    res++;
                    count[k]++;
                } else{
                    count[k]++;
                }
            }
        }
    }

    return res;
}

int main(int argc, char *argv[]){
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<char>> v(n, std::vector<char>(m));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			std::cin >> v[i][j];
		}
	}
	std::cout << numIslands(v) << "\n";
	return 0;
}
