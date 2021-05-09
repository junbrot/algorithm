// 

#include <iostream>
using namespace std;

int dp_func(int* coin,int coin_num,int (*dp)[10005],int price)
{
	
	//가장 작은 코인에 해당하는 dp값은 정렬해 놓음.
	for(int i=0; i<=price; i++)
	{
		if(i%coin[0] == 0)
			dp[0][i] = 1;
	}

	for(int i=1; i<coin_num; i++)
	{
		dp[i][0] = 1;
		
		for(int j=0; j<=price; j++)
		{
			if(j < coin[i])
				dp[i][j] = dp[i-1][j];
				
			else
				dp[i][j] = dp[i-1][j] + dp[i][j-coin[i]];
		}
	}
	
	return dp[coin_num - 1][price];
}

int main() {
	
	int N = 0;
	scanf("%d",&N);
	
	for(int i=0; i<N; i++)
	{
		int coin[25] = {0};
		int dp[25][10005] = {0};
		
		int coin_num = 0;
		scanf("%d",&coin_num);
		
		for(int j=0; j<coin_num; j++)
			scanf(" %d",&coin[j]);
			
		int price = 0;
		scanf("%d",&price);
		
		int answer = dp_func(coin,coin_num,dp,price);
		printf("%d\n",answer);
	}
	return 0;
}
