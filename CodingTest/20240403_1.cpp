#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;

void Solution()
{
	// N개의 랜선을 만드는데,
	// K개 보유하고 있으며 각 길이가 있으므로,
	// *평균적으로 K개의 랜선 을 다 더한 길이에서 11을 나눈 길이보다 각 길이는 짧을 것
	// 따라서, 해당 길이부터 전부다 계산하며, 모든 선에 대해서 해당 길이로 /연산한 값을 모두 더했을 때 N이 안되면
	// %를 통해 각 길이별로 남은 길이를 체크하고, 해당 길이를 /한 결과에 맞게 분배한 만큼 길이를 적게 하여 1개씩 더해나갈 수 있게 탐색하며 자르면 적절할 것 으로 확인.

	//값 받기
	int LineCount{};
	int WantedLineCount{};
	vector<int> CurrentLineLengths;

	std::cin >> LineCount;
	std::cin >> WantedLineCount;
	for(int i=0; i<LineCount; ++i)
	{
		int LineLength{};
		std::cin >> LineLength;
		CurrentLineLengths.push_back(LineLength);
	}
	//Value == WantedLineLength
	int WantedLineLength = std::accumulate(CurrentLineLengths.begin(), CurrentLineLengths.end(), 0) / WantedLineCount;

	
	while(true)
	{
		long long currentLineCount = 0;
		//for(const int& CurrentLineLength : CurrentLineLengths)
		//int LessRemainLineValue = numeric_limits<int>::max();
		int GreaterRemainLineValue = 0;
		int GreaterRemainLineIndex = -1;

		//std::cout << "_+++++++++++++++" << std::endl;
		for (int i=0; i<CurrentLineLengths.size(); ++i)	//해당 인덱스에 대해 알아야하므로 
		{
			currentLineCount += (CurrentLineLengths[i] / WantedLineLength);
			if(CurrentLineLengths[i] % WantedLineLength > GreaterRemainLineValue)
			{
				GreaterRemainLineValue = CurrentLineLengths[i] % WantedLineLength;
				GreaterRemainLineIndex = i;
			}

			//std::cout << CurrentLineLengths[i] % WantedLineLength << " " << GreaterRemainLineValue << std::endl;
		}
		//std::cout << "_+++++++++++++++" <<currentLineCount<<" " <<WantedLineCount <<" "<< WantedLineLength<< std::endl;
		// 현재 라인 갯수 변수가 목표 갯수보다 같거나 높아지는 순간이 정답
		if (currentLineCount >= WantedLineCount)
		{
			std::cout << WantedLineLength;
			return;
		}
		else    // 그보다 낮다면, % 값이 가장 낮았던 길이의 선에 대하여 수가 1만큼 늘어날 수 있도록 자를 선의 길이를 조정한다.
		{
			/*
			 (현재 선 길이)100/(원하는 선길이)3이 (나오는 선 갯수)33인데, 34의 값을 원하므로, 100/34 = 2.9 즉 2로 나눠야 함
			 100/12 가 8인데, 9의 값을 원하므로, 100/9 = 11.111 즉 11로 나눠야함.
			 */
			int currentGetLineCount = CurrentLineLengths[GreaterRemainLineIndex] / WantedLineLength;
			currentGetLineCount += 1;
			WantedLineLength = CurrentLineLengths[GreaterRemainLineIndex] / currentGetLineCount;
			
		}
		
	}
}


int main()
{
	Solution();
	return 0;
}