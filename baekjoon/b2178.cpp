// 최단거리 = bfs

#include <iostream>
#include <queue>
using namespace std;

char map[102][102] = {0};
int H = 0;
int W = 0;

int bfs_index[101][101] = {0};

void bfs()
{
	int h = 1;
	int w = 1;
	int cnt = 1;
	queue<int> q[3];
	
	q[0].push(h);
	q[1].push(w);
	q[2].push(cnt);
	
	while(!q[0].empty())
	{
		h = q[0].front();
		w = q[1].front();
		cnt = q[2].front();
		q[0].pop();
		q[1].pop();
		q[2].pop();

		if((h == H)&& (w == W))
		{
			printf("%d",cnt);
			break;	
		}
		else
		{
			if((map[h+1][w] == '1')&& (bfs_index[h+1][w] == 0))
			{
				q[0].push(h+1);
				q[1].push(w);
				q[2].push(cnt+1);
				bfs_index[h+1][w] = 1;
			}
			
			if((map[h-1][w] == '1')&& (bfs_index[h-1][w] == 0))
			{
				q[0].push(h-1);
				q[1].push(w);
				q[2].push(cnt+1);
				bfs_index[h-1][w] = 1;
			}
			
			if((map[h][w+1] == '1')&& (bfs_index[h][w+1] == 0))
			{
				q[0].push(h);
				q[1].push(w+1);
				q[2].push(cnt+1);
				bfs_index[h][w+1] = 1;
			}
			
			if((map[h][w-1] == '1')&& (bfs_index[h][w-1] == 0))
			{
				q[0].push(h);
				q[1].push(w-1);
				q[2].push(cnt+1);
				bfs_index[h][w-1] = 1;
			}
			cnt++;
		}
		
	}
}

int main() {
	
	scanf("%d %d",&H,&W);

	for(int i=1; i<=H; i++)
	{
		for(int j=1; j<=W; j++)
			scanf(" %c",&map[i][j]);
	}
	
	bfs();
}
