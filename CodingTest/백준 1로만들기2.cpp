#include <iostream>
#include <vector>

int main(){
	// 바로 생각나는건 DP[1] ~ DP[1000000] 까지 굴리는건데,
	// 100만번에 대해서 3개의 연산이 들어가고 그냥 출력하는거니까.. 괜찮을듯
	// 근데 방법이 필요하니까..
	// 그냥 다 구해서 -1인 것들로 가면 될거같음

	std::vector<int> DP(1000005, INT32_MAX);
	int N;
	std::cin>>N;

	DP[1] = 0;
	for(int i = 1; i < N+1; ++i){
		if(i * 3 < 1000002){
			DP[i*3] = std::min(DP[i*3], DP[i] + 1);
		}
		if(i * 2 < 1000002){
			DP[i*2] = std::min(DP[i*2], DP[i] + 1);
		}
		if(i+1 < 1000002){
			DP[i+1] = std::min(DP[i+1], DP[i] + 1);
		}
	}

	std::cout << DP[N] << "\n";
	while(true){
		std::cout<<N<<" ";

		if(N==1){
			break;
		}

		if(N%3 == 0 && DP[N/3] == DP[N] - 1){
			N = N/3;
		}
		else if(N%2 == 0 && DP[N/2] == DP[N]-1){
			N= N/2;
		}
		else{
			N-=1;
		
		}

	}

}