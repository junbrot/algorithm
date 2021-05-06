#include <stdio.h>
#include <string.h>

int spinspin(char(*a)[64],int i_start, int i_end, int j_start, int j_end)
{
	int i,j;
	for(i = i_start; i<i_end; i++)
	{
		for(j = j_start; j<j_end; j++)
		{
			if(a[i][j]!=a[i_start][j_start])
				return 1;
		}
	}
	return 0;
}

void spin(char(*a)[64],int i_s, int i_e, int j_s, int j_e, char* answer)
{
	int i_start = i_s;
	int i_end = i_e;
	int i_mid = (i_s + i_e)/2;
	
	int j_start = j_s;
	int j_end = j_e;
	int j_mid = (j_s + j_e)/2;
	
	char temp[10000] = {0};
	temp[0] = '(';
	
	if(spinspin(a,i_start,i_mid,j_start,j_mid) == 1)
	{
		spin(a,i_start,i_mid,j_start,j_mid,temp);
	}
	else
		temp[strlen(temp)] = a[i_start][j_start];
	
	if(spinspin(a,i_start,i_mid,j_mid,j_end) == 1)
	{
		spin(a,i_start,i_mid,j_mid,j_end,temp);
	}
	else
		temp[strlen(temp)] = a[i_start][j_mid];
	
	if(spinspin(a,i_mid,i_end,j_start,j_mid) == 1)
	{
		spin(a,i_mid,i_end,j_start,j_mid,temp);
	}
	else
		temp[strlen(temp)] = a[i_mid][j_start];
		
	if(spinspin(a,i_mid,i_end,j_mid,j_end) == 1)
	{
		spin(a,i_mid,i_end,j_mid,j_end,temp);
	}
	else
		temp[strlen(temp)] = a[i_mid][j_mid];
	
	temp[strlen(temp)] = ')';
	strcat(answer,temp);
}

int main() {
	
	char a[64][64] = {0};
	char answer[10000] = {0};
	
	int N = 0;
	scanf("%d",&N);
	
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
			scanf(" %c",&a[i][j]);
	}
	
	char check = a[0][0];
	int flag = 0;
	for(int i=0; i<N ;i++)
	{
		for(int j=0; j<N; j++)
		{
			if(check != a[i][j])
			{	
				flag = 1;
				break;
			}
		}
	}
	
	
	if(flag == 0)
		printf("%c",a[0][0]);
	else
	{
		spin(a,0,N,0,N,answer);	
		printf("%s",answer);
	}
	return 0;
}
