#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    
    vector<string> answer;
	
	for(int i=0; i<n;i++)
	{
		string temp = "";
		char firstIndex[20] = {0};
		char secondIndex[20] = {0};
		
		int firstValue = arr1[i];
		int secondValue = arr2[i];
		
		int fcnt=0;
		while(firstValue > 0)
		{
			firstIndex[fcnt++] = firstValue%2;
			firstValue = firstValue/2;
		}
		
		int scnt=0;
		while(secondValue > 0)
		{
			secondIndex[scnt++] = secondValue%2;
			secondValue = secondValue/2;
		}
		
		for(int i=n-1; i>=0;i--)
		{
			if(firstIndex[i] || secondIndex[i])
				temp+='#';
			else
				temp+=' '; 
		}
		
		answer.push_back(temp);
	}
    return answer;
}
