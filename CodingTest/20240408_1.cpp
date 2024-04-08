#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;

    // ī�װ���
    //unordered_map<string,vector<string>> ClothesByCategory;
    map<string, int> ClothesByCategory;
    for(auto cloth : clothes)
    {
        /*auto p = ClothesByCategory.find(cloth[1]);
        if (p == ClothesByCategory.end())
        {
            vector<string> temp{cloth[0]};
            ClothesByCategory.try_emplace(cloth[1], temp);
            
        }else
        {
            p->second.push_back(cloth[0]);
        }*/
        ClothesByCategory[cloth[1]] += 1;
    }
    // ����� �� : n���� �� �������� ���� ��,
    // 1���� ���� ���� ��� -> nC1 * �ش� ī�װ� �ʟ� ������ // 
    // 2���� ���� ���� ��� -> nC2 * �ش� ī�װ��� ���� ������....
    // 3���� ���� ���� ��� -> nC3 * �ش� ī�װ��� ���� ������..
    // n���� ���� ���� ��� -> nCn * �ش� ī�װ� ���� �Ӱ��������� ��

    //�� ����� ������ �����
    // ���� ������ ��� ===
    // a1 a2 a3
    // b1 b2 b3
    // c1 c2
    // d1 d2 d3
    // ���� ���� ���� 4�� �� ���õǾ��� �� -> 3*3*2*3 = A
    // 3�� ���� -> A/3 + A/3 + A/2 + A/3 -> B
    // 2�� ���� ->
    // ....
    

    // ��� 3. ���������� Ʈ���� �����?
    // 1���� �Ծ��� ��� n=1 �� ���� ���ϰ�
    // 2���� ���ؼ� n=2�� ���� ���ϰ�..
    // 3���� ���ؼ� n=3�� ���� ���ϰ�..

    // ���4. �ʵ鿡���ؼ�
    // a1 a2 a3 X
    // b1 b2 b3 X
    // c1 c2 X 
    // d1 d2 d3 X 

	answer = 1;

    for(auto p = ClothesByCategory.begin(); p!=ClothesByCategory.end(); ++p)
    {
        answer *= (p->second+1);
    }

    return answer - 1; // �ƹ��͵� ���Ծ��� ���� ����;

}

void main()
{
}