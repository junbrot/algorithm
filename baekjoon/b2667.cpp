// 

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int num = 0;
int map[25][25] = {0};
int bfs_index[25][25] = {0};

int x[4] = {0,0,-1,1};
int y[4] = {1,-1,0,0};

int bfs(int f, int s)
{
	int cnt = 0;
	queue<int> q[2];
	q[0].push(f);
	q[1].push(s);
	
	while(!q[0].empty())
	{
		int first = q[0].front();
		int second = q[1].front();
		q[0].pop();
		q[1].pop();

		if(bfs_index[first][second] != '1')
		{
			cnt++;
			bfs_index[first][second] = '1';
			
			for(int i=0; i<4; i++)
			{
				int index_x = first+x[i];
				int index_y = second+y[i];
				
				if((index_x >=0)&&(index_x <num)&&(index_y >=0)&&(index_y <num))
				{
					if(map[index_x][index_y] == 1)
					{
						q[0].push(index_x);
						q[1].push(index_y);
					}
				}
			}
		}
	}
	return cnt;
}

int main() {
	
	scanf("%d",&num);
	for(int i=0; i<num; i++)
	{
		for(int j=0; j<num; j++)
			scanf("%1d",&map[i][j]);		
	}
	
	vector<int> ans;
	for(int i=0; i<num; i++)
	{
		for(int j=0; j<num; j++)
		{
			if((map[i][j] == 1)&&(bfs_index[i][j] == 0))
			{
				ans.push_back(bfs(i,j));
			}
		}
	}

	sort(ans.begin(),ans.end());
	printf("%d\n",ans.size());
	for(int i=0; i<ans.size();i++)
		printf("%d\n",ans[i]);
	
	return 0;
}
