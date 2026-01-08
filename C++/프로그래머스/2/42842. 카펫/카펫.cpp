#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer(2);
    // yellow 가 나눠지는지 하고서
    for(int i = 1; i <= yellow; ++i)
    {
        if(yellow % i == 0){
            int Width = i+2;
            int Height = (yellow/i) + 2;
             if(Width * Height == brown + yellow){
                 if(Width > Height){
                     answer[0] = Width;
                     answer[1] = Height;
                 }
                 else{
                     answer[0] = Height;
                     answer[1] = Width;
                 }
                 break;
             }
        }
    }
    
    
    return answer;
}