#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;

void Solution()
{
	// N���� ������ ����µ�,
	// K�� �����ϰ� ������ �� ���̰� �����Ƿ�,
	// *��������� K���� ���� �� �� ���� ���̿��� 11�� ���� ���̺��� �� ���̴� ª�� ��
	// ����, �ش� ���̺��� ���δ� ����ϸ�, ��� ���� ���ؼ� �ش� ���̷� /������ ���� ��� ������ �� N�� �ȵǸ�
	// %�� ���� �� ���̺��� ���� ���̸� üũ�ϰ�, �ش� ���̸� /�� ����� �°� �й��� ��ŭ ���̸� ���� �Ͽ� 1���� ���س��� �� �ְ� Ž���ϸ� �ڸ��� ������ �� ���� Ȯ��.

	//�� �ޱ�
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
		for (int i=0; i<CurrentLineLengths.size(); ++i)	//�ش� �ε����� ���� �˾ƾ��ϹǷ� 
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
		// ���� ���� ���� ������ ��ǥ �������� ���ų� �������� ������ ����
		if (currentLineCount >= WantedLineCount)
		{
			std::cout << WantedLineLength;
			return;
		}
		else    // �׺��� ���ٸ�, % ���� ���� ���Ҵ� ������ ���� ���Ͽ� ���� 1��ŭ �þ �� �ֵ��� �ڸ� ���� ���̸� �����Ѵ�.
		{
			/*
			 (���� �� ����)100/(���ϴ� ������)3�� (������ �� ����)33�ε�, 34�� ���� ���ϹǷ�, 100/34 = 2.9 �� 2�� ������ ��
			 100/12 �� 8�ε�, 9�� ���� ���ϹǷ�, 100/9 = 11.111 �� 11�� ��������.
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