#include <iostream>
#include <vector>
#include <algorithm>
int main() {
	// 1000이면 사실상 N^2 써도 되긴함
	int N;
	std::cin >> N;
	std::vector<int> V(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> V[i];
	}
	std::sort(V.begin(), V.end());

	for (int i = 0; i < N; ++i) {
		std::cout << V[i] << "\n";
	}

}