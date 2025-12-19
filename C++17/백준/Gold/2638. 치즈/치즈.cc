#include <iostream>
#include <vector>
#include <queue>
// 치즈 하나마다 바깥닿는지 보는게 아니라
// 바깥부분부터 해서 다른애들 닿는거 2개를 보면 될거같음

int X, Y;
int main() {
	std::cin >> X >> Y;

	int CurrentCheeseCount = 0;
	std::vector<std::vector<int>> Board(X, std::vector<int>(Y));
	for (int x = 0; x < X; ++x) {
		for (int y = 0; y < Y; ++y) {
			int Val;
			std::cin >> Val;
			Board[x][y] = Val;
			if (Val == 1) {
				CurrentCheeseCount += 1;
			}
		}
	}

	int Time = 0;
	while (true) {
		if (CurrentCheeseCount <= 0) {
			break;
		}
		++Time;

		std::queue<std::pair<int, int>> Q;
		for (int i = 0; i < X; ++i) {
			Q.emplace(i, 0);
		}
		for (int i = 0; i < Y; ++i) {
			Q.emplace(0, i);
		}

		std::vector<std::vector<int>> MeetAir(X, std::vector<int>(Y, 0));
		std::vector<std::vector<bool>> Visited(X, std::vector<bool>(Y, false));
		while (!Q.empty()) {
			std::pair<int, int> Cur = Q.front(); Q.pop();
			if (Visited[Cur.first][Cur.second]) {
				continue;
			}
			Visited[Cur.first][Cur.second] = true;

			static int dx[4] = { 0,0,1,-1 };
			static int dy[4] = { 1,-1,0,0 };
			for (int dir = 0; dir < 4; ++dir) {
				int NextX = Cur.first + dx[dir];
				int NextY = Cur.second + dy[dir];
				if (NextX < 0 || NextX >= X || NextY < 0 || NextY >= Y) continue;
				if (Visited[NextX][NextY]) continue;

				// 다음 칸이 공기면
				if (Board[NextX][NextY] == 0) {
					Q.emplace(NextX, NextY);
				}
				// 다음 칸이 치즈면
				else {
					++MeetAir[NextX][NextY];
				}
				
			}
		}
		
		for (int x = 0; x < X; ++x) {
			for (int y = 0; y < Y; ++y) {
				if (MeetAir[x][y] >= 2) {
					Board[x][y] = 0;
					--CurrentCheeseCount;
				}
			}
		}
	}

	std::cout << Time;
}