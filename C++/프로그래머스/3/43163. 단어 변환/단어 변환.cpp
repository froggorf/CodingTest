#include <string>
#include <vector>
#include <algorithm>
using namespace std;

std::string Target;
std::vector<std::string> Words; //편하려고 어차피 수도 적으니까 걍 만듦

bool CanExchange(const std::string& CurStr, const std::string& Word){
    int DiffCount = 0;
    for(int i = 0; i < CurStr.length(); ++i){
        if(CurStr[i] != Word[i]){
            ++DiffCount;
        }
        
        if(DiffCount >= 2){
            break;
        }
    }
    
    return DiffCount == 1;
}

int Answer = INT32_MAX;
void Func(const std::string& CurStr, std::vector<bool>& Visited, int ExchangeCount){
    if(CurStr == Target){
        Answer = std::min(Answer, ExchangeCount);
        return;
    }
    
    size_t WordsSize = Words.size();
    for(size_t i = 0; i < WordsSize; ++i){
        // 이전에 방문했으면 하면 안되고
        if(Visited[i]){
            continue;
        }
        
        // 변환이 가능하다면, 즉 1개의 차이만 가지고있으면
        if(CanExchange(CurStr, Words[i])){
            Visited[i] = true;
            Func(Words[i], Visited, ExchangeCount + 1);
            Visited[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    Words = words;
    Target = target;
    // 정렬을 한번 해줘서 찾기 쉽게 해준다음에 50log50 으로 극히 작은수,
    std::sort(words.begin(),words.end());
    
    // 일단 target이 words 안에 없는 경우엔 못만듦,
    if(!std::binary_search(words.begin(), words.end(), target)){
        return 0;
    }
    
    // 정렬을 통해 binary search 하려 했는데, 굳이 그럴필요 없이 그냥 각 원소들과 차이가 한개인지 같은거만 하는게 맞는거같음, 단어 길이가 3~10이니까
    std::vector<bool> Visited(words.size(), false);
    Func(begin, Visited, 0);
    
    if(Answer == INT32_MAX){
        return 0;
    }
    return Answer;
    
}