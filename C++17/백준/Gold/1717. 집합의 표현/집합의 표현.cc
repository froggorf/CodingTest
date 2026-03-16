#include "iostream"
#include "vector"

std::vector<int> Root;

int Find(int A) {
	int CurVal = Root[A];
	if (CurVal == A) {
		return A;
	}

	return Root[A] = Find(CurVal);
}

// 0 1 2 1 4 5 7 7

void Union(int A, int B) {
	int ARoot = Find(A);
	int BRoot = Find(B);

	if (ARoot == BRoot) {
		return;
	}

	Root[BRoot] = ARoot;
}

int main() {
	// 문제가 union-find 문제같음,
	// union-find 문제는 루트가 같은지 보는거였으니까..+
	
	std::cin.tie(nullptr);
	std::ios::sync_with_stdio(false);

	int n, m;
	std::cin >> n >> m;

	Root = std::vector<int>(n+1);
	for (int i = 0; i < n+1; ++i) {
		Root[i] = i;
	}

	for (int i = 0; i < m; ++i) {
		int Command, A, B;
		std::cin >> Command >> A >> B;
		if (Command == 0) {
			// 합집합
			Union(A, B);
		}
		else if (Command == 1) {
			// 포함
			int ARoot = Find(A);
			int BRoot = Find(B);
			if (ARoot == BRoot) {
				std::cout << "yes" << "\n";
			}
			else {
				std::cout << "no" << "\n";
			}
		}
	}
}