#include <iostream>
#include <vector>
#include <cmath>
int r, c;
bool bFindAnswer = false;
int AccessTime = -1;
void Solve(	int XStart, int YStart,
	int Size) {
	if (bFindAnswer) {
		return;
	}

	// 만약 Size가 1이면 읽고
	if (Size == 1) {
		++AccessTime;
		if (XStart == r && YStart == c) {
			std::cout << AccessTime;
			bFindAnswer = true;
		}
		return;
	}

	//만약 지금 보는곳이 r행 c열을 포함하지 않는다면 그냥 다 한번에 더해버리는 방법도 있지않을까??
	if (r < XStart || r > XStart + Size ||
		c < YStart || c > YStart + Size) {
		AccessTime += Size * Size;
		return;
	}

	// 아니면 Z 모양으로 분할한다
	int NewSize = Size >> 1;
	Solve(XStart, YStart, NewSize);					// 제 2 사분면
	Solve(XStart, YStart+NewSize, NewSize);			// 제 1 사분면
	Solve(XStart+NewSize, YStart, NewSize);			// 제 3 사분면
	Solve(XStart+NewSize, YStart+NewSize, NewSize);	// 제 4 사분면


}

int main() {
	int N;
	std::cin >> N >> r >> c;
	int Size = std::pow(2, N);
	Solve( 0, 0, Size);


}