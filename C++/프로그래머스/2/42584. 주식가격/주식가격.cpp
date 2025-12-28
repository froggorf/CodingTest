#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(),0);
    // 뭔가 스택 쓰면 좋아보이는데..
    std::stack<std::pair<int,int>> S;
    for(int i = 0; i < prices.size(); ++i)
    {
        while(!S.empty() && S.top().second > prices[i])
        {
            std::pair<int,int> Top = S.top(); S.pop();
            answer[Top.first] = i - Top.first;
        }
        S.emplace(i, prices[i]);
    }
    
    while(!S.empty())
    {
        std::pair<int,int> Top = S.top(); S.pop();
        answer[Top.first] = prices.size() - Top.first - 1;
    }
    
    return answer;
}