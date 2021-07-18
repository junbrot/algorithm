// 또 bfs
#include <iostream>
#include <queue>
using namespace std;

int X,Y,cnt;

int loc_x[4] = {1,-1,0,0};
int loc_y[4] = {0,0,1,-1};

void bfs(int x, int y, const int b_index[50][50], int temp_index[50][50])
{
	int min_ans = 0;
	queue<int> q[2];
	q[0].push(x);
	q[1].push(y);
	
	while(!q[0].empty())
	{
		int x = q[0].front();
		int y = q[1].front();
		
		q[0].pop();
		q[1].pop();
		
		if((temp_index[x][y] == 0) && (b_index[x][y] == 1))
		{
			temp_index[x][y] = 1;

			for(int i=0; i<4; i++)
			{
				if(x+loc_x[i] >= 0 && x+loc_x[i] <X && y+loc_y[i] >= 0 && y+loc_y[i] <Y)
				{
					q[0].push(x+loc_x[i]);
					q[1].push(y+loc_y[i]);
				}
			}
		}
		
	}
}

int main() {
	int num = 0;
	scanf("%d",&num);
	
	for(int i=0; i<num; i++)
	{

		int b_index[50][50] = {0};
		int temp_index[50][50] = {0};
		scanf(" %d %d %d",&X,&Y,&cnt);
		
		for(int j=0; j<cnt; j++)
		{
			int l,r;
			scanf(" %d %d",&l,&r);
			b_index[l][r] = 1;
		}
		
		int min_answer = 0;
		
		for(int x=0; x<X; x++)
		{
			for(int y=0; y<Y; y++)
			{
				if((temp_index[x][y] == 0)&&(b_index[x][y] == 1))
				{
					bfs(x,y,b_index,temp_index);		
					min_answer++;
					
				}		
			}
		}
		
		printf("%d\n",min_answer);
	}
	
	return 0;
}
