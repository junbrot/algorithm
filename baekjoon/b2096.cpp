// dp문제. top-down

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
	
	int N;
	scanf("%d",&N);
	
	int min_arr[3] = {0};
	int max_arr[3] = {0};
	
	scanf("%d %d %d",&min_arr[0],&min_arr[1],&min_arr[2]);
	max_arr[0] = min_arr[0];
	max_arr[1] = min_arr[1];
	max_arr[2] = min_arr[2];
	
	int temp[3] = {0};
	
    int first_min,second_min,third_min;
    int first_max,second_max,third_max;
    
	for(int i=1; i<N ; i++)
	{
		scanf("%d %d %d",&temp[0],&temp[1],&temp[2]);
		
		first_min = min(min_arr[0],min_arr[1]);
		third_min = min(min_arr[1],min_arr[2]);
		second_min = min(first_min,third_min);
		
		first_max = max(max_arr[0],max_arr[1]);
		third_max = max(max_arr[1],max_arr[2]);
		second_max = max(first_max,third_max);
		
		min_arr[0] = temp[0] + first_min;
		min_arr[1] = temp[1]+ second_min;
		min_arr[2] = temp[2] + third_min;
		
		max_arr[0] = temp[0] + first_max;
		max_arr[1] = temp[1] + second_max;
		max_arr[2] = temp[2] + third_max;
	}
	
	first_min = min(min_arr[0],min_arr[1]);
	second_min = min(min_arr[1],min_arr[2]);
	third_min = min(first_min,second_min);
	
	first_max = max(max_arr[0],max_arr[1]);
	second_max = max(max_arr[1],max_arr[2]);
	third_max = max(first_max,second_max);
	
	printf("%d %d",third_max,third_min);
	return 0;
}
