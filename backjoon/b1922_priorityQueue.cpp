// prim 알고리즘
// 최소 신장 트리 구하는 방법중 1
// 구현방법은 1.배열을 사용 -> O(V^2)
//            2.priorityqueue사용 -> O(E log V)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int V,E;
vector<vector<pair <int, int>>> v;
int v_index[1001];

void prim()
{
	priority_queue<vector<int>> q;
	int start_node = 1;
	v_index[start_node] = 1;
	
	vector<int> temp = {-1*v[1][0].second,1,v[1][0].first};
	for(int i=0; i<v[start_node].size(); i++)
	{
		q.push({-1*v[start_node][i].second,start_node,v[start_node][i].first});
	}
	
	int ans = 0;
	while(!q.empty())
	{
		vector<int> temp = q.top();
		
		int len = temp[0];
		int now = temp[1];
		int next = temp[2];

		q.pop();
	
		if(v_index[next] == 0)
		{
			v_index[next] = 1;
			ans += len;
			
			for(int i=0; i<v[next].size(); i++)
				q.push({-1*v[next][i].second,next,v[next][i].first});
		}
	}
	printf("%d\n",-1*ans);
}

int main() 
{
	// your code goes here
	scanf("%d",&V);
	scanf(" %d",&E);
	v.resize(V+1);
	
	for(int i=0; i<E; i++)
	{
		int f,s,t;
		
		scanf(" %d %d %d",&f,&s,&t);
		v[f].push_back({s,t});
		v[s].push_back({f,t});
	}
	
	prim();
	
	return 0;
}
