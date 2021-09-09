#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<char> sorted_arr;

void merge(vector<char> &arr, int start, int mid, int end)
{
	int front_ind = start;
	int back_ind = mid+1;
	int sorted_ind = start;
	
	while((front_ind<=mid)&&(back_ind<=end))
	{
		if(arr[front_ind] > arr[back_ind])
			sorted_arr[sorted_ind++] = arr[front_ind++];
		else
			sorted_arr[sorted_ind++] = arr[back_ind++];
	}
	
	if(front_ind > mid)
	{
		for(int i=back_ind; i<=end; i++)
			sorted_arr[sorted_ind++] = arr[i];
	}
	else
	{
		for(int i=front_ind; i<=mid; i++)
			sorted_arr[sorted_ind++] = arr[i];	
	}
	
	for(int i=start; i<=end; i++)
		arr[i] = sorted_arr[i];
	
}

void merge_sort(vector<char> &arr, int start, int end)
{
	if(start < end)
	{
		int mid = (start + end)/2;
		merge_sort(arr, start, mid);
		merge_sort(arr, mid+1, end);
		merge(arr,start,mid,end);
	}
}


int main() {
	
	vector<char> arr;
	string num = "";
	cin>>num;
	
	int len = num.size();
	for(int i=0; i<len; i++)
	{
		arr.push_back(num[i]);
	}
	
	sorted_arr.resize(len);
	merge_sort(arr,0,len-1);
	
	for(int i=0; i<len;i++)
		cout<<arr[i];
	
	return 0;
}
