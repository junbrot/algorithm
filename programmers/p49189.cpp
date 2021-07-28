//무슨 알고리즘인지 잘 모르겠는데 그냥 제일 긴 경로에 해당하는 노드 갯수 찾으라 해서
//node 갯수 -1 만큼 for문 돌면서, 탐색 level을 1씩 높여가면서 탐색했음
// 만약 탐색한 적이 있는 노드면, 확장 X

#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;
vector<vector<int>> e;
vector<int> check;
int v;

int search_longest()
{
	int longest_num = 0;
	queue<int> bef;
	bef.push(1);
	check[1] = 1;
	
	for(int i=1; i<v; i++)
	{
		int local_num = 0;
		queue<int> q[2];
		
		while(!bef.empty())
		{
			q[0].push(bef.front());
			q[1].push(0);
			bef.pop();
		}
		
		while(!q[0].empty())
		{
			int now = q[0].front();
			int loc_cnt = q[1].front();
			q[0].pop();
			q[1].pop();
			
			if(loc_cnt == 1)
			{
				if(check[now] == 0)
				{	
					check[now] = 1;
					bef.push(now);
					local_num++;
				}
			}
			else
			{
				for(int j=0; j<e[now].size(); j++)
				{
					int next = e[now][j];
					if(check[next] == 0)
					{
						q[0].push(e[now][j]);
						q[1].push(1);
					}
				}
			}
		}
		
		if(local_num > 0)
			longest_num = local_num;
	}
	
	return longest_num;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
	e.resize(n+1);
	check.resize(n+1);
    v = n;
    
    for(int i=0; i<edge.size(); i++)
    {
    	int f = edge[i][0];
    	int s = edge[i][1];
    	
    	e[f].push_back(s);
    	e[s].push_back(f);
    }
	
	answer = search_longest();
    return answer;
}
