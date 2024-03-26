#include <string>
#include <iostream>
#include <vector>

using namespace std;

void MakeToUpper(string& s, int i)
{
	if(isalpha(s[i]))
	{
        s[i] = std::toupper(s[i]);
	}
}

string solution(string s) {
    // == find를 이용해 ' '을 찾아 해당 이전 끼리 연결하는 방법으로 진행

    // == 1. 먼저 모든 문자를 소문자로 바꾼다
    for(auto p =s.begin(); p!=s.end(); ++p)
    {
        if (isalpha(*p))
        {
            *p = std::tolower(*p);
        }
    }
    
    // == 2. 맨 앞자에 대해서만 먼저 대문자 처리를 진행하고,
    MakeToUpper(s, 0);

    auto p = s.begin();
    while(p!=s.end())
    {
        // == ' '을 찾아 문자열의 끝이 아니라면 다음 글자를 대문자로 바꿔준다.
        p = find(p, s.end(), ' ');
        if(p!=s.end())
        {
            ++p;
            MakeToUpper(s, distance(s.begin(), p));
        }
    	
        
        
    }

    std::cout << s << std::endl;

    //string answer = "";
    //return answer;
    return s;
}

void main()
{
    solution("3people unFollowed me");
    solution("for the last week");
}