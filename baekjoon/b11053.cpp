// lis
#include <iostream>
using namespace std;

int main() {
	
	int N;
	int arr[1001] = {0};
	
	scanf("%d",&N);
	
	for(int i=1; i<=N; i++)
		scanf("%d ",&arr[i]);
	
	int dp[1001] = {0};
	int len_dp = 1;
	
	for(int i=1; i<=N; i++)
	{
		if(arr[i] > dp[len_dp-1])
			dp[len_dp++] = arr[i];
		else
		{
			int start = 0;
			int end = len_dp-1;
			while(1)
			{
			
				int mid = (start + end)/2;
				
				if((dp[mid]<arr[i]) && (arr[i] <=dp[mid+1]))
				{
					dp[mid+1] = arr[i];
					break;
				}
				else
				{
					if((dp[mid]<arr[i]))
						start = mid;
					else
						end = mid;
				}
			}
		}
	}
	
	printf("%d",len_dp-1);
	
	return 0;
}
