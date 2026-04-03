#include <iostream>
#include <vector>

int main() {
	// n이 100만이기 때문에 nlogn으로 끊어야함
	// 그렇다면...
	std::cin.tie(nullptr);
	std::ios::sync_with_stdio(false);

	int N;
	std::cin >> N;
	std::vector<int> Nums(N);
	for (int i = 0; i < N; ++i) {
		std::cin>>Nums[i];
	}

	std::vector<int> Answers;

	for (int i = 0; i < N; ++i) {
		// 일단 하나씩 돌면서

		// 맨 뒤의 수보다 작은 수라면 적절한 위치에 대체해줘야함
		
		if (!Answers.empty() && Answers.back() >= Nums[i]) {
			if (Answers.back() == Nums[i]) {
				continue;
			}
			auto Iter = std::lower_bound(Answers.begin(), Answers.end(), Nums[i]);
			*Iter = Nums[i];
			continue;
		}

		// 아니면 걍 추가하면 됨
		Answers.emplace_back(Nums[i]);
	}

	std::cout << Answers.size();

}