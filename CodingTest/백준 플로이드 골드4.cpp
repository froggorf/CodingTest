#include <iostream>
#include <vector>

int main(){

	std::cin.tie(nullptr);
	std::ios::sync_with_stdio(false);
	int N, M;
	std::cin>>N>>M;
	std::vector<std::vector<int>> Costs(N+1, std::vector<int>(N+1, INT32_MAX));
	for(int i = 0; i < M; ++i){
		int Start,End,Cost;
		std::cin>>Start>>End>>Cost;
		Costs[Start][End] = std::min(Costs[Start][End], Cost);
	}

	// 플루이드 워셜
	// 모든 쌍을 구해야하는거니까

	for(int k = 1; k <= N; ++k){
		for(int Start = 1; Start <= N; ++Start){
			for(int Arr = 1; Arr <= N; ++Arr){
				if(Costs[Start][k] == INT32_MAX || Costs[k][Arr] == INT32_MAX){
					continue;
				}

				Costs[Start][Arr] = std::min(Costs[Start][Arr], Costs[Start][k] + Costs[k][Arr]);
			}
		}
	}

	for(int Start = 1; Start <= N; ++Start){
		for(int Arr = 1; Arr <= N; ++Arr){
			if(Start == Arr){
				std::cout << "0 ";
				continue;
			}

			if(Costs[Start][Arr] == INT32_MAX){
				std::cout<<"0 ";
				continue;
			}

			std::cout << Costs[Start][Arr] <<" ";
		}
		std::cout<<"\n";
	}


}