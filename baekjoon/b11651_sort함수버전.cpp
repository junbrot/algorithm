#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstdio>
using namespace std;

vector<pair<int,int>> arr;

bool compare(pair<int,int> &one, pair<int,int> &two)
{

// 	if(one.second == two.second)
// 		return one.first < two.first;
// 	else
// 		return one.second < two.second;
	
	if(one.second > two.second)
		return 0;
	else if(one.second < two.second)
	{
		return 1;
	}
	else
	{
		if(one.first > two.first)
			return 0;
		else
			return 1;
	}
}

int main() {
	
	int num = 0;
	scanf("%d",&num);
	
	for(int i=0; i<num; i++)
	{
		int front,back;
		scanf(" %d %d",&front,&back);
		
		arr.push_back({front,back});
	}
	
	sort(arr.begin(), arr.end(), compare);
	
	for(int i=0; i<num; i++)
		cout<<arr[i].first<<' '<<arr[i].second<<endl;
	
	return 0;
}
