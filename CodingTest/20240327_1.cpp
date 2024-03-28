#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    // == 순회로 앞부터 계산할 경우, 시간이 오래 걸릴 뿐더러 모두 찾아봐야함
    // == 가장 짧은 연속된 배열을 구하는 거니까 뒤에서 부터 보는게 더욱 효율적일 것으로 예상

    // == 다만 가장 앞부터 이므로, 값을 찾아도 같은 갯수까지는 이전까지 계속 살펴봐야 할 것으로 예상

    int CurrentSum{};
    auto startP = sequence.rbegin();
    auto endP = sequence.rbegin();

    vector<int> answer;
    answer.push_back(-1);
    answer.push_back(-1);

    for (auto p = sequence.rbegin(); p != sequence.rend(); ++p)
    {
        // == k 보다 큰 숫자는 볼 필요 없음.
        if (*p > k) {
            CurrentSum = 0;
            continue;
        }

        if (answer[0]!=-1 && (distance(startP, endP) > (answer[1] - answer[0] + 1)))
        {
            return answer;
        }

        // == 합해서 k가 되도록 계속 찾기
        // 첫 범위 라면, 스타트 위치를 정해주고
        if (CurrentSum == 0)
        {
            startP = p;
        }
        CurrentSum += *p;
        // 더해지는 곳 까지 endp 를 저장해준다.
        endP = p;

        // 만약 더하던 값이 k를 넘어가면 초기화 후 이전 시작위치 다음부터 시작한다.
        if (CurrentSum > k)
        {
            CurrentSum = 0;
            p = startP;
            continue;
        }
        // == 만약 k 값이 됐다면 값 출력 하지만, begin 기준으로 출력해야함
        else if (CurrentSum == k)
        {
            // == (추가작업) 다만, 범위가 같다는 한에서 앞쪽을 해야 정답이므로,
            // == 이후 작업도 진행해주어야한다.
            if (answer[0]!=-1)
            {
                int firstDistance = answer[1] - answer[0] + 1;
                int fwd = sequence.size() - distance(sequence.rbegin(), endP) - 1;
                int bwd = sequence.size() - distance(sequence.rbegin(), startP) - 1;
                int NowDistance = bwd - fwd + 1;

                if (firstDistance >= NowDistance)
                {
                    answer[0] = fwd;
                    answer[1] = bwd;
                    p = endP;
                    continue;
                }
                else
                {
                    return answer;
                }
            }
            else
            {
                // startP가 begin 기준 뒷쪽
                // endp가 begin 기준 앞쪽
                // rbegin 이므로 -1을 해주어서 값을 통일시켜준다.
                answer[0] = (sequence.size() - distance(sequence.rbegin(), endP) - 1);
                answer[1] = (sequence.size() - distance(sequence.rbegin(), startP) - 1);

            }
        }
    }

    return answer;
}

void main()
{
    solution(vector<int>{1, 2, 3, 4, 5}, 7);
    solution(vector<int>{1, 1, 1, 2, 3, 4, 5},5);
    solution(vector<int>{2,2,2,2,2}, 6);
}