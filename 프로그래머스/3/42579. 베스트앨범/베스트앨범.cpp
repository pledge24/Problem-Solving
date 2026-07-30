#include <bits/stdc++.h>

using namespace std;
using GenresData = pair<int, vector<pair<int, int>>>; // <총 재생횟수, <id, cnt>>
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    // 장르 별로 가장 많이 재생된 2개의 노래 index 출력.
    map<string, GenresData> m1;
    int N = genres.size();
    for(int i = 0; i < N; i++)
    {
        string g = genres[i];
        int p = plays[i];
        
        m1[g].first += p;
        m1[g].second.push_back(make_pair(i, p));
    }
    
    vector<vector<int>> res;
    for(auto p : m1)
    {
        // GenresData = pair<int, vector<pair<int, int>>>; // <총 재생횟수, <id, cnt>>
        GenresData& md = p.second;
        int totalPlay = md.first;
        vector<pair<int, int>>& musicList = md.second;
        
        std::sort(musicList.begin(), musicList.end(), [](auto p1, auto p2){
            if(p1.second == p2.second)
                p1.first < p2.first;
            
            return p1.second > p2.second;
        });
                  
        for(int i = 0; i < std::min(2, (int)musicList.size()); i++)
        {
            pair<int, int> music = musicList[i];
            res.push_back({totalPlay, music.second, music.first});
        }
    }
    
    std::sort(res.begin(), res.end(), [](auto v1, auto v2){
        if(v1[0] != v2[0])
            return v1[0] > v2[0];
        
        if(v1[1] != v2[1])
            return v1[1] > v2[1];
        
        return v1[2] < v2[2];
    });
    
    for(int i = 0; i < res.size(); i++)
        answer.push_back(res[i][2]);
    
    return answer;
}