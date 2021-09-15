#include <iostream>
#include <vector>
#define MAX_VAL 987654321
using namespace std;

int n;
int arr[20][20];
int min_answer = MAX_VAL;

void dfs(int num, vector<int> ans)
{
	if(ans.size() == n/2)
	{
		int check[20] = {0};
		for(int i=0; i<ans.size(); i++)
		{
			check[ans[i]] = 1;
		}
		
		vector<int> not_ans;
		
		for(int i=0; i<n; i++)
		{
			if(check[i] == 0)
				not_ans.push_back(i);
		}
		
		int front = 0,back=0;
		
		for(int i=0; i<ans.size(); i++)
		{
			for(int j=i+1; j<ans.size(); j++)
			{
				front += arr[ans[i]][ans[j]];
				front += arr[ans[j]][ans[i]];
			}
		}
		
		for(int i=0; i<not_ans.size(); i++)
		{
			for(int j=i+1; j<not_ans.size(); j++)
			{
				back += arr[not_ans[i]][not_ans[j]];
				back += arr[not_ans[j]][not_ans[i]];
			}
		}
		
		if(abs(front - back) < min_answer)
			min_answer = abs(front - back);
	}
	else
	{
		for(int i=num+1; i<n; i++)
		{
			ans.push_back(i);
			dfs(i,ans);
			ans.pop_back();
		}
	}
}

int main() {
	
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			scanf(" %d",&arr[i][j]);
		}
	}
	
	vector<int> ans;
	ans.push_back(0);
	dfs(0,ans);
	
	cout<<min_answer;
	return 0;
}
