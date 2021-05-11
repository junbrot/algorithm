// LCS(dp)
#include <iostream>
#include <cstring>
using namespace std;

int main() {
	
	char front[1001] = {0};
	char back[1001] = {0};
	
	scanf("%s",front);
	scanf("%s",back);
	
	int dp[1001][1001] = {0};
	
	for(int i=1; i<=strlen(back); i++)
	{
		for(int j=1; j<=strlen(front); j++)
		{
			if(front[j-1] == back[i-1])
				dp[i][j] = dp[i-1][j-1]+1;
			else
			{
				dp[i][j] = dp[i-1][j] > dp[i][j-1]? dp[i-1][j] : dp[i][j-1];
			}
		}
	}
	printf("%d",dp[strlen(back)][strlen(front)]);
	
	return 0;
}
