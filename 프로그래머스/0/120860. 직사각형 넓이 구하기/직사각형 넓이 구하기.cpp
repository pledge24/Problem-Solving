#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> dots) {
    int answer = 0;
    
    std::sort(dots.begin(), dots.end());
    
    vector<int>& point1 = dots.front();
    vector<int>& point2 = dots.back();
    
    answer = abs(point1[0] - point2[0]) * abs(point1[1] - point2[1]);
    
    return answer;
}