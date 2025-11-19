#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
struct Data {
	int Index;
	int Weight;
	int Height;
};

int main() {
	std::cin.tie(nullptr);
	int N;
	std::cin >> N;
	std::vector<Data> D;
	D.reserve(N);
	for (int i = 0; i < N; ++i) {
		int Weight;
		int Height;
		std::cin >> Weight >> Height;
		D.emplace_back(Data{ i,Weight,Height });
	}
	for (int i = 0; i < N; ++i) {
		int MoreCount = 0;
		for (int j = 0; j < N; ++j) {
			if (i == j) {
				continue;
			}
			if (D[j].Weight > D[i].Weight && D[j].Height > D[i].Height) {
				++MoreCount;
			}
		}
		std::cout << MoreCount + 1 << " ";
	}
}

/*
5
55 185
58 183
88 186
60 175
55 175

*/