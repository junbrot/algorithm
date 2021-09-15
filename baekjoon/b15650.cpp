#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n,m;

void dfs(int i,vector<int> solution, int check[9])
{

	if(solution.size() == m)
	{
		for(int i=0; i<solution.size(); i++)
			cout<<solution[i]<<' ';
		cout<<'\n';
		return;
	}
	else
	{
		for(int j=i+1; j<=n; j++)
		{
			if(check[j] == 0)
			{
				solution.push_back(j);
				check[j] = 1;
				dfs(j,solution,check);
				solution.pop_back();
				check[j] = 0;
			}
		}
	}

}

int main() {
	
	scanf("%d %d",&n,&m);
	
	int answer = 0;
	for(int i=1; i<=n-m+1; i++)
	{
		int check[9] = {0};
		
		vector<int> solution;
		solution.push_back(i);
		check[i] = 1;
		
		dfs(i,solution,check);
	}
	
	return 0;
}

