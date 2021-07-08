// brute force

#include <iostream>
using namespace std;

int main() {
	
	int num=0;
	int index_arr[1000] = {0};
	int k[1000] = {0};
	
	scanf("%d",&num);
	
	for(int i=0; i<num; i++)
		scanf("%d",&k[i]);
	
	int i = 1;
	while(1)
	{
		int j = i*(i+1)/2;
		if(j > 1000)
			break;
		
		index_arr[j] = 1;
		i++;
	}
	
	for(int i=0; i<num; i++)
	{
		int flag = 0;
		for(int one=1; one<k[i]; one++)
		{
			for(int two=one; two<k[i]; two++)
			{
				int three = k[i] - one - two;
				
				if(three <two)
					break;
				
				if(index_arr[one] &&index_arr[two] && index_arr[three])
				{
					printf("1\n");
					flag = 1;
					break;
				}
			}
			if(flag == 1)
				break;
		}
		if(flag != 1)
			printf("0\n");
	}
	return 0;
}
