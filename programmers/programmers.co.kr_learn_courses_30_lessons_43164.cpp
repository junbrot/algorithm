#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<string> final_answer;
int dfs(vector<pair<string,string>> p, vector<string> answer,string first,int target_num)
{
	if(p.size()==0)
	{
		for(int i=0; i<answer.size(); i++)
			final_answer.push_back(answer[i]);
		
		return 1;
	}
	else
	{
		int num = p.size();
		for(int i=0; i<num; i++)
		{
			if(p[i].first == first)
			{
				answer.push_back(p[i].second);
				
				vector<pair<string,string>> temp;
				temp.assign(p.begin(), p.end());
				temp.erase(temp.begin()+i);
				
				if(dfs(temp,answer,p[i].second,target_num)==1)
					return 1;
				answer.pop_back();
			}
		}
	}
	return 0;
}

vector<string> solution(vector<vector<string>> tickets) {
    
    vector<string> answer;
    vector<pair<string,string>> p;
    for(int i=0; i<tickets.size(); i++)
    	p.push_back(pair<string,string>(tickets[i][0],tickets[i][1]));
	
	sort(p.begin(),p.end());
	
	string first_index = "ICN";
    answer.push_back(first_index);
    dfs(p,answer,first_index,p.size()+1);
    
    return final_answer;
}
