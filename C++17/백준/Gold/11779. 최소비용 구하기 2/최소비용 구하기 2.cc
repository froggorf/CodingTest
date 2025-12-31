#include <iostream>
#include <vector>
#include <queue>
#include <stack>

struct Data {
	int first;		// 여태까지 Weight
	int second;		// 새로운 도착지
	int Last;		// 이전 도착지
};

struct DataComp {
	bool operator()(const Data& A, const Data& B) {
		return A.first > B.first;
	}
};

int main() {
	std::cin.tie(nullptr);
	std::ios::sync_with_stdio(false);
	// n = 1000
	// m = 100'000
	// n^2 까지도 괜찮음,
	// mlogm

	// 모든 쌍을 구하는게 아니라
	// A 에서 B로 가는 것을 구하는거니까..
	// PQ 만으로도 가능할것같음
	// 시작점을 0, 점점 갱신하면서 가고 도착지에 도착했을경우 출력하면 될것같고..
	// 경로가 있어야하는데..
	// 뭔가 트리같은 느낌으로 저장해서 역으로 다가갈수있지않을까? 메모리는 좀 더 쓰겠지만
	int N, M;
	std::cin >> N >> M;
	std::vector<std::vector<std::pair<int,int>>> Graph(N + 1);
	for (int i = 0; i < M; ++i) {
		int A, B, Weight;
		std::cin >> A >> B >> Weight;
		Graph[A].emplace_back(B, Weight);
	}

	int Start, End;
	std::cin >> Start >> End;
	std::vector<int> Dist(N + 1, INT32_MAX);
	//Dist[Start] = 0;
	std::priority_queue<Data, std::vector<Data>, DataComp> PQ;
	PQ.emplace(Data{ 0, Start, -1 });

	// 얘에다가 경로를 저장할거임,
	// Way[i] => i까지 오기 이전에 간 곳
	std::vector<int> Way(N + 1, -1);
	while (!PQ.empty()) {
		Data Cur = PQ.top(); PQ.pop();

		if (Cur.first >= Dist[Cur.second]) {
			continue;
		}

		Dist[Cur.second] = Cur.first;
		Way[Cur.second] = Cur.Last;
		// 도착한거이므로 나가기
		if (Cur.second == End) {
			break;
		}

		// 다음 경로들에 대해서
		for (const std::pair<int,int>& Next : Graph[Cur.second]) {
			int NextWeight = Cur.first + Next.second;
			PQ.emplace(Data{ NextWeight, Next.first, Cur.second });
		}
	}

	std::cout << Dist[End] << "\n";
	// 이제 경로를 추적해야하는데, 
	std::stack<int> S;
	S.emplace(End);
	int Current = End;
	while (true) {
		if (Current == Start) {
			//S.emplace(Start);
			break;
		}

		S.emplace(Way[Current]);
		Current = Way[Current];
	}

	std::cout << S.size() << "\n";
	while (!S.empty()) {
		std::cout << S.top() << " ";
		S.pop();
	}

}