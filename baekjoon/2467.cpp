#include <iostream>
using namespace std;

int main(void) {
	
	long liq[100005] = {0};
	
	int pos_N = 0, neg_N=0;
	
	int N = 0;
	cin>> N;
	
	for(int i=0; i<N; i++)
	{
		cin >> liq[i];
		
		if(liq[i] < 0)
			neg_N++;
		else
			pos_N++;
	}
	
	int n_start = neg_N - 1, n_end = 0;
	int p_start = neg_N, p_end = N-1;
	
	long n_min = abs(liq[n_start-1] + liq[n_start]);
	long n_min_1 = liq[n_start-1];
	long n_min_2 = liq[n_start];
	
	long p_min = liq[neg_N] + liq[neg_N+1];
	long p_min_1 = liq[neg_N];
	long p_min_2 = liq[neg_N+1];
	
	long Min = abs(liq[n_start] + liq[p_start]);
	long Min_p = liq[p_start];
	long Min_n = liq[n_start];
	
	if(pos_N == 0)
		cout<<n_min_1<<" "<<n_min_2;
	else if(neg_N == 0)
		cout<<p_min_1<<" "<<p_min_2;
	else
	{
		int i = p_start;
		int j = n_start;
		
		while(1)
		{
			if(Min > abs(liq[i] + liq[j]))
			{
				Min = abs(liq[i] + liq[j]);
				Min_p = liq[i];
				Min_n = liq[j];
			}
			
			if(i == p_end)
			{
				if(j == n_end)
					break;
				else
					j--;
			}
			else if(j == n_end)
				i++;
				
			else
				liq[i]>abs(liq[j])? j-- : i++;
		}
		
		long n_p = min(n_min,p_min);
		long n_p_min = min(n_p,Min);
		
		
		if(n_p_min == Min)
			cout<<Min_n<<" "<<Min_p;
		else
		{
			if(n_p == n_min)
				cout<<n_min_1<<" "<<n_min_2;	
			else
				cout<<p_min_1<<" "<<p_min_2;
		}
	}
	
	return 0;
}
