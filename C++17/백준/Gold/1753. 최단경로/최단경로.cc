#include <iostream>
#include <vector>
#include <queue>

int main() {
	std::cin.tie(nullptr);
	std::ios::sync_with_stdio(false);
	int V, E;
	std::cin >> V >> E;
	int StartCity;
	std::cin >> StartCity;
	
	struct Edge {
		int End, Value;
	};
	std::vector<std::vector<Edge>> Graph(V + 1);

	for (int i = 0; i < E; ++i) {
		int Start, End, Value;
		std::cin >> Start >> End >> Value;
		Graph[Start].emplace_back(Edge{ End, Value });
	}
	std::vector<int> Dist(V + 1, INT32_MAX);
	Dist[StartCity] = 0;
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> PQ;
	PQ.emplace(0, StartCity);
	while (!PQ.empty()) {
		int CurValue = PQ.top().first;
		int CurNode = PQ.top().second;
		PQ.pop();

		// 이미 최적의 길을 찾음
		if (CurValue > Dist[CurNode]) {
			continue;
		}
		
		for (const Edge& Next : Graph[CurNode]) {
			int NewValue = CurValue + Next.Value;
			if (NewValue < Dist[Next.End]) {
				Dist[Next.End] = NewValue;
				PQ.emplace(NewValue, Next.End);
			}
		}
	}

	for (int i = 1; i <= V; ++i) {
		if (Dist[i] == INT32_MAX) {
			std::cout << "INF" << "\n";
			continue;
		}
		std::cout << Dist[i] << "\n";

	}
}