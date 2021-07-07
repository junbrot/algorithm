#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    
    int answer = 0;
	sort(people.begin(),people.end());
	
	int start_index = 0;
	int end_index = people.size();
	
	int cnt = 0;
	while(1)
	{
		int big_index = 0;
		
		if(people[start_index] > limit)
			break;

		for(int i=end_index-1; i>start_index; i--)
		{
			if(people[start_index]+ people[i] <= limit)
			{
				big_index = i;
				break;
			}
		}
		
		if(big_index == 0)
			break;

		cnt += 1;
		end_index = big_index;
		start_index+=1;
	}
	
	answer = people.size()-cnt;
	return answer;
}
