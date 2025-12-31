#include <iostream>
#include <vector>


int main() {
	// N짜리 수열,
	// 연속된 수의 부분합, 그 합이 S 이상인것중 가장 짧은 길이
	// 투포인터 쓰면 되지않을까,
	std::cin.tie(nullptr);
	std::ios::sync_with_stdio(false);

	long long N, S;
	std::cin >> N >> S;
	std::vector<int> Nums(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> Nums[i];
	}

	int CurrentSum = 0;
	auto Left = Nums.begin();
	auto Right = Nums.begin();
	CurrentSum = *Left;
	int Answer = INT32_MAX;
	while (true) {

		if (CurrentSum >= S) {
			int CurrentDistance = std::distance(Left, Right) + 1;
			if (CurrentDistance < Answer) {
				Answer = CurrentDistance;
			}

			if (Left < Right) {
				// 이제 한칸씩 왼쪽꺼를 뒤로
				CurrentSum -= *Left;
				++Left;
			}
			else {
				if (Right + 1 == Nums.end()) {
					break;
				}
				else {
					++Right;
				}
				
			}
		}
		else {
			// S를 못넘겼는데 Right가 끝원소를 가리키면 while 나가면 됨
			if (Right + 1 == Nums.end()) {
				break;
			}
			else {
				++Right;
				CurrentSum += *Right;
			}
		}
		
	}

	if (Answer == INT32_MAX) {
		std::cout << 0;
		return 0;
	}
	
	std::cout << Answer;
}