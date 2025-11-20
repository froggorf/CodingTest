#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
struct Pred {
	bool operator()(const std::pair<int, int>& A, const std::pair<int, int>& B) {
		if (A.first == B.first) {
			return A.second < B.second;
		}
		return A.first > B.first;
	}
};




int main() {
	int N, M;
	std::cin >> N >> M;
	
	std::map<int, int> Ladders;
	std::vector<bool> bIsLadderStart(101,false);
	std::map<int, int> Snakes;
	std::vector<bool> bIsSnakeStart(101, false);
	for (int i = 0; i < N; ++i) {
		int Start, End;
		std::cin >> Start >> End;
		bIsLadderStart[Start] = true;
		Ladders[Start] = End;
	}
	for (int i = 0; i < M; ++i) {
		int Start, End;
		std::cin >> Start >> End;
		bIsSnakeStart[Start] = true;
		Snakes[Start] = End;
	}

	// 일단 그리디로 풀어볼것같음
	// 그리디는 생각보다 복잡함..
	// 수행횟수가 적은 방향으로 PQ를 써볼까?

	int LastMinCount[101];
	for (int i = 0; i < 101; ++i) {
		LastMinCount[i] = INT32_MAX;
	}

	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Pred> PQ;
	PQ.emplace(0, 1);
	int Cur = 1;
	while (!PQ.empty()) {
		std::pair<int, int> Cur = PQ.top(); PQ.pop();
		if (LastMinCount[Cur.second] < Cur.first) {
			continue;
		}
		LastMinCount[Cur.second] = Cur.first;

		if (bIsLadderStart[Cur.second]) {
			int Next = Ladders[Cur.second];
			PQ.emplace(Cur.first, Next);
			continue;
		}
		else if (bIsSnakeStart[Cur.second]) {
			PQ.emplace(Cur.first, Snakes[Cur.second]);
			continue;
		}

		if (Cur.second >= 94) {
			std::cout << Cur.first + 1;
			return 0;
		}

		for (int i = 1; i <= 6; ++i) {
			int Arrive = Cur.second + i;
			
			PQ.emplace(Cur.first + 1, Arrive);
		}
	}
	
}