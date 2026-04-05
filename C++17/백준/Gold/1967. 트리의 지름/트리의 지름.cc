#include <iostream>
#include <vector>
#include <queue>
#include <stack>
int N;
std::pair<int,int> FindBestFarNode(
	const std::vector<std::vector<std::pair<int, int>>>& Graph,
	int StartNode) {
	std::pair<int, int> ReturnValue{ StartNode,0 };
	
	std::stack<std::pair<int, int>> S;
	std::vector<bool> Visited(N + 1, false);
	S.emplace(StartNode, 0);
	Visited[StartNode] = true;
	while (!S.empty()) {
		std::pair<int, int> Top = S.top(); S.pop();
		for (const std::pair<int, int>& NextNodes : Graph[Top.first]) {
			// 이미 방문했던 곳이면 패스
			if (Visited[NextNodes.first]) {
				continue;
			}
			// 아니면 추가한다
			S.emplace(NextNodes.first, Top.second + NextNodes.second);
			Visited[NextNodes.first] = true;
		}
		if (ReturnValue.second < Top.second) {
			ReturnValue = Top;
		}
	}

	return ReturnValue;
}

int main() {
	// 이 문제 한 노드 잡고 제일 먼거 구한다음에
	// 걔로부터 가장 먼걸 구해서 그 둘사이의 길이를 구하면 됐던거같음
	// 왜냐면 첫번쨰 가장먼게 가장 첫 먼 지름한쪽이고
	// 그다음 먼건 반대쪽 지름이니까

	std::cin.tie(nullptr);
	std::ios::sync_with_stdio(false);
	std::cin >> N;
	std::vector<std::vector<std::pair<int, int>>> Graph(N+1);
	for (int i = 0; i < N-1; ++i) {
		int Start, End, Value;
		std::cin >> Start >> End >> Value;
		Graph[Start].emplace_back(End, Value);
		Graph[End].emplace_back(Start, Value);
	}

	// 일단 점 하나 잡고, 그곳에서 가장 먼걸 구한다
	std::pair<int, int> FarFromFirstNode = FindBestFarNode(Graph, 1);
	std::pair<int, int> Answer = FindBestFarNode(Graph, FarFromFirstNode.first);

	std::cout << Answer.second;




}