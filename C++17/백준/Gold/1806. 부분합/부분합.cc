#include <iostream>
#include <vector>
#include <queue>
#include <stack>
int main() {
	// 실수로 봐버렸지만,
	// 연속된 수들의 부분합중에 S이상이 되는것중 짧은것
	// 그러면 S를 넘기는순간 ++Left,
	// S가 안되면 ++Right 를 하면 되지않을까?
	// 10000을 10만번 더해도 int 최대는 안넘음
	int N,S;
	std::cin >> N >> S;
	std::vector<int> Nums(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> Nums[i];
	}

	auto Left = Nums.begin();
	auto Right = Left;
	int Value = *Left;
	int ShortestLength = INT32_MAX;
	while (true) {
		// S보다 크면
		if (Value >= S) {
			// 기록을 남긴다음에
			ShortestLength = std::min(static_cast<int>(std::distance(Left, Right)) + 1, ShortestLength);
			// 왼쪽 한칸 옮기기
			Value -= *Left;
			++Left;
		}
		// S보다 작으면
		else {
			++Right;
			if (Right == Nums.end()) {
				break;
			}
			Value += *Right;
		}
	}
	if (ShortestLength == INT32_MAX) {
		std::cout << 0;
		return 0;
	}
	std::cout << ShortestLength;


}