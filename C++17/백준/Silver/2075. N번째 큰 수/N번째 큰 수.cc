#include <iostream>
#include <vector>
#include <queue>

// N번째로 큰수를 찾아야하는데,
// 가장 큰 수는 맨아래에 있겠지
// N개에 대해서 

struct Data {
	int Value;
	int X;
	int Y;
	bool operator<(const Data& Other) const {
		return Value < Other.Value;
	}
};

struct Pred{
	bool operator()(const Data& A, const Data& B) {
		return A.Value < B.Value;
	}
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int N;
	std::cin >> N;
	std::vector<std::vector<int>> Board(N, std::vector<int>(N));

	std::priority_queue<Data, std::vector<Data>, Pred> PQ;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			std::cin >> Board[i][j];
			
			if (i == N - 1) {
				PQ.emplace(Data{Board[i][j],i,j });
			}
		}
	}

	int Count = 0;
	while (++Count < N) {
		Data CurMax = PQ.top(); PQ.pop();
		if (CurMax.X > 0) {
			PQ.emplace(Data{ Board[CurMax.X - 1][CurMax.Y], CurMax.X - 1, CurMax.Y });
		}
		
	}
	
	std::cout << PQ.top().Value;
}