#include <iostream>
#include <vector>
#include <queue>
int main() {
	// 일단 모든 쌍의 최소거리를 구하는거니까
	// 플루이드 워셜을 쓰면 될것같고
	// N이 1000, M이 10000
	// N^2 1000000 가능,
	// M^2 100000000 가능,
	
	std::cin.tie(nullptr);
	int N,M,X;
	std::cin >> N >> M >> X;
	std::vector<std::vector<std::pair<int,int>>> Graph(N + 1);
	for (int i = 0; i < M; ++i) {
		int Start, End, Weight;
		std::cin >> Start >> End >> Weight;
		Graph[Start].emplace_back(End, Weight);
	}

	// 일단 모든 출발지에서 X 로 가는 최단경로를 찾고
	std::vector<int> ToX(N + 1, INT32_MAX);
	for (int i = 1; i < N + 1; ++i) {
		if (i == X) {
			continue;
		}
		std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> PQ;
		std::vector<int> CurNearest(N + 1, INT32_MAX);
		// 현재 weight, 현재 도시
		PQ.emplace(0, i);
		while (!PQ.empty()) {
			std::pair<int, int> Cur = PQ.top(); PQ.pop();
			// X에 도착했으면 남기고 나가면 됨
			if (Cur.second == X) {
				ToX[i] = Cur.first;
				break;
			}

			// 지금 경로가 더 길면 굳이 갈 필요가 없음
			if (Cur.first >= CurNearest[Cur.second]) {
				continue;
			}
			CurNearest[Cur.second] = Cur.first;

			for (const std::pair<int, int>& Next : Graph[Cur.second]) {
				PQ.emplace(Next.second + Cur.first, Next.first);
			}
		}
	}

	// 여기까지 하면 ToX는 구했으니까,
	// X로부터 다른 지역으로 가는 가장 저렴버젼을 구하면 됨
	std::vector<int> XToOther(N + 1, INT32_MAX);
	{
		std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> PQ;
		PQ.emplace(0, X);
		while (!PQ.empty()) {
			std::pair<int, int> Cur = PQ.top(); PQ.pop();
			if (Cur.first >= XToOther[Cur.second]) {
				continue;
			}

			XToOther[Cur.second] = Cur.first;
			for (std::pair<int, int>& Next : Graph[Cur.second]) {
				PQ.emplace(Cur.first + Next.second, Next.first);
			}
		}
	}

	int Answer = 0;
	for (int i = 1; i < N + 1; ++i) {
		if (i == X) {
			continue;
		}
		Answer = std::max(Answer, ToX[i] + XToOther[i]);
	}

	std::cout << Answer;
}