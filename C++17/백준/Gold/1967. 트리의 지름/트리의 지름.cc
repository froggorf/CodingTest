#include <iostream>
#include <vector>
#include <queue>
int N;
std::vector<std::vector<std::pair<int, int>>> Graph;
int FindFarNode(int StartNode) {
	std::queue<std::pair<int, int>> Q;
	Q.emplace(StartNode, 0);
	int FarNode = StartNode;
	int FarDistance = 0;
	std::vector<bool> Visited(N + 1, false);
	while (!Q.empty()) {
		std::pair<int, int> Cur = Q.front(); Q.pop();
		if (Visited[Cur.first]) {
			continue;
		}
		Visited[Cur.first] = true;
		if (FarDistance < Cur.second) {
			FarDistance = Cur.second;
			FarNode = Cur.first;
		}

		for (const std::pair<int, int>& NodeData : Graph[Cur.first]) {
			if (Visited[NodeData.first]) {
				continue;
			}
			Q.emplace(NodeData.first, Cur.second + NodeData.second);
		}
	}

	return FarNode;
}
int main() {
	// 가중치가 1이 아닌 그래프에서 최장길이를 구하는거니까
	// 플루이드 워셜을 쓰면 됨
	// 내가 기억하기로 이건 DP를 활용하는것이었는데..
	
	// 아니다 최단경로를 구해서 그 최단경로가 가장 긴것을 구하는것 같음

	std::cin.tie(nullptr);
	std::cin >> N;
	Graph = std::vector<std::vector<std::pair<int, int>>>(N + 1);
	for (int i = 0; i < N-1; ++i) {
		int Start;
		int End;
		int Weight;
		std::cin >> Start >> End >> Weight;
		Graph[Start].emplace_back(End, Weight);
		Graph[End].emplace_back(Start, Weight);
	}

	int Answer = 0;
	// 노드의 개수가 10000개,
	// 100'000'000 1억.. 시간제한은 2초,,
	// nlogn으로 끊는게 맞음,

	// 노드 하나 잡아서
	int FirstFarNode = FindFarNode(1);
	int AnotherFarNode = FindFarNode(FirstFarNode);
	
	std::queue<std::pair<int, int>> Q;
	Q.emplace(FirstFarNode, 0);
	std::vector<bool> Visited(N + 1, false);
	while (!Q.empty()) {
		std::pair<int, int> Cur = Q.front(); Q.pop();
		
		if (Cur.first == AnotherFarNode) {
			std::cout << Cur.second;
			return 0;
		}

		if (Visited[Cur.first]) {
			continue;
		}
		Visited[Cur.first] = true;


		for (const std::pair<int, int>& NextNode : Graph[Cur.first]) {
			if (Visited[NextNode.first]) {
				continue;
			}
			Q.emplace(NextNode.first, Cur.second + NextNode.second);
		}
	}
	
}