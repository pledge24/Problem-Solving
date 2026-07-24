#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    std::sort(routes.begin(), routes.end(), [](vector<int>& r1, vector<int>& r2){
        if(r1[0] == r2[0])
            return r1[1] > r2[1];
        
        return r1[0] < r2[0];
    });
    
    int maxOut = routes[0][1];
    answer++;   // 설치하고 시작.
    for(int i = 1; i < routes.size(); i++)
    {
        vector<int>& r = routes[i];
        int in = r[0];
        int out = r[1];
        
        if(in > maxOut)
        {
            maxOut = out;
            answer++;
        }
        
        maxOut = min(maxOut, out);
    }
    
    return answer;
}