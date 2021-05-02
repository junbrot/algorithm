#include <iostream>
using namespace std;

int arr_len = 0;

void print_arr(int* arr)
{
	cout<<arr[0]<<'\n';
	
	int loc = 0;
	int aft_loc_l = 1;
	int aft_loc_r = 2;
	arr[0] = arr[arr_len-1];
	
	while(1)
	{
		if(aft_loc_r > arr_len -1)
			break;
		
		int min_lr = min(arr[aft_loc_r],arr[aft_loc_l]);
		if(arr[loc] <= min_lr)
			break;
		else
		{
			if(min_lr == arr[aft_loc_r])
			{
				int temp = arr[loc];
				arr[loc] = arr[aft_loc_r];
				arr[aft_loc_r] = temp;
				loc = aft_loc_r;
			}
			else
			{
				int temp = arr[loc];
				arr[loc] = arr[aft_loc_l];
				arr[aft_loc_l] = temp;
				loc = aft_loc_l;
			}
	
			aft_loc_r = (loc+1)*2;
			aft_loc_l = aft_loc_r-1;
		}
	}
	arr_len--;
}

void input_arr(int* arr)
{
	int loc = arr_len;

	while(1)
	{
		if(loc == 0)
			break;
		else
		{
			if(arr[(loc-1)/2] > arr[loc])
			{
				int temp = arr[loc];
				arr[loc] = arr[(loc-1)/2];
				arr[(loc-1)/2] = temp;
				loc = (loc-1)/2;
			}
			else
				break;
		}
	}
	
	arr_len++;
}


int main() {
	
	int N;
	int arr[100000] = {0};
	
	cin >> N;
	
	for(int i=0; i<N; i++)
	{
		int temp;
		scanf("%d",&temp);
			
		if(temp == 0)
		{
			if(arr_len == 0)
				cout<<0<<'\n';
			else
				print_arr(arr);
		}
		else
		{
			arr[arr_len] = temp;
			input_arr(arr);
		}
	}
	
	return 0;
}
