#include <string>
#include <vector>
#include <algorithm>

using namespace std;
std::vector<int> Answer;
void Func(std::string& s){
    int ZeroCount = 0;
    for(const char C : s){
        if(C == '0'){
            ++ZeroCount;
        }
    }
    Answer.emplace_back(ZeroCount);
    int Length = s.length() - ZeroCount;  
    s.clear();
    s.reserve(100);
    while(true){
        if(Length == 0){
            break;
        }
        if(Length & 1){
            s.push_back('1');
        }
        else{
            s.push_back('0');
        }
        Length/=2;
        
    }
    std::reverse(s.begin(),s.end());
    
}


vector<int> solution(string s) {
    // s의 길이는 15만,
    // 모두다 1이라 할때 
    // 15만 -> 대략 10번 내외임
    // 그럼 n * 10 해도 충분하니까 그냥 썡으로 돌리는게 나음
    
    while(s != "1"){
        Func(s);
    }
    std::vector<int> A(2,0);
    A[0] = Answer.size();
    for(int i = 0; i < Answer.size(); ++i){
        A[1] += Answer[i];
    }
    return A;
}