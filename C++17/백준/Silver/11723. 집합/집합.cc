#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
int main() {
	std::vector<int> S;
	int Count = 0;
	std::cin.tie(nullptr);
	std::ios::sync_with_stdio(false);
	std::cin >> Count;
	std::vector<int> InCount(21, 0);

	while (Count--) {
		std::string Func;
		std::cin >> Func;
		if (Func == "add") {
			int Val;
			std::cin >> Val;
			if (InCount[Val]) {
				continue;
			}
			S.emplace_back(Val);
			InCount[Val] = 1;
		}
		else if (Func == "remove") {
			int Val;
			std::cin >> Val;
			S.erase(std::remove(S.begin(), S.end(), Val), S.end());
			InCount[Val] = 0;
		}
		else if (Func == "check") {
			int Val = 0;
			std::cin >> Val;
			bool bIn = InCount[Val] > 0;
			
			int Out = bIn ? 1 : 0;
			std::cout << Out << "\n";
		}
		else if (Func == "toggle") {
			int Val = 0;
			std::cin >> Val;
			bool bIn = InCount[Val] > 0;
			if (bIn) {
				S.erase(std::remove(S.begin(), S.end(), Val), S.end());
				InCount[Val] = 0;
			}
			else {
				S.emplace_back(Val);
				InCount[Val] = 1;
			}
		}
		else if (Func == "all") {
			S.clear();
			S.resize(20);
			for (int i = 0; i < 20; ++i) {
				S[i] = i + 1;
				InCount[i + 1] = 1;
			}
		}
		else if (Func == "empty") {
			S.clear();
			for (int i = 1; i < 21; ++i) {
				InCount[i] = 0;
			}
		}

	}
}