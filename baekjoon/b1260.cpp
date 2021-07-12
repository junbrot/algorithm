// bfs, dfs

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int node_map[1001][1001] = {0};

int dfs_answer[1001] = {0};
int dfs_index[1001] = {0};
int dfs_tail = 1;

int bfs_answer[1001] = {0};
int bfs_index[1001] = {0};
int bfs_tail = 1;

int node_num = 0;
int line_num = 0;

void dfs(int start_node)
{
	if(dfs_index[start_node] == 0)
    {
        dfs_answer[dfs_tail++] = start_node;
	    dfs_index[start_node] = 1;
	
	    for(int i=1; i<=node_num; i++)
	    {
		    if(node_map[start_node][i] == 1)
		        dfs(i);
	    }
    }
}

void bfs(int start_node)
{
	queue<int> q;
	q.push(start_node);
	
	while(!q.empty())
	{
		int node = q.front();
		
		if(bfs_index[node] == 0)
		{
			bfs_answer[bfs_tail++] = node;
			bfs_index[node] = 1;

			for(int i=1; i<=node_num; i++)
			{
				if(node_map[node][i] == 1)
					q.push(i);
			}
		}
		q.pop();
	}
}

int main() {
	// your code goes here
	int start_node = 0;
	scanf("%d %d %d",&node_num,&line_num,&start_node);
	
	for(int i=0; i<line_num; i++)
	{
		int first = 0;
		int second = 0;
		scanf("%d %d",&first,&second);
		node_map[first][second] = 1;
		node_map[second][first] = 1;
	}
	
	dfs(start_node);
	
	for(int i=1; i<dfs_tail; i++)
		printf("%d ",dfs_answer[i]);
	printf("\n");

	bfs(start_node);
	
	for(int i=1; i<bfs_tail; i++)
		printf("%d ",bfs_answer[i]);
	printf("\n");

	return 0;
}
