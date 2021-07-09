// 

#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a, int b){
	return a<b;
}

int main() {
	
	int height[9] = {0};
	int h_sum= 0;
	for(int i=0; i<9; i++)
	{
		scanf("%d",&height[i]);
		h_sum +=height[i];
	}	
	
	sort(height,height+9,compare);
	
	int first = 0;
	int second = 0;
	for(int i=0; i<9; i++)
	{
		int flag = 0;
		for(int j=i+1; j<9; j++)
		{
			int local_first = height[i];
			int local_second = height[j];
			
			if( (h_sum - local_first - local_second) < 100)
				break;
			else if( (h_sum - local_first - local_second) == 100)
			{
				first = i;
				second = j;
				flag = 1;
			}
		}
		
		if(flag == 1)
			break;
	}
	
	int check_sum = 0;
	for(int i=0; i<9; i++)
	{
		if((i!=first) && (i!=second)){
			
			printf("%d\n",height[i]);
			check_sum += height[i];	
		}
	}
	return 0;
}
