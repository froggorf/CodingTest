#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 모든 숫자 입력에 대해서 +인 경우와 - 인경우 두가지로 갈래가 나눠지는 이진 트리 구조로 진행을 하여
// 맨 아래 노드의 값이 타겟인 경우의 수를 더하면 될 것 같다.

int Value = 0;

void CalcValue(std::vector<int>& numbers, int currentIndex, int NowValue, int TargetValue)
{
    if (currentIndex >= numbers.size()) {
        if (NowValue == TargetValue)
        {
            Value += 1;
        }
        return;
    }

    CalcValue(numbers, currentIndex + 1, NowValue + numbers[currentIndex], TargetValue);
    CalcValue(numbers, currentIndex + 1, NowValue - numbers[currentIndex], TargetValue);
}

int solution(vector<int> numbers, int target) {
    

    // 트리에 numbers 구조를 다 더할 순 없으니,
    // 순환 구조 개념으로 접근을 해본다.
    CalcValue(numbers, 0, 0, target);

    int answer = Value;
    //std::cout << answer << std::endl;
    return answer;
}

void main()
{
    solution(std::vector<int>{1, 1, 1, 1, 1}, 3);
}