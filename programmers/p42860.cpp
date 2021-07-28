// greedy

#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <climits>
#include <cstdio>

using namespace std;

int solution(string name) {
    
    
    int answer = 0;
	
	int check[20] = {0};
	
	
	// 처음값이 'A'이더라도 시작점이기 때문에 들러야함.
	// 들르지 않아도 되는 값은 check값을 0, 들러야 하는 곳의 check값은 1
	// 각각의 알파벳을 만드는데 드는 비용을 미리 계산
	
	answer += min(abs(name[0]- 'A'), 26-abs(name[0]-'A'));
	for(int i=1; i<name.length(); i++)
	{
		if(name[i] == 'A')
		{
			check[i] = 0;
		}
		else
		{
			answer += min(abs(name[i]- 'A'), 26-abs(name[i]- 'A'));
			check[i] = 1;
		}		
	}

	// A부터 시작해서 check가 1인, 즉 값이 'A'가 아닌 가장 거리값이 작은 곳으로 이동
	int index = 0;
	while(1)
	{
		int local_min = name.length();
		int local_min_index = 0;
		
		for(int i=1; i<name.length(); i++)
		{
			if(check[i] == 0)
				continue;
			else
			{
				int first = abs(i - index);
				int second = name.length() - first;
				
				int min_length = min(first,second);
				if(min_length < local_min)
				{
					local_min = min_length;
					local_min_index = i;			
				}
			}
		}
		
		if(local_min_index == 0)
			break;
		else{
			answer+= local_min;
			index = local_min_index;
			check[local_min_index] = 0;
		}
	}
	
    return answer;
}

int main(void)
{
	printf("%d\n",solution("JEROEN"));
	return 0;
}
