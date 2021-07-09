// 소수 찾기
// 1. 소수를 찾아야함.
// 2. 순열 조합들을 재귀함수를 사용해서 표현해야함. 


#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;
int cnt = 0;
int number_index[10000001] = {0};
    
void permutation(string numbers, int input_index[], int num_cnt)
{
	
	if(num_cnt <= numbers.length())
	{	
	
		int num = 0;
		int num_index = 1;
		while(1)
		{
			int flag = 0;
			for(int i=0; i<7; i++)
			{
				if(input_index[i] == num_index)
				{
					num += ((numbers[i]-'0') * pow(10,num_index-1));
					num_index++;
					flag = 1;
					break;
				}
			}
			
			if(flag == 0)
				break;
		}
		
		if(number_index[num] == 1)
		{
			number_index[num] = 0;
			cnt++;
		}
		
		for(int i=0; i<numbers.length(); i++)
		{
			if(input_index[i] == 0)
			{
				int temp_index[7] = {0};
				for(int j=0; j<7; j++)
					temp_index[j] = input_index[j];
				temp_index[i] = num_index;
				permutation(numbers,temp_index,num_cnt+1);
			}
		}
	}
}


int solution(string numbers) {
    int answer = 0;
    
    // 소수면 1로 표시
    
    int start_index = 2;
    int end_index = pow(10,numbers.length());
    
	for(int i=start_index; i<end_index; i++)
	{
		int flag = 0;
		for(int j=2; j<=sqrt(i); j++)
		{
			if(i%j == 0)
			{
				flag = 1;
				break;
			}
		}
		
		if(flag == 0)
		{
			number_index[i] = 1;
		}
	}
	
	int input_index[7] = {0};
	input_index[0] = 1;

	for(int i=0; i<numbers.length(); i++)
	{
		int temp_index[7] = {0};
		temp_index[i] = 1;
		permutation(numbers,temp_index,1);
	}
	
	answer = cnt;
    return answer;
}

int main(void)
{
	printf("%d",solution("7612"));
}
