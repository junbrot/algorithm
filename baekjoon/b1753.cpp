// 다익스트라 = stack사용시 시간복잡도 O(V^2) 우선순위 큐 사용시 O(E*logV). 

#include <iostream>
#include <vector>
#include <queue>

#define inf 987654321

using namespace std;


int V,E;
int startNode;
vector<vector<pair<int,int>>> node;
int length[20001];

void dist(int startNode)
{
	priority_queue<pair<int,int>>pq;
	pq.push({0,startNode});
	
	while(!pq.empty()){
		
		int now_node = pq.top().second;
		int cost = -1*pq.top().first;
		
		pq.pop();
		
		for(int i=0; i<node[now_node].size(); i++){
			
			int new_node = node[now_node][i].first;
			int current_length = node[now_node][i].second;
			
			int bef_length = length[new_node];
			int new_length = length[now_node] + current_length;
			
			if(bef_length > new_length){
				length[new_node] = new_length;
				pq.push({-1*new_length, new_node});
			}
		}
	}
}

int main() {
	
	scanf("%d %d",&V,&E);
	scanf(" %d",&startNode);
	
	node.resize(V+1);

	for(int i=0; i<E; i++)
	{
		int f,s,t;
		scanf(" %d %d %d",&f,&s,&t);
		node[f].push_back({s,t});
	}

	for(int i=1; i<=V; i++)
		length[i] = inf;
	length[startNode] = 0;
	dist(startNode);
	
	for(int i=1; i<=V; i++)
	{
		if(length[i] == inf)
			printf("INF\n");
		else
			printf("%d\n",length[i]);
	}
}
