#include <iostream>
#include <functional>
#include <queue>

using namespace std;

int main() {
	
	priority_queue< int, vector<int>, greater<int> > pq;
	
	int N;
	scanf("%d",&N);
	
	for(int i=0; i<N; i++)
	{
		int temp;
		scanf("%d",&temp);
			
		if(temp == 0)
		{
			if(pq.empty())
				cout<<0<<'\n';
			else
			{
				cout<<pq.top()<<'\n';
				pq.pop();
			}		
		}
		else
			pq.push(temp);
	}
	return 0;
}
