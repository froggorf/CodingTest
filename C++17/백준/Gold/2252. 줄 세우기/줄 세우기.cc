#include <iostream>
#include <vector>
#include <queue>

int main() {
	std::cin.tie(nullptr);
	std::ios::sync_with_stdio(false);
	int N, M;
	std::cin >> N >> M;

	std::vector<int> Degree(N + 1, 0);
	std::vector<std::vector<int>> Nexts(N + 1);
	for (int i = 0; i < M; ++i) {
		int Left, Right;
		std::cin >> Left >> Right;
		Nexts[Left].emplace_back(Right);
		++Degree[Right];
	}

	std::queue<int> Q;
	for (int i = 1; i <= N; ++i) {
		if (Degree[i] == 0) {
			Q.emplace(i);
		}
	}

	while (!Q.empty()) {
		int Cur = Q.front(); Q.pop();
		std::cout << Cur << " ";
		for (int Next : Nexts[Cur]) {
			--Degree[Next];
			if (Degree[Next] == 0) {
				Q.emplace(Next);
			}
		}
	}


}