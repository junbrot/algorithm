#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

bool compare(pair<int,int> a, pair<int,int> b)
{
	return a.first < b.first;
}

bool compare2(pair<int,int> a, pair<int,int> b)
{
	return a.second < b.second;
}

int main() {
	
	int n;
	vector<pair<int,int>> arr;
	
	cin>>n;
	for(int i=0; i<n; i++)
	{
		int front;
		
		scanf("%d",&front);
		arr.push_back({front,i});
	}
	
	stable_sort(arr.begin(),arr.end(),compare);
	
	vector<int> answer;
	answer.push_back(0);
	
	for(int i=1; i<n; i++)
	{
		if(arr[i-1].first == arr[i].first)
			answer.push_back(answer[i-1]);
		else
			answer.push_back(answer[i-1] + 1);
	}

	for(int i=0; i<n; i++)
		arr[i].first = answer[i];

	stable_sort(arr.begin(),arr.end(),compare2);
	
	for(int i=0; i<n; i++)
		cout<<arr[i].first<<' ';

	return 0;
}

