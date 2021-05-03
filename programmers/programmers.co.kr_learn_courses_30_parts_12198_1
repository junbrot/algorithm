#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    
    vector<int> answer;
    
    for(int i=0; i<commands.size();i++)
    {
    	vector<int> temp;
    	
    	for(int j=commands[i][0]-1; j<commands[i][1]; j++)
    		temp.push_back(array[j]);
   
	 	sort(temp.begin(),temp.end());
    	answer.push_back(temp[commands[i][2]-1]);
    }	
    
    return answer;
}

int main() {
	
	int N;
	scanf("%d",&N);
	
	vector<int> a(N,0);

	for(int i=0; i<N; i++)
		scanf("%d",&a[i]);
	
	scanf("%d",&N);
	vector<vector<int>> commands(N,vector<int>(3,0));

	for(int i=0; i<N; i++)
		scanf("%d %d %d",&commands[i][0],&commands[i][1],&commands[i][2]);
		
	vector<int> sol = solution(a,commands);
	printf("%d %d %d\n",sol[0],sol[1],sol[2]);
	
	return 0;
}
