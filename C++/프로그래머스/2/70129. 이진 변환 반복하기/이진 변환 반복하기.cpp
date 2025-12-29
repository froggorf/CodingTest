#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



vector<int> solution(string s) {
    vector<int> answer(2, 0);
    while(s != "1"){
        ++answer[0];
        
        // 1. 0을 다 지우고
        size_t OriginLength = s.length();
        s.erase(std::remove(s.begin(), s.end(), '0'), s.end());
        size_t CurrentLength = s.length();
        answer[1] += (OriginLength - CurrentLength);
        
        
        // 2. 길이로 새로 만든다.
        s.clear();
        s.reserve(1000);
        while(CurrentLength > 0){
            if(CurrentLength & 1){
                s = '1' + s;
            }
            else{
                s = '0' + s;
            }
            CurrentLength = CurrentLength >> 1;
        }
    }
    
    // 01110
    // -> 111 -> 11 (1, 2)
    // -> 11 -> 10 (2,2)
    // -> 1 -> 1 (3,3)
    
    
    
    
    
    return answer;
}