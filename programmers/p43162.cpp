// bfs

#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int com_index[200]; 

void bfs(int node, vector<vector<int>> computers)
{
	queue<int> q;
	q.push(node);
	
	while(!q.empty())
	{
		int f = q.front();
		q.pop();
		if(com_index[f] == 0)
		{
			com_index[f] = 1;
			for(int i=0; i<computers[f].size(); i++)
			{
				if((computers[f][i] == 1)&&(i!=f))
					q.push(i);
			}
		}
	}
}

int solution(int n, vector<vector<int>> computers) 
{
    int answer = 0;
    
    for(int i=0; i<computers.size();i++)
    {
    	if(com_index[i] == 0)
    	{
    		bfs(i,computers);
    		answer++;
    	}
    }
    
    return answer;
}
