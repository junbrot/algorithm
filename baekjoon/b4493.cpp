#include <iostream>
using namespace std;

int main() {
	
	int total=0;
	
	cin>>total;
	
	for(int i=0; i<total;i++)
	{
		int win_lose = 0;
		int cnt = 0;
		cin>>cnt;
		
		char left,right;
		int l,r;
		
		for(int j=0; j<cnt; j++)
		{
			cin>>left>>right;
			
			l = (int(left%'Q'))%80;
			r = (int(right%'Q'))%80;
			
			if(l == r)
				continue;
			else if((l+1)%3 == r)
				win_lose++;
			else
				win_lose--;
		}
		
		
		if(win_lose == 0)
			cout<<"TIE"<<'\n';
		else if(win_lose > 0)
			cout<<"Player 1"<<'\n';
		else
			cout<<"Player 2"<<'\n';
	}
  
  return 0;
}
