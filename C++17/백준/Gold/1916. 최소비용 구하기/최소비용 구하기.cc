#include <iostream>
#include <vector>
#include <queue>

int main() {
	std::cin.tie(nullptr);
	std::ios::sync_with_stdio(false);

	int N, M;
	std::cin >> N >> M;
	struct Bus {
		int End, Value;
	};
	std::vector<std::vector<Bus>> BusData(N+1);

	for (int i = 0; i < M; ++i) {
		int Start, End, Value;
		std::cin >> Start >> End >> Value;
		BusData[Start].emplace_back(Bus{ End, Value });
	}
	int StartCity, EndCity;
	std::cin >> StartCity >> EndCity;
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> PQ;
	PQ.emplace(0, StartCity);
	std::vector<int> Dist(N + 1, INT32_MAX);
	while (!PQ.empty()) {
		int CurValue = PQ.top().first;
		int CurCity = PQ.top().second; 
		PQ.pop();

		if (CurValue > Dist[CurCity]) {
			continue;
		}

		if (CurCity == EndCity) {
			std::cout << CurValue;
			break;
		}


		for (const Bus& NextCityBus : BusData[CurCity]) {
			int NewValue = CurValue + NextCityBus.Value;
			if (NewValue < Dist[NextCityBus.End]) {
				PQ.emplace(NewValue, NextCityBus.End);
				Dist[NextCityBus.End] = NewValue;
			}
		}
	}
}