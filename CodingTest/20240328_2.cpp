#include <iostream>
#include <stack>
#include<string>
using namespace std;

int solution(string s)
{
    //1. 포인터를 활용해서 붙어있는 2개를 계속해서 제거해나가는 방식으로 접근해보기 <- 바로 생각이 정리 안돼서
    //2. 2개가 아니라 막힐 경우 선입후출의 방식을 가지는 스택 구조를 활용해보기로 함.

    // 스택을 만들고
    stack<char> MyStack;
    // 첫 데이터는 넣어주고 시작
    MyStack.push(s[0]);

    // 모든 원소를 살펴보면서
    for(int i=1; i<s.size(); ++i)
    {
        if(!MyStack.empty())
        {
            // 이전에 담은 것과 같다면 꺼내고 다음 원소 보기
            if (MyStack.top() == s[i])
            {
                MyStack.pop();
                continue;
            }
        }
        MyStack.push(s[i]);
    }
    cout << MyStack.size();
    if (MyStack.empty()) return 1;
    else return 0;

    int answer = -1;

  

    return answer;
}

void main()
{
    solution("abcdefghijklmnopponmlkjihgfedcba");
}