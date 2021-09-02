#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    priority_queue<int> upper;
    
    priority_queue<int,vector<int>,greater<int>> lower;
    int cnt = 0;
    
    for(int i=0; i<operations.size(); i++)
    {
        if(operations[i][0] == 'I')
        {   
            upper.push(stoi(operations[i].substr(2,operations[i].length()-2)));
            lower.push(stoi(operations[i].substr(2,operations[i].length()-2)));
            cnt++;
        }
        else if(operations[i][0] == 'D' && cnt > 0)
        {
            if(operations[i][2] == '-')
            {
                lower.pop();
            }
            else
            {
                upper.pop();
            }
            cnt--;
        }
        
        if(cnt == 0)
        {
            while(!upper.empty())
                upper.pop();
            while(!lower.empty())
                lower.pop();
        }
    }
    
    if(cnt == 0)
    {
         answer.push_back(0);
         answer.push_back(0);
    }   
    else
    {
        answer.push_back(upper.top());
        answer.push_back(lower.top());
    }
        
    return answer;
}
