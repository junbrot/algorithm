#include <stdio.h>

int main(void) {
	
	int n,d,k,c;
	scanf("%d %d %d %d",&n,&c,&k,&c);
	
	int p[30000] = {0};
	int num_d[3001] = {0};
	
	for(int i=0; i<n; i++)
		scanf("%d",&p[i]);

	int max_cnt = 0;
	int temp_cnt = 0;
	
	for(int i=0; i<n; i++)
	{
		int temp_cnt_2 = 0;

		if(i == 0)
		{
			for(int j=0; j<k; j++)
			{
				if(num_d[p[j]] == 0)
				{
					num_d[p[j]] = 1;
					temp_cnt++;
				}
				else
					num_d[p[j]] += 1;
			}
			
			temp_cnt_2 = temp_cnt;
			
			if(num_d[c] == 0)
				temp_cnt_2++;
			
			max_cnt = temp_cnt_2;
		}
		else
		{
			int check_i = (i+k-1) % n;
			
			if(num_d[p[i-1]] > 1)
				num_d[p[i-1]] -= 1;
				
			else if(num_d[p[i-1]] == 1)
			{
				num_d[p[i-1]] = 0;
				temp_cnt--;
			}
			
			if(num_d[p[check_i]] == 0)
			{
				num_d[p[check_i]] = 1;
				temp_cnt++;
			}
			else
				num_d[p[check_i]] += 1;
			
			temp_cnt_2 = temp_cnt;
			
			if(num_d[c] == 0)
				temp_cnt_2++;
			
			if(temp_cnt_2 > max_cnt)
				max_cnt = temp_cnt_2;
		}
	}
	
	printf("%d",max_cnt);
	return 0;
}
