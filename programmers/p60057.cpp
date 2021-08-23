// 문자열 문제 : ab가 10개있으면 10ab로 표현 가능, 100개있으면 100ab로 표현 가능 하다는걸 생각 못해서 1:30이나 걸린


#include <string>
#include <vector>
#include <iostream>

using namespace std;

int cnt_function(int cnt){
	int local_cnt = 0;
	if(cnt < 10)
		local_cnt = 1;
	else if(cnt < 100)
		local_cnt = 2;
	else if(cnt < 1000)
		local_cnt = 3;
	else
		local_cnt = 4;
	return local_cnt;
}

int solution(string s) {

    int answer = 1001;

    for(int i=0; i<=(s.size())/2; i++)
    {
    	int length = i+1;
		int local_answer = 0; 	

    	string front = s.substr(0,length);
    	string back = "";
    	int cnt = 1;
    	
    	for(int j=length; j<s.size(); j+=length)
    	{
    		string back = s.substr(j,length);
    	
    		if(front.compare(back) == 0)
    		{
    			cnt += 1;
    		}
    		else
    		{
    			if(cnt > 1)
    				local_answer += length + cnt_function(cnt);
    			else
    				local_answer += length;
    			
    			front = back;
    			cnt = 1;
    		}

    	}
		
		if(cnt > 1)
		{
			
			
			local_answer += length +cnt_function(cnt);
		}
		else
		{
			local_answer += front.size();
		}
		
		if(answer > local_answer)
			answer = local_answer;
    }
    return answer;
}
