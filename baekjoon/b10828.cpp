#include <iostream>
#include <vector>
using namespace std;

int num;
int stack[100000] = {0};
int t = -1;

void push(int b){
	
	if(t < num)
		stack[++t] = b;
}

void pop(){
	
	if(t>=0)
		cout << stack[t--] << '\n';
	else
		cout << -1 << '\n';
}

void empty()
{
	if(t >= 0)
		cout << 0 <<'\n';
	else
		cout << 1 << '\n';
}


void top(){
	
	if(t >= 0)
		cout << stack[t] << '\n';
	else
		cout << -1 << '\n';
}

void size(){

	cout<<t+1<<'\n';
}

int main() {
	

	cin >> num;
	
	while(1)
	{
		string a = "";
		int b = 0;
	
		cin >>a;
		
		if(a.empty())
			break;
		
		if(a == "push")
		{
			cin >> b;
			if(b > 0)
			{
				push(b);
			}
		}
		else if (a == "pop")
		{
			pop();
		}
		else if (a == "size")
		{
			size();	
		}
		else if (a == "empty")
		{
			empty();	
		}
		else if (a == "top")
		{
			top();
		}
	}
	return 0;
}
