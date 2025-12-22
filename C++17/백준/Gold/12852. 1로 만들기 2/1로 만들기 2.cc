#include <iostream>
#include <vector>
#include <cassert>
int main() {
	// 지금 당장 생각나는건,
	// 연산량을 기준으로 PQ로 해서 하는 방법이 있을것같고
	// 아니면 DP를 쓰는 방법이 있을거같음
	
	// 그리고 N에서 1로 만드는거랑
	// 1에서 모든 수를 다 구한다음에 하는거중에 무슨 방법이 더 좋은지를 생각해봐야함

	// 생각해보니까 1에서 만들면서 가는게 더 가벼울것같다는 생각이 듦
	// 근데 과정이 있어야함...
	// 
	std::vector<int> DP(500'0000, INT32_MAX);
	DP[1] = 0;
	for (int i = 1; i <= 100'0000; ++i) {
		DP[i * 2] = std::min(DP[i] + 1, DP[i * 2]);
		DP[i * 3] = std::min(DP[i] + 1, DP[i * 3]);
		DP[i + 1] = std::min(DP[i] + 1, DP[i + 1]);
	}

	int N;
	std::cin >> N;

	std::cout << DP[N] << "\n";
	while (true) {
		std::cout << N << " ";
		if (N == 1) {
			break;
		}

		int LessCount = INT32_MAX;
		int Target = -1;
		if (N % 3 == 0) {
			if (DP[N / 3] < LessCount) {
				LessCount = DP[N / 3];
				Target = 3;
			}
		}

		if (N % 2 == 0) {
			if (DP[N / 2] < LessCount) {
				LessCount = DP[N / 2];
				Target = 2;
			}
		}

		if (DP[N - 1] < LessCount) {
			Target = 1;
		}

		if (Target == 1) {
			N -= 1;
		}
		else if (Target == 2) {
			N /= 2;
		}
		else if (Target == 3) {
			N /= 3;
		}
		else {
			assert(false);
		}
	}

	return 0;
}