

#include <string>
#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    
    string answer = "";
	
	int num_len = number.length();
	int current_index = 0;
	int remove_cnt = 0;
	
	while(1)
	{
		int check_len = k - remove_cnt + 1;
		char big = 0;
		int big_index = -1;
		
		if(remove_cnt == k)
			break;
		
		if((current_index + k - remove_cnt) == num_len)
			break;
		
		
		for(int j=0; j<check_len; j++)
		{
			if(big < number[current_index + j])
			{
				big = number[current_index + j];
				big_index = current_index + j;
			}
		}
		
		if(big_index == -1)
			break;
			
		remove_cnt += big_index - current_index;
		current_index = big_index += 1;
		answer += big;
	}
	
	if(remove_cnt == k)
	{
		for(int i=current_index; i < num_len; i++)
			answer += number[i];
	}
    return answer;
}


int main(void)
{
	cout<<solution("4177252841",4)<<endl;
	cout<<solution("12345",2)<<endl;
	cout<<solution("54321",2)<<endl;
	
}
