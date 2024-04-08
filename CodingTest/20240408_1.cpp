#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;

    // 카테고리와
    //unordered_map<string,vector<string>> ClothesByCategory;
    map<string, int> ClothesByCategory;
    for(auto cloth : clothes)
    {
        /*auto p = ClothesByCategory.find(cloth[1]);
        if (p == ClothesByCategory.end())
        {
            vector<string> temp{cloth[0]};
            ClothesByCategory.try_emplace(cloth[1], temp);
            
        }else
        {
            p->second.push_back(cloth[0]);
        }*/
        ClothesByCategory[cloth[1]] += 1;
    }
    // 경우의 수 : n개의 옷 가짓수가 있을 때,
    // 1개의 옷을 입을 경우 -> nC1 * 해당 카테고리 옷읙 ㅏ짓수 // 
    // 2개의 옷을 입을 경우 -> nC2 * 해당 카테고리의 옷의 가짓수....
    // 3개의 옷을 입을 경우 -> nC3 * 해당 카테고리의 옷의 가짓수..
    // n개의 옷을 입을 경우 -> nCn * 해당 카테고리 옷으 ㅣ가짓수들의 합

    //위 방식은 구현의 어려움
    // 새로 생각한 방식 ===
    // a1 a2 a3
    // b1 b2 b3
    // c1 c2
    // d1 d2 d3
    // 예시 문제 기준 4개 다 선택되었을 때 -> 3*3*2*3 = A
    // 3개 선택 -> A/3 + A/3 + A/2 + A/3 -> B
    // 2개 선택 ->
    // ....
    

    // 방법 3. 내부적으로 트리를 만들면?
    // 1개만 입었을 경우 n=1 의 값을 구하고
    // 2개에 대해선 n=2의 값을 구하고..
    // 3개에 대해선 n=3의 값을 구하고..

    // 방법4. 옷들에대해서
    // a1 a2 a3 X
    // b1 b2 b3 X
    // c1 c2 X 
    // d1 d2 d3 X 

	answer = 1;

    for(auto p = ClothesByCategory.begin(); p!=ClothesByCategory.end(); ++p)
    {
        answer *= (p->second+1);
    }

    return answer - 1; // 아무것도 안입었을 때를 제외;

}

void main()
{
}