#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int Find(std::vector<int>& Group, int U){
    if(Group[U] == U){
        return U;
    }
    
    return Group[U] = Find(Group,Group[U]);
}

bool Union(std::vector<int>& Group, int U, int V){
    int URoot = Find(Group, U);
    int VRoot = Find(Group, V);
    // 같은 네트워크 그룹인데 추가하면 사이클 생김
    if(URoot == VRoot){
        return false;
    }
    
    Group[VRoot] = URoot;
    return true;
}

int solution(int n, vector<vector<int>> costs) {
    // 네트워크 그룹을 최소 가격으로 만들어내는것
    // 그러므로 일단 union find 로 그룹을 만드는데
    // 그리디로 최소 가격으로 맞추면 됨
    std::vector<int> Group(n);
    for(int i = 0; i < n; ++i){
        Group[i] = i;
    }
    int Answer = 0;
    std::sort(costs.begin(), costs.end(), [](const std::vector<int>& A, const std::vector<int>& B){
        return A[2] < B[2];
    });
    // 최소 간선부터 적용
    int EdgeCount = 0;
    int AnswerCost = 0;
    for(const std::vector<int>& Cost : costs){
        if(Union(Group, Cost[0], Cost[1])){
            ++EdgeCount;
            AnswerCost += Cost[2];
            
            if(EdgeCount == n-1){
                break;
            }
        }
    }
    
    return AnswerCost;
}