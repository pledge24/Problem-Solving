#include <bits/stdc++.h>

using namespace std;

// 도시 이름을 검색 -> 해당 도시의 맛집 게시물을 제시
// 성능 측정 -> 게시물을 가져오는 시간이 너무 오래 걸림
// DB 캐시 적용을 결정
// 캐시 크기에 따른 실행시간 측정 프로그램?
// Hit cost = 1, Miss cost = 5
int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    map<string, int> m1;
    int totalCost = 0;
    for(int i = 0; i < cities.size(); i++)
    {
        // Fitting
        string city = "";
        for(char c : cities[i])
        {
            city += tolower(c);
        }
        
        // Hit
        if(m1.find(city) != m1.end())
        {
            totalCost += 1;
            m1[city] = i;
            
            // cout << i << " " << city << '\n';
            continue;
        }
        
        // Miss
        totalCost += 5;

        if(cacheSize == 0)
        {
            continue;
        }
        
        // Miss Method 1 : Add
        if(m1.size() < cacheSize)
        {
            m1[city] = i;
        }
        // Miss Method 2 : Replace
        else
        {
            string target = "";
            int usedN = numeric_limits<int>::max();
            for(auto& p : m1)
            {
                if(p.second < usedN)
                {
                    target = p.first;
                    usedN = p.second;
                }
            }

            // cout << i << " removed: " << target << '\n';
            // cout << usedN << '\n';
                
            m1.erase(target);
            m1[city] = i;
        }
        
        
    }
    
    answer = totalCost;
    
    return answer;
}