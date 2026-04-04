#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    // n == 10000
    // 100000000 1억이니까 n^2 도 어느정도 가능
    
    std::vector<int> Answer(prices.size());
    
    for(int i = 0; i < prices.size() - 1; ++i){
        int Time = 0;
        for(int j = i + 1; j < prices.size(); ++j){
            ++Time;
            if(prices[i] > prices[j]){
                break;
            }
        }
        Answer[i] = Time;
    }
    // 마지막은 무조건 안떨어지니까
    
    return Answer;
    
}