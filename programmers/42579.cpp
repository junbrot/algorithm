#include <string>
#include <vector>
#include <utility>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    
    vector<int> answer;
    vector<string> sorted_genres;
    vector<vector<pair<int,int>>> music;
    vector<int> sum;
    int genre_cnt = 0;
    
    music.resize(100);
    
    for(int i=0; i<genres.size(); i++)
    {
        int genres_check = 0;
        for(int j=0; j<sorted_genres.size(); j++)
        {
            if(genres[i] == sorted_genres[j])
            {        
                music[j].push_back({i,plays[i]});
                sum[j] += plays[i];
                genres_check = 1;
                break;
            }
        }
        
        if(genres_check == 0)
        {
            music[genre_cnt++].push_back({i,plays[i]});
            sorted_genres.push_back(genres[i]);
            sum.push_back(plays[i]);
        }
    }
    
    
    for(int big = 0; big < genre_cnt; big++)
    {
        int cnt = 0;
        int max_sum = sum[0];

        for(int i=1; i<genre_cnt; i++)
        {
            if(sum[i] > max_sum)
            {
                max_sum = sum[i];
                cnt = i;
            }
        }
        
        sum[cnt] = 0;
        
        if(music[cnt].size() == 1)
            answer.push_back(music[cnt][0].first);
        else
        {
            for(int j=0; j<2; j++)
            {
                int biggest = 0;
                int biggest_loc = 0;
                int biggest_cnt = 0;

                for(int k=0; k<music[cnt].size(); k++)
                {
                    int target_loc = music[cnt][k].first;
                    int target_play = music[cnt][k].second;

                    if(biggest < target_play)
                    {
                        biggest = target_play;
                        biggest_loc = target_loc;
                        biggest_cnt = k;
                    }   
                    else if(biggest == target_play)
                    {
                        if(biggest_cnt > target_loc)
                        {
                            biggest_loc = target_loc;
                            biggest_cnt = k;
                        }
                    }
                }
                music[cnt][biggest_cnt].second = 0;                
                answer.push_back(biggest_loc);            
            }
        }

    }
  
    return answer;
}
