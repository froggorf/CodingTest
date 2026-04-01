#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::cin.tie(nullptr);
	std::ios::sync_with_stdio(false);

	int N;
	std::cin >> N;
	std::vector<int> Nums(N, 0);
	for (int i = 0; i < N; ++i) {
		std::cin >> Nums[i];
	}

	std::vector<int> Answers(N,-1);
	// 앞에 숫자들을 다 보면서 나보다 작으면 std::max(나, 이전+1)
	
	for (int i = 0; i < N; ++i) 
	{
		Answers[i] = 1;
		for (int j = 0; j < i; ++j) {
			if (Nums[i] > Nums[j]) {
				Answers[i] = std::max(Answers[i], Answers[j] + 1);
			}

		}

	} 

	std::cout << *std::max_element(Answers.begin(), Answers.end());
}