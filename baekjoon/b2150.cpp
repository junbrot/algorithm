// SCC 코사라주 알고리즘

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int V,E;

vector<vector <int>> node;
vector<vector <int>> back_node;

int vis[10001];
int vis2[10001];

vector<int> stack;
vector<vector<int>> ans;

void dfs(int startNode){
	
	vis[startNode] = 1;
	for(int i=0; i<node[startNode].size(); i++)	
	{
		int nextNode = node[startNode][i];
		if(vis[nextNode] == 0)
			dfs(nextNode);
	}
	stack.push_back(startNode);
}

void dfs2(int startNode, vector<int> *v){
	
	vis2[startNode] = 1;
	
	for(int i=0; i<back_node[startNode].size(); i++)	
	{
		int nextNode = back_node[startNode][i];
		if(vis2[nextNode] == 0)
			dfs2(nextNode,v);
	}
	
	(*v).push_back(startNode);
}

int main() {
	
	scanf("%d %d",&V,&E);
	
	node.resize(V+1);
	back_node.resize(V+1);
	
	for(int i=1; i<=E; i++)
	{
		int f,b;
		scanf(" %d %d",&f,&b);
		node[f].push_back(b);
		back_node[b].push_back(f);
	}
	
	for(int i=1; i<=V; i++)
	{
		if(vis[i] == 0)
			dfs(i);
	}

	for(int i=stack.size()-1; i>=0; i--)
	{
		int node = stack[i];
		if(vis2[node] == 0)
		{
			vector<int> temp;
			dfs2(node,&temp);
			ans.push_back(temp);
		}
	}
	
	for(int i=0; i<ans.size(); i++)
		sort(ans[i].begin(),ans[i].end());
	sort(ans.begin(),ans.end());
	
	cout<<ans.size()<<endl;
	for(int i=0; i<ans.size(); i++)
	{
		for(int j=0; j<ans[i].size(); j++)
			cout<<ans[i][j]<<' ';
		cout<<-1<<endl;
	}

	return 0;
}
