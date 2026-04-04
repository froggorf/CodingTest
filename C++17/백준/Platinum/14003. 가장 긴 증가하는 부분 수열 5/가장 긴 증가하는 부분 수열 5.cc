#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);
	int N;
	std::cin >> N;
	std::vector<int> Nums(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> Nums[i];
	}

	std::vector<int> Indices;
	std::vector<int> Answers;

	for (int i = 0; i < N; ++i) {
		// 만약 맨뒤 숫자가 지금 수 보다 크면 추가
		if (!Answers.empty() && Answers.back() <= Nums[i]) {
			if (Answers.back() == Nums[i]) {
				Indices.emplace_back(-1);
				continue;
			}
			Indices.emplace_back(static_cast<int>(Answers.size()));
			Answers.emplace_back(Nums[i]);
			continue;
		}

		if (Answers.empty()) {
			Indices.emplace_back(0);
			Answers.emplace_back(Nums[i]);
			continue;
		}
		auto Iter = std::lower_bound(Answers.begin(), Answers.end(), Nums[i]);
		*Iter = Nums[i];
		int Val = std::distance(Answers.begin(), Iter);
		Indices.emplace_back(Val);
	}

	std::cout << Answers.size() << "\n";

	std::stack<int> Values;
	

	int Val = Answers.size() - 1;
	for (int i = N - 1; i >= 0; --i) {
		if (Val == Indices[i]) {
			Values.emplace(Nums[i]);
			--Val;
			if (Val < 0) {
				break;
			}
		}
	}

	while (!Values.empty()) {
		std::cout << Values.top() << " ";
		Values.pop();
	}
}