#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int unit = 2*w+1;
    for(int i = 1; i < stations.size(); i++)
    {
        int prev = stations[i-1];
        int cur = stations[i];
        
        int distance = cur - prev - 1;
        if(distance > 2*w)
        {
            int emptyDist = distance - 2*w;
            // cout << prev << ' ' << cur << ' ' << emptyDist << '\n';
            answer += emptyDist / unit + (emptyDist % unit > 0);
        }
    }

    // process edge.
    int leftDist = stations.front() - 1 - w;
    int rightDist = n - stations.back() - w;
    
    // cout << leftDist << ' ' << rightDist << '\n';
    
    if(leftDist > 0)
        answer += leftDist / unit + (leftDist % unit > 0);
    
    if(rightDist > 0)
        answer += rightDist / unit + (rightDist % unit > 0);
    
    return answer;
}