// 이상한 문자열 문제

#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    int refactor_check = 0;
    
	int new_len = new_id.size();
	if(3 <= new_len && new_len <= 15)
	{
		for(int i=0; i<new_len; i++)
		{	
			int cond1 = ('a'<=new_id[i] && new_id[i] <= 'z');
			int cond2 = ('0'<=new_id[i] && new_id[i] <= '9');
			int cond3 = (new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.');
			
			if(!(cond1 || cond2 || cond3))
			{
				refactor_check = 1;
				break;
			}
		}

		if(refactor_check == 0)
		{
			int bef_dot = 0;
			for(int i=0; i<new_len; i++)
			{

				if(new_id[i] == '.')
				{
					if(bef_dot == 1)
					{
						refactor_check = 1;
						break;
					}
					else
					{
						bef_dot = 1;
					}
				}
				else
					bef_dot = 0;
			}
			if(refactor_check == 0)
			{
				if(new_id[new_len] == '.'||new_id[0] == '.')
					refactor_check = 1;
			}
		}
	}
	else
	{
		refactor_check = 1;	
	}
	
	if(refactor_check == 0)
		answer = new_id;
	else
	{
		// 1단계
		for(int i=0; i<new_len; i++)
			new_id[i] = tolower(new_id[i]);

		// 2단계
		string new_id_2 = "";
		for(int i=0; i<new_len; i++)
		{	
			int cond1 = ('a'<=new_id[i] && new_id[i] <= 'z');
			int cond2 = ('0'<=new_id[i] && new_id[i] <= '9');
			int cond3 = (new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.');
			
			if(!(cond1 || cond2 || cond3))
				continue;
			new_id_2+=new_id[i];
		}
		
		// 3단계
		string new_id_3 = "";
		
		int new_len = new_id_2.size();
		int bef_dot = 0;
		for(int i=0; i<new_len; i++)
		{
			if(new_id_2[i] == '.')
			{
				if(bef_dot == 1)
					continue;
				else
				{
					bef_dot = 1;
				}
			}
			else
				bef_dot = 0;
			
			new_id_3 += new_id_2[i];
		}
		
		//4단계
		if(new_id_3[new_id_3.size()-1] == '.')
			new_id_3.erase(new_id_3.size()-1,1);
		if(new_id_3[0] == '.')
			new_id_3.erase(0,1);
		
		//5단계
		if(new_id_3.size() == 0)
			new_id_3 += 'a';
		
		//6단계
		if(new_id_3.size() >= 16)
			new_id_3.erase(15,new_id_3.size()-15);
		if(new_id_3[new_id_3.size()-1] == '.')
			new_id_3.erase(new_id_3.size()-1,1);
		
		//7단계
		if(new_id_3.size() <= 2)
		{
			while(new_id_3.size()<3)
				new_id_3 += new_id_3[new_id_3.size()-1];
		}
		
		answer = new_id_3;
		
	}

	return answer;
}
