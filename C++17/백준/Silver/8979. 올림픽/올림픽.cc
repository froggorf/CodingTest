#include <iostream>
#include <vector>
#include <queue>
struct Score {
	int Index;
	int Gold;
	int Silver;
	int Couper;

	bool operator<(const Score& Other) const {
		if (Gold == Other.Gold) {
			if (Silver == Other.Silver) {
				return Couper < Other.Couper;
			}
			return Silver < Other.Silver;
		}
		return Gold < Other.Gold;
	}

	bool operator==(const Score& Other) const {
		return Gold == Other.Gold && Silver == Other.Silver && Couper == Other.Couper;
	}
};
struct Pred {
	bool operator()(const Score& A, const Score& B) {
		return A < B;
	}
};
int main() {
	// 금 더 많은
	// 금 같으면 은베달
	// 금은 같으면 동
	std::cin.tie(nullptr);
	int N, K;
	std::cin >> N >> K;

	std::priority_queue<Score, std::vector<Score>, Pred> PQ;
	for (int i = 0; i < N; ++i) {
		int Index, Gold, Silver, Couper;
		std::cin >> Index >> Gold >> Silver >> Couper;
		PQ.emplace(Score{ Index, Gold, Silver, Couper });
	}
	Score Last;
	int LastGrade = 1;
	int CurrentGrade = 0;
	while (!PQ.empty()) {
		++CurrentGrade;
		Score Current = PQ.top(); PQ.pop();
		// 이전의 것과 다르다면
		if (!(Last == Current)) {
			LastGrade = CurrentGrade;
		}

		if (Current.Index == K) {
			std::cout << LastGrade;
		}
		Last = Current;
	}
}