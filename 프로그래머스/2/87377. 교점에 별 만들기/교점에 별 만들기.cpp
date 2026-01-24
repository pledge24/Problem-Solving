#include <bits/stdc++.h>

using namespace std;
using Pos = pair<double, double>;
using int64 = long long;

const int64 INF = numeric_limits<int64>::max();

bool GetCrossPoint(Pos& outPos, vector<int>& l1, vector<int>& l2)
{
    double a1 = l1[0];
    double b1 = l1[1];
    double c1 = l1[2];
    
    double a2 = l2[0];
    double b2 = l2[1];
    double c2 = l2[2];
    
    if(a1*b2 - a2*b1 == 0)
    {
        // cout << "check" << '\n';
        return false;
    }
    
    double px = (b1*c2 - b2*c1) / (a1*b2 - a2*b1);
    double py = (c1*a2 - c2*a1) / (a1*b2 - a2*b1);
    
    outPos = make_pair(px, py);
    
    return true;
}

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    set<Pos> cpList;
    
    Pos maxPoint = make_pair(-INF, -INF);
    Pos minPoint = make_pair(INF, INF);
    for(int i = 0; i < line.size(); i++)
    {
        vector<int>& l1 = line[i];
        for(int j = i+1; j < line.size(); j++)
        {
            vector<int>& l2 = line[j];
            
            Pos cp = make_pair(0, 0);
            if(GetCrossPoint(cp, l1, l2) == false)
                continue;
            
            // 소수점이 있다면 pass
            if(cp.first != static_cast<int64>(cp.first) || cp.second != static_cast<int64>(cp.second))
            {
                continue;
            }
            
            cpList.insert(cp);
            
            // calc boundary
            maxPoint = make_pair(max(maxPoint.first, cp.first), max(maxPoint.second, cp.second));
            minPoint = make_pair(min(minPoint.first, cp.first), min(minPoint.second, cp.second));
        }
    }
    
    // cout << "maxPoint: " << maxPoint.first << " " << maxPoint.second << '\n';
    // cout << "minPoint: " << minPoint.first << " " << minPoint.second << '\n';
    
    int64 rows = maxPoint.second - minPoint.second + 1;
    int64 cols = maxPoint.first - minPoint.first + 1;
    int64 offsetX = -minPoint.first;
    int64 offsetY = -minPoint.second;
    
    string str(cols, '.');
    for(int i = 0; i < rows; i++)
    {
        answer.push_back(str);
    }
    
    for(Pos pos : cpList)
    {
        int64 px = pos.first;
        int64 py = pos.second;
        
        // cout << px + offsetX << " " << py + offsetY << '\n';
        answer[(rows-1) - (py + offsetY)][px + offsetX] = '*';
    }
    
    // for(int i = 0; i < rows; i++)
    // {
    //     cout << answer[i] << '\n';
    // }
    
    return answer;
}