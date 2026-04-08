#include <string>
#include <vector>

using namespace std;
int Answer = INT32_MAX;
string Begin;
string Target;
vector<string> Words;

void BackTracking(std::vector<bool>& Visited, string Cur, int Depth){
    if(Cur == Target){
        Answer = std::min(Answer,Depth);
    }
    for(int i = 0; i < Words.size(); ++i){
        if(Visited[i]){
            continue;
        }
        
        int WrongCount = 0;
        for(int Index = 0; Index < Cur.length(); ++Index){
            if(Cur[Index] != Words[i][Index]){
                ++WrongCount;
                if(WrongCount >= 2){
                    break;
                }
            }
        }
        if(WrongCount == 1){
            Visited[i] = true;
            BackTracking(Visited, Words[i], Depth+1);
            Visited[i]= false;
        }
    }
    
}

int solution(string begin, string target, vector<string> words) {
    // 백트래킹을 활용하면 될것같음
    Begin = begin;
    Target = target;
    Words = words;
    
    std::vector<bool> Visited(words.size(), false);
    BackTracking(Visited, Begin, 0);
    if(Answer == INT32_MAX){
        return 0;
    }
    return Answer;
}