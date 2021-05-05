#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	
	int N,C;
	scanf("%d %d",&N,&C);
	
	vector<int> home(N,0);
	
	for(int i=0; i<N; i++)
		scanf(" %d",&home[i]);
	
	sort(home.begin(),home.end());

	int left = 1;
	int right = home[N-1]-home[0];
	
	int ans_mid = -1;
	
	while(1)
	{
		int cnt = 1;
		
		int mid = (left + right)/2;
		int target = home[0];
		
		for(int i=1; i<N; i++)
		{
			if(mid <= home[i] - target)
			{	
				cnt++;
				target = home[i];	
			}
		}
		
		if(cnt < C)
			right = mid - 1;
		else
		{
			left = mid + 1;
			ans_mid = mid;
		}
		
		
		if(left > right)
			break;
			
	}
	printf("%d",ans_mid);
}
