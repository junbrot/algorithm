#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    
    vector<int> answer;
    answer.resize(prices.size());

	vector<int> stack[3];
	stack[0].push_back(prices[0]);
	stack[1].push_back(0);
	stack[2].push_back(0);
	
	for(int i=1; i<prices.size(); i++)
	{
		
		for(int j=0; j<stack[2].size(); j++)
		{
			stack[2][j]++;
		}
		
		int check_cnt = stack[0].size();
		for(int j=0; j<check_cnt; j++)
		{
			if(stack[0].back() > prices[i])
			{
				answer[stack[1].back()] = stack[2].back();
				stack[0].pop_back();
				stack[1].pop_back();
				stack[2].pop_back();
				
			}
			else{
				break;
			}
		}
		stack[0].push_back(prices[i]);
		stack[1].push_back(i);
		stack[2].push_back(0);
	}
	
	for(int i=0; i<stack[0].size(); i++)
	{
		answer[stack[1][i]] = stack[2][i];
	}

    return answer;
}
