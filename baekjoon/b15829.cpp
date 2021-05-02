#include <iostream>
#include <cmath>
using namespace std;

int main() {
	
	int N;
	scanf("%d",&N);
	
	long long sum = 0;
	long long a = 1;
	
	for(int i=0; i<N; i++)
	{
		char temp;
		scanf(" %c",&temp);
		
		sum = (sum + (temp-'a'+1)*a)%1234567891;
		
		a = (a * 31) % 1234567891;
	}
	
	printf("%lld",sum);
	
	return 0;
}
