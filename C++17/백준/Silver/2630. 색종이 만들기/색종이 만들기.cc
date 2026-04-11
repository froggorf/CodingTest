#include <iostream>
#include <vector>

int WhiteCount = 0;
int BlueCount = 0;

void Solve(const std::vector<std::vector<int>>& Paper, int XStart, int XEnd, int YStart, int YEnd) {
	int InitColor = Paper[XStart][YStart];
	bool bAllSameColor = true;
	for (int X = XStart; X <= XEnd && bAllSameColor; ++X) {
		for (int Y = YStart; Y <= YEnd; ++Y) {
			if (InitColor != Paper[X][Y]) {
				bAllSameColor = false;
				break;
			}
		}
	}

	if (bAllSameColor) {
		InitColor == 1 ? ++BlueCount : ++WhiteCount;
	}
	// 4개로 분할한다
	else {
		int XMid = XStart + (XEnd - XStart) / 2;
		int YMid = YStart + (YEnd - YStart) / 2;
		Solve(Paper, XStart, XMid, YMid+1, YEnd); // 제 1사분면
		Solve(Paper, XStart, XMid, YStart, YMid); // 제 2사분면
		Solve(Paper, XMid+1, XEnd, YStart, YMid); // 제 3사분면
		Solve(Paper, XMid+1, XEnd, YMid+1, YEnd); // 제 4사분면
	}

}

int main() {
	std::cin.tie(nullptr);
	std::ios::sync_with_stdio(false);

	int N;
	std::cin >> N;

	std::vector<std::vector<int>> Paper(N, std::vector<int>(N));
	for (int X = 0; X < N; ++X) {
		for (int Y = 0; Y < N; ++Y) {
			std::cin >> Paper[X][Y];
		}
	}

	Solve(Paper, 0, N - 1, 0, N - 1);

	std::cout << WhiteCount << "\n" << BlueCount;

}