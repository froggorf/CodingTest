#include <iostream>
#include <vector>

long long Build(const std::vector<long long>& OriginValue,
	std::vector<long long>& SegmentTree,
	int Left, int Right, int TargetIndex) {

	int Mid = (Left + Right) / 2;
	
	if (Left == Right) {
		return SegmentTree[TargetIndex] = OriginValue[Left];
	}

	long long LeftSum = Build(OriginValue, SegmentTree, Left, Mid, 2 * TargetIndex);
	long long RightSum = Build(OriginValue, SegmentTree, Mid + 1, Right, 2 * TargetIndex + 1);
	return SegmentTree[TargetIndex] = LeftSum + RightSum;
}

long long Update(std::vector<long long>& SegmentTree, int SegmentIndex, int Left, int Right, int TargetIndex, long long NewValue) {
	// 목적지 리프노드까지 잘 도착한것
	if (Left == Right) {
		long long OriginValue = SegmentTree[SegmentIndex];
		SegmentTree[SegmentIndex] = NewValue;
		return NewValue - OriginValue;
	}

	int Mid = (Left + Right) / 2;
	long long Diff{ 0 };
	if (Left <= TargetIndex && TargetIndex <= Mid) {
		Diff = Update(SegmentTree, 2 * SegmentIndex, Left, Mid, TargetIndex, NewValue);
	}
	else {
		Diff = Update(SegmentTree, 2 * SegmentIndex + 1, Mid + 1, Right, TargetIndex, NewValue);
	}

	SegmentTree[SegmentIndex] += Diff;

	return Diff;
}

long long Query(const std::vector<long long>& SegmentTree, int SegmentIndex, int Left, int Right, int QueryLeft, int QueryRight) {
	// 쿼리의 가운데 부분이면 그부분만 출력
	if (QueryLeft <= Left && Right <= QueryRight) {
		return SegmentTree[SegmentIndex];
	}
	if (QueryRight < Left
		|| Right < QueryLeft) {
		return 0;
	}

	int Mid = (Left + Right) / 2;
	long long LeftSum = Query(SegmentTree, 2 * SegmentIndex, Left, Mid, QueryLeft, QueryRight);
	long long RightSum = Query(SegmentTree, 2 * SegmentIndex + 1, Mid + 1, Right, QueryLeft, QueryRight);
	return LeftSum + RightSum;

}

int main() {
	std::cin.tie(nullptr);
	std::ios::sync_with_stdio(false);
	int N, M, K;
	std::cin >> N >> M >> K;
	std::vector<long long> OriginValue(N);	
	for (int i = 0; i < N; ++i) {
		std::cin >> OriginValue[i];
	}
	std::vector<long long> SegmentTree(4 * N);	//총 500만개 == 2000만바이트 == 20MB, OK
	
	Build(OriginValue, SegmentTree, 0, N-1, 1);
	
	for (int i = 0; i < M + K; ++i) {
		long long Command, First, Second;
		std::cin >> Command >> First >> Second;
		First -= 1;
		// Update
		if (Command == 1) {
			Update(SegmentTree, 1, 0, N - 1, First, Second);
		}
		// Query
		if (Command == 2) {
			int RangeEnd = (int)Second - 1;
			long long Answer = Query(SegmentTree, 1, 0, N - 1, First, RangeEnd);
			std::cout << Answer << "\n";
		}
	}



}