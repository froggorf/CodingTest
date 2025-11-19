#include <iostream>
#include <vector>

int main() {
	int N;
	std::cin >> N;
	
	// DP 인걸 봐버렸으니 일단..
	// DP[i] -> 돌 개수가 i 개일때 현재 차례 사람이 이길 수 있는지
	std::vector<int> DP(N+1);
	DP[1] = 1;
	DP[2] = 0;
	DP[3] = 1;
	DP[4] = 0; // 1개 가져가던 3개 가져가던 짐
	for (int i = 5; i < N + 1; ++i) {
		// 돌이 i개일때
		// i-1 / i-2 / i-3 에 자기가 이길 가능성이 있다면 그 개수만큼 빼가면 되므로
		DP[i] = DP[i - 1] == 0 || DP[i - 3] == 0;
	}

	if (DP[N] == 1) {
		std::cout << "SK";
	}
	else {
		std::cout << "CY";
	}
}
