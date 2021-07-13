// dfs

#include <string>
#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;
vector<int> arr;
int arr_cnt;
int cnt;

void dfs(int sum,int n, int target)
{
	if(n == arr_cnt)
	{
		if(sum == target)
			cnt++;
	}
	else
	{
		dfs(sum+arr[n],n+1,target);
		dfs(sum-arr[n],n+1,target);
	}
}

int solution(vector<int> numbers, int target) {
    
    int answer = 0;
	arr_cnt = numbers.size();
  
    for(int i=0; i<arr_cnt; i++)
    	arr.push_back(numbers[i]);
    
    dfs(0,0,target);
	answer = cnt;
    return answer;
}
