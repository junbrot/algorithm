#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool compare(string a, string b)
{
	if(a.size() == b.size())
		return a < b;
	else
		return a.size() < b.size();
}

int main() {

	vector<string> arr;
	int num;
	
	scanf("%d",&num);
	for(int i=0; i<num; i++)
	{
		string a;
		cin>>a;
		arr.push_back(a);
	}
	
	vector<string> arr2;
	for(int i=0; i<num; i++)
	{
		int flag = 0;
		for(int j=i+1; j<num; j++)
		{
			if(arr[i] == arr[j])
			{	
				flag = 1;
				break;
			}
		}
		if(flag == 0)
			arr2.push_back(arr[i]);
	}
	
	sort(arr2.begin(),arr2.end(),compare);
	
	for(int i=0; i<arr2.size(); i++)
	{
		for(int j=0; j<arr2[i].size(); j++)
			printf("%c",arr2[i][j]);
		printf("\n");
	}
	return 0;
}
