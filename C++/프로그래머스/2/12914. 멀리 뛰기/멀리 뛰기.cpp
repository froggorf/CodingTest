#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    // 1칸 뛰는 방법은 1
    // 2칸 뛰는 방법은 2
    // 3칸 뛰는 방법은 (DP[3-2]) + (DP[3-1])
    if(n == 1){
        return 1;
    }
    if(n==2){
        return 2;
    }
    
    std::vector<long long> DP(n+3, -1);
    DP[1] = 1;
    DP[2] = 2;
    for(int i = 3; i <= n; ++i){
        DP[i] = (DP[i-2] + DP[i-1]) % 1234567;
    }
    
    
    return DP[n];
    
}