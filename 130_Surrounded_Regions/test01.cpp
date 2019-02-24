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

class Union{
public:
    Union(int n){
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

void solve(std::vector<std::vector<char>>& board) {
    int n = board.size();
    int m = board[0].size();
    
    if(n ==0) return;

    Union uf(n*m+1);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if((i==0||i==n-1||j==0||j==m-1) && board[i][j] == 'O'){
                uf.connect(i*m+j, n*m);
            }else if(board[i][j] == 'O'){
                if(board[i-1][j] == 'O') uf.connect(i*m+j, (i-1)*m+j);
                if(board[i+1][j] == 'O') uf.connect(i*m+j, (i+1)*m+j);
                if(board[i][j-1] == 'O') uf.connect(i*m+j, i*m+j-1);
                if(board[i][j+1] == 'O') uf.connect(i*m+j, i*m+j+1);
            }
        }
    }
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(!uf.connected(i*m+j, n*m)){
                board[i][j] = 'X';
            }
        }
    }
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
	
    solve(v);
	std::cout << v;
	return 0;
}
