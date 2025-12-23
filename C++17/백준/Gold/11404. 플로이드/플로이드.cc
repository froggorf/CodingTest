#include <iostream>
#include <vector>
#include <queue>
int main() {
	// 비용의 최소
	// 즉 이건 그.... 다른거 썼어야했나,,,
	int N, M;
	std::cin >> N >> M;
	std::vector<std::vector<int>> DP(N, std::vector<int>(N, INT32_MAX));

	// i에서 i로 가는 비용은 0원
	for (int i = 0; i < N; ++i) {
		DP[i][i] = 0;
	}

	for (int i = 0; i < M; ++i) {
		int Start, End, Weight;
		std::cin >> Start >> End >> Weight;
		--Start; --End;
		DP[Start][End] = std::min(DP[Start][End], Weight);
	}

	for (int k = 0; k < N; ++k) {
	for (int x = 0; x < N; ++x) {
		for (int y = 0; y < N; ++y) {
			
				if (DP[x][k] == INT32_MAX || DP[k][y] == INT32_MAX) {
					continue;
				}

				DP[x][y] = std::min(DP[x][y], DP[x][k] + DP[k][y]);
			}
		}
	}

	for (int x = 0; x < N; ++x) {
		for (int y = 0; y < N; ++y) {
			if (DP[x][y] == INT32_MAX) {
				std::cout << "0 ";
			}
			else {
				std::cout << DP[x][y]<<" ";
			}
		}
		std::cout << "\n";
	}
	

	
}