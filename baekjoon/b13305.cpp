// greedy 알고리즘.

#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	
	int num = 0;
	long length[100000] = {0};
	long oil[100000] = {0};
	
	scanf("%d",&num);
	
	for(int i=0; i<num-1; i++)
		scanf(" %ld",&length[i]);
	
	for(int i=0; i<num; i++)
		scanf(" %ld",&oil[i]);
		
	unsigned long long sum = oil[0]*length[0];
	long current = oil[0];
	for(int i=1; i<num-1; i++)
	{
		if(current  < oil[i])
			sum += current*length[i];
		else
        {
			sum += oil[i]*length[i];
			current = oil[i];
        }
	}
	
	printf("%llu",sum);
	
	return 0;
}
