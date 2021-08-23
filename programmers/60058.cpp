// 문제를 잘 읽자  문자열 문제

#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string p) 
{
    
    string answer = "";
	
	int total = 0;
	int u_check = 0;
	string u = "", v="";
	
	if(p.length() == 0)
		return "";
	
	for(int i=0; i<p.length(); i++)
	{
		if(p.at(i)=='(')
			total += 1;
		else if(p.at(i) == ')')
			total -= 1;
		
		if(total < 0 && u_check == 0)
			u_check = 1;
		
		if(total == 0)
		{
			u = p.substr(0,i+1);
			v = p.substr(i+1,p.length());
			break;
		}
	}
	
	if(u_check == 0)
	{
		return u+solution(v);
	}
	else
	{
		
		string complete_v = "(";
		
		if(v.length() == 0)
			complete_v += ')';
		else
			complete_v += (solution(v) + ')');
		
		string new_u = "";
		
		if(u.length() > 2)
		{
			u = u.substr(1,u.length()-2);
			
			for(int i=0; i<u.length(); i++)
			{
				if(u.at(i) == '(')
					new_u += ')';
				else
					new_u += '(';
			}
		}
		else if(u.length() == 2)
		{
			new_u = "";
		}
		else
			return "";
		
		answer = complete_v + new_u;
	}
	
	return answer;
}

int main(void){
	
	string p = "()))((()";
	cout<<solution(p);
}
