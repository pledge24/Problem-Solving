#include <bits/stdc++.h>

using namespace std;

void DrawGraph(int k, vector<int>& graph)
{
    while(k > 1)
    {
        graph.push_back(k);
        
        if(k % 2 == 0)
            k /= 2;
        else 
            k = 3*k + 1;
    }
    graph.push_back(1);
}

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    
    // draw graph
    vector<int> graph;
    DrawGraph(k, graph);
    
    // calc area
    vector<double> areas;
    for(int i = 0; i < graph.size(); i++)
    {
        if(i == 0)
        {
            areas.push_back(0);
            continue;
        }
        
        int prevH = graph[i-1];
        int curH = graph[i];
        
        double unit_area = max(prevH, curH) - abs(prevH - curH) / 2.f;
        areas.push_back(areas[i-1] + unit_area);
    }
    
    int n = graph.size() - 1;
    for(const vector<int>& rn : ranges)
    {
        int start = rn[0];
        int end = n + rn[1];
        
        if(start > end)
        {
            answer.push_back(-1);
            continue;
        }
        
        double area = areas[end] - areas[start];
        answer.push_back(area);
    }
    
    return answer;
}