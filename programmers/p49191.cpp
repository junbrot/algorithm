//  각 노드마다 자기자신을 제외하고 모든 다른 노드에 대해
// 다른 노드로 가는 경로가 있거나 + 다른 노드에서 자신에게 오는 경로가 있으면 answer+1이 되는 형식

#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;
vector<vector<int>> node;
int v;
int check[101][101];

int bfs()
{
	// 경로가 있나 없나 먼저 확인
	for(int i=1; i<=v; i++)
	{
		queue<int> q;
		q.push(i);

		while(!q.empty())
		{
			int now_node = q.front();
			q.pop();
			
			if(check[i][now_node] == 0)
			{
				check[i][now_node] = 1;
			
				for(int j=0; j<node[now_node].size(); j++)
				{
					q.push(node[now_node][j]);
				}
			}
		}
	}
	
	
	int answer = 0;
	
	for(int i=1; i<=v; i++)
	{
		int answer_check = 0;	
		for(int j=1; j<=v; j++)
		{
			if((check[i][j] == 1)||(check[j][i] == 1))
				answer_check++;
		}
		
		if(answer_check == v)
			answer++;
	}
	
	return answer;
}

int solution(int n, vector<vector<int>> results) {

    int answer = 0;
    v = n;
    node.resize(n+1);
    
	for(int i=0; i<results.size(); i++)
	{
		int f,s;
		f = results[i][0];
		s = results[i][1];
		node[f].push_back(s);
	}
    
	answer = bfs();
	
    return answer;
}
