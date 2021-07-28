#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int bfs(int words_index[51][51],int end,int len)
{
	int int_index[51] = {0};
	
	queue<int> q[2];
	q[0].push(0);
	q[1].push(0);
	
	int answer = 0;
	while(!q[0].empty())
	{
		int start_node = q[0].front();
		int local_cnt = q[1].front();
		q[0].pop();
		q[1].pop();
		
		if(start_node == end)
		{
			answer = local_cnt;
			break;
		}
		
		if(int_index[start_node] == 0)
		{
			int_index[start_node] = 1;
			for(int i=0; i<len; i++)
			{
				if(words_index[start_node][i] == 1)
				{
					q[0].push(i);
					q[1].push(local_cnt+1);
				}
			}
				
		}
	}
	return answer;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int words_index[51][51] = {0};
    int words_len = begin.length();
	words.insert(words.begin(),begin);
	
    for(int i=0; i<words.size(); i++)
	{
		for(int j=0; j<words.size(); j++)
		{
			int cnt = 0;
			for(int k=0; k<words_len; k++)
			{
				if(words[i][k] - words[j][k])
				{
					cnt++;
				}
			}
			
			if(cnt == 1)
			{
				words_index[i][j] = words_index[j][i] = 1;
			}
		}
	}
	
	int target_index = 0;
	for(int i=0; i<words.size();i++)
	{
		if(target == words[i])
		{
			target_index = i;
			break;
		}
	}
	
	answer = bfs(words_index,target_index,words.size());
    return answer;
}
