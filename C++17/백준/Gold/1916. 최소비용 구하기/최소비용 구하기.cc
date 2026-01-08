#include <iostream>
#include <queue>
#include <vector>

int main()
{
	std::cin.tie(nullptr);
	std::ios::sync_with_stdio(false);

	int N, M;
	std::cin>>N>>M;

	std::vector<std::vector<std::pair<int,int>>> Costs(N+1);
	for (int i = 0; i < M; ++i)
	{
		int Start, End, Cost;
		std::cin >> Start >> End >> Cost;
		Costs[Start].emplace_back(End,Cost);
	}

	int A, B;
	std::cin>>A>>B;
	
	std::vector<int> Dist(N+1, 0x3f3f3f3f);
	// A에서 출발하니까 Dist[A] = 0;
	Dist[A] = 0;

	std::priority_queue<std::pair<int, int>, 
		std::vector<std::pair<int, int>>, 
		std::greater<std::pair<int, int>>> PQ;
	PQ.emplace(0,A);

	while (!PQ.empty())
	{
		std::pair<int,int> Cur = PQ.top(); PQ.pop();
		int CurrentCost = Cur.first;
		int CurrentCity = Cur.second;

		if (CurrentCost > Dist[CurrentCity]) continue;

		if (CurrentCity == B) break;

		const std::vector<std::pair<int,int>>& BusData = Costs[CurrentCity];
		for (const std::pair<int,int>& Bus : BusData)
		{
			int NextCity = Bus.first;
			int BusCost = Bus.second;
			int NewCost = CurrentCost + BusCost;
			if (NewCost < Dist[NextCity])
			{
				Dist[NextCity] = NewCost;
				PQ.emplace(NewCost, NextCity);
			}
		}
	}
	std::cout<<Dist[B]<<"\n";
}


// 한 도시에서 출발
// 다른 도시 도착하는 M개의 버스
// A번째 도시에서 B번째 도시까지 가는데 드는 최소비용