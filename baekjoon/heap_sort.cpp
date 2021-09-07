#include <iostream>
#include <vector>

using namespace std;

vector<int> sorted;

void merge(vector<int> &list, int left, int mid, int right)
{
	int front_index = left;
	int back_index = mid+1;
	int sorted_index = left;
	
	while(front_index <= mid && back_index <= right)
	{
		if(list[front_index] < list[back_index])
			sorted[sorted_index++] = list[front_index++];
		else
			sorted[sorted_index++] = list[back_index++];
	}
	
	if(front_index > mid)
	{
		for(int i=back_index; i<=right; i++)
			sorted[sorted_index++] = list[i];
	}
	else
	{
		for(int i=front_index; i<=mid; i++)
			sorted[sorted_index++] = list[i];
	}
	
	for(int i=left; i<=right; i++)
		list[i] = sorted[i];
}

void merge_sort(vector<int> &list, int left, int right)
{
	int mid;
	if(left < right)
	{
		mid = (left + right)/2;
		merge_sort(list,left,mid);
		merge_sort(list,mid+1,right);
		merge(list,left,mid,right);
	}
}

int main(void)
{
	int n=8;
	vector<int> list = {21,10,12,20,25,13,15,22};
	sorted.resize(8);
	
	merge_sort(list,0,7);
	
	for(int i=0;i<n; i++)
	{
		printf("%d\n",list[i]);	
	}
}
