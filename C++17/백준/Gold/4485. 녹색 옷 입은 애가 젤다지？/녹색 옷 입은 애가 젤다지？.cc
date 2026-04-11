#include <iostream>
#include <vector>
#include <queue>

int main() {
	std::cin.tie(nullptr);
	std::ios::sync_with_stdio(false);

	int ProcedualCount = 0;
	while (true) {
		++ProcedualCount;
		int N;
		std::cin >> N;
		if (N == 0) {
			break;
		}

		std::vector<std::vector<int>> Board(N, std::vector<int>(N));
		for (int X = 0; X < N; ++X) {
			for (int Y = 0; Y < N; ++Y) {
				std::cin >> Board[X][Y];
			}
		}

		struct Point {
			int X, Y;
			int CurLoseValue;
			
			bool operator>(const Point& Other) const {
				return CurLoseValue > Other.CurLoseValue;
			}
		};
		std::priority_queue<Point, std::vector<Point>, std::greater<Point>> PQ;
		PQ.emplace(Point{ 0,0,Board[0][0]});
		std::vector<std::vector<int>> Dist(N, std::vector<int>(N, INT32_MAX));
		Dist[0][0] = Board[0][0];
		while (!PQ.empty()) {
			int CurValue = PQ.top().CurLoseValue;
			int CurX = PQ.top().X;
			int CurY = PQ.top().Y;
			PQ.pop();

			// 이미 더 최적의 길이 있음
			if (CurValue > Dist[CurX][CurY]) {
				continue;
			}

			// 최적의 길을 찾음
			if (CurX == N - 1 && CurY == N - 1) {
				break;
			}

			int dx[4] = {0,0,-1,1};
			int dy[4] = {1,-1,0,0};
			for (int Dir = 0; Dir < 4; ++Dir) {
				int NextX = CurX + dx[Dir];
				int NextY = CurY + dy[Dir];
				if (NextX < 0 || NextX >= N || NextY < 0 || NextY >= N) {
					continue;
				}

				int NewValue = CurValue + Board[NextX][NextY];
				if (NewValue < Dist[NextX][NextY]) {
					Dist[NextX][NextY] = NewValue;
					PQ.emplace(Point{ NextX,NextY,NewValue });
				}
			}
		}

		//std::cout << std::format("Problem {}: {}\n", ProcedualCount, Dist[N-1][N-1]);
		std::cout << "Problem " << ProcedualCount << ": " << Dist[N - 1][N - 1] << "\n";
	}


}