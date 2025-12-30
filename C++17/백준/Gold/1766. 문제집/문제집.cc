#include <iostream>
#include <vector>
#include <queue>
int main() {
	// 문제가 딱봐도 위상정렬 문제임..
	std::cin.tie(nullptr);
	int N, M;
	std::cin >> N >> M;
	std::vector<std::vector<int>> Pre(N+1);
	std::vector<int> Indegree(N + 1, 0);
	for (int i = 0; i < M; ++i) {
		int A, B;
		std::cin >> A >> B;
		Pre[A].emplace_back(B);
		++Indegree[B];
	}

	// 3.2만 input
	// 1'600'000'000
	// 0'900'000'000
	// 대략 9억..
	// 2초이므로 약 2~4억 연산 가능하니까
	// nlogn으로 끊어야함

	// 위상정렬 어떻게 했는지 기억안남,
	// 뭔가 0개인 것들을 먼저 넣고 해서 하는방식이었던것같은데...
	std::vector<int> Answer;
	Answer.reserve(N);
	
	std::priority_queue<int, std::vector<int>, std::greater<int>> PQ;
	for (int i = 1; i <= N; ++i) {
		if (Indegree[i] == 0) {
			PQ.emplace(i);
		}
		
	}
	while (!PQ.empty()) {
		int Solved = PQ.top(); PQ.pop();
		Answer.emplace_back(Solved);
		for (int Next : Pre[Solved]) {
			--Indegree[Next];
			if (Indegree[Next] == 0) {
				PQ.emplace(Next);
			}
		}
	}

	for (int Ans : Answer) {
		std::cout << Ans << " ";
	}
}