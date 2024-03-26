//https://school.programmers.co.kr/learn/courses/30/lessons/12939

#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

string solution(string s) {

    vector<int> nums;
    int num;

    // == s를 이용해 stringstream을 만들고(버퍼)
    stringstream ss(s);
    while (ss >> num)
    {
        // == nums 벡터에 값을 저장한다.
        nums.push_back(num);
    }


    int maxint{};
    int minint{};

    // == std::max_element, std::min_element로 최댓값과 최솟값을 구해
	maxint = *max_element(nums.begin(), nums.end());
    minint = *min_element(nums.begin(), nums.end());

    // == string으로 출력해낸다.
    string answer = std::to_string(minint) +" "+std::to_string(maxint);
    return answer;
}

void main()
{
    solution("-1 -1");
}