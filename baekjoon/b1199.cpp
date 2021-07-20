// 두 점 사이의 선이 하나가 아닐 수 있음.(이거때문에 시간 개많이날림)
// 오일러 회로 = 모든 정점이 차수가 2의배수면 어디서 시작하던 회로가 존재. 

#include <iostream>
#include <vector>
using namespace std;

int node[1001][1001];
int N;

void dfs(int n)
{
	for(int i=1; i<=N; i++)
	{
	    while(node[n][i])
		{
			node[i][n]--;
            node[n][i]--;
			dfs(i);
		}
	}
	cout << n << " ";
}

int main() {
	
	scanf("%d",&N);
	
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=N; j++)
		{
			scanf(" %d",&node[i][j]);
		}
	}
	
	int have_answer = 1;
	for(int i=1; i<=N; i++)
	{
		int check_even = 0;
		for(int j=1; j<=N; j++)
		{
			check_even += node[i][j];
		}
		
		if(check_even%2 !=0)
		{
			have_answer = 0;
			cout<<-1;
			break;
		}
	}
	
	if(have_answer == 1)
	{
		dfs(1);
	}
	
	return 0;
}
