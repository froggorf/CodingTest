#include <iostream>
#include <vector>

struct Data {
	
	int Start;
	int End;
	int Value;
};

int main() {
	int N, M;
	std::cin >> N >> M;
	std::vector<Data> Edges;
	for (int i = 0; i < M; ++i) {
		int Start, End, Value;
		std::cin >> Start >> End >> Value;
		Edges.emplace_back(Data{ Start, End, Value });
	}

	std::vector<long long> Dist(N + 1, INT64_MAX);
	Dist[1] = 0;
	for (int i = 0; i < N; ++i) {
		for (const Data& Edge : Edges) {
			if (Dist[Edge.Start] != INT64_MAX
				&& Dist[Edge.End] > Dist[Edge.Start] + Edge.Value) {
				Dist[Edge.End] = Dist[Edge.Start] + Edge.Value;
			}
		}
	}

	for (const Data& Edge : Edges) {
		if (Dist[Edge.Start] != INT64_MAX
			&& Dist[Edge.End] > Dist[Edge.Start] + Edge.Value) {
			std::cout << -1;
			return 0;
		}
	}

	for (int i = 2; i < N + 1; ++i) {
		if (Dist[i] == INT64_MAX) {
			std::cout << -1 << "\n";
		}
		else {
			std::cout << Dist[i] << "\n";
		}
	}
}