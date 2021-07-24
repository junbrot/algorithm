// 그래프의 최단경로 찾는 문제에 음의 가중치가 있을때는 벨만 포드 알고리즘.
// 그냥 V-1번 주어진 E를 탐색함. V번째 탐색했을 때, 최단거리가 업데이트 된다는 거는 음의 루프가 있다는 거고.
// 시간복잡도 : O(VE) V-1번 E개를 탐색하니깐. 진짜 극혐

#include <iostream>
#include <vector>
#include <queue>

#define INF 987654321

using namespace std;

int V,E;
vector<pair<pair<int,int>,int>> node;
vector<long long> length;

int bell()
{

	for(int i=0; i<V; i++)
	{	
		for(int j=0; j<node.size(); j++)
		{
			int startNode = node[j].first.first;
			int nextNode = node[j].first.second;
			int len = node[j].second;
			
			if(length[startNode] == INF)
				continue;
			else if(length[startNode]+len < length[nextNode])
			{
				if(i == V-1)
					return -1;
				length[nextNode] = length[startNode]+len;
			}
		}
	}
	
	return 1;
}

int main() {
	
	scanf("%d %d",&V,&E);
	length.resize(V+1);
	
	for(int i=0;i<E;i++)
	{
		int f,s,t;
		scanf(" %d %d %d",&f,&s,&t);
		node.push_back({{f,s},t});
	}
	
	for(int i=1; i<=V; i++)
		length[i] = INF;
	length[1] = 0;
	
	if(bell() == -1)
		printf("%d",-1);
	else
	{
		for(int i=2; i<=V; i++)
		{
			if(length[i] == INF)
				printf("-1\n");
			else
				printf("%lld\n",length[i]);
		}
	}
	
	return 0;
}
