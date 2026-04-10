#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int Find(std::vector<int>& Roots, int U) {
	if (Roots[U] == U) {
		return U;
	}

	return Roots[U] = Find(Roots, Roots[U]);
}

bool Union(std::vector<int>& Roots, int U, int V) {
	int URoot = Find(Roots, U);
	int VRoot = Find(Roots, V);

	if (URoot == VRoot) {
		return false;
	}

	if (URoot > VRoot) {
		Roots[URoot] = VRoot;
	}
	else {
		Roots[VRoot] = URoot;
	}
	return true;
}

int main() {
	// N== 10만, 즉 N^2으로 모든 거리를 구해낼 수 없음
	// nlogn 으로 끊어야함
	// 그럼 n개에 대해서 가까운걸 logn번만에  찾아야한단건데
	// 당장 드는 생각은 맵을 사용해서 x,y,z 를 별도로 관리하는것..?
	// x -> {인덱스} 로 관리
	//...를 생각했으나 그럴필요가없음 그냥 x로 정렬, y로 정렬, z로 정렬 해서 하면됨
	struct Planet {
		int Index;
		int X, Y, Z;
	};

	std::cin.tie(nullptr);
	std::ios::sync_with_stdio(false);
	int N;
	std::cin >> N;
	std::vector<Planet> Planets;
	Planets.reserve(N);
//	std::multimap<int, int> Coord_X;
//	std::multimap<int, int> Coord_Y;
//	std::multimap<int, int> Coord_Z;

	for (int i = 0; i < N; ++i) {
		int X, Y, Z;
		std::cin >> X >> Y >> Z;
		Planets.emplace_back(Planet{ i, X, Y, Z });
	//	Coord_X.emplace(X, i);
	//	Coord_Y.emplace(Y, i);
	//	Coord_Z.emplace(Z, i);
	}

	struct Edge {
		int A, B;
		int Value;
	};
	std::vector<Edge> Edges;
	Edges.reserve(3 * N);
	std::sort(Planets.begin(), Planets.end(), [](const Planet& A, const Planet& B) {
		return A.X < B.X;
		});

	for (int i = 0; i < N - 1; ++i) {
		int Value = Planets[i+1].X -Planets[i].X;
		Edges.emplace_back(Edge{ Planets[i + 1].Index, Planets[i].Index, Value });
	}
	std::sort(Planets.begin(), Planets.end(), [](const Planet& A, const Planet& B) {
		return A.Y < B.Y;
		});

	for (int i = 0; i < N - 1; ++i) {
		int Value = Planets[i + 1].Y - Planets[i].Y;
		Edges.emplace_back(Edge{ Planets[i + 1].Index, Planets[i].Index, Value });
	}
	std::sort(Planets.begin(), Planets.end(), [](const Planet& A, const Planet& B) {
		return A.Z < B.Z;
		});

	for (int i = 0; i < N - 1; ++i) {
		int Value = Planets[i + 1].Z - Planets[i].Z;
		Edges.emplace_back(Edge{ Planets[i + 1].Index, Planets[i].Index, Value });
	}

	std::vector<int> Roots(N);
	for (int i = 0; i < N; ++i) {
		Roots[i] = i;
	}
	
	std::sort(Edges.begin(), Edges.end(), [](const Edge& A, const Edge& B) {
		return A.Value < B.Value;
		});
	long long AnswerCost = 0;
	int EdgeCount = 0;
	for (const Edge& E : Edges) {
		if (Union(Roots, E.A, E.B)) {
			AnswerCost += E.Value;
			if (++EdgeCount == N - 1) {
				break;
			}
		}
	}

	std::cout << AnswerCost;
}