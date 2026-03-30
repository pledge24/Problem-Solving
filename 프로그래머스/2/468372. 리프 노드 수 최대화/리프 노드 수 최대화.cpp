#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

int GetMaxLeafs(int n2, int n3, int leftDist)
{
    int W = 1;  // 리프노드 크기
    
    for(int i = 0; i < n2; i++)
    {
        if(leftDist < W /* r+1 */)
        {
            return W + leftDist;
        }
        
        leftDist -= W;
        W *= 2;
    }
    
    for(int j = 0; j < n3; j++)
    {
        if(leftDist < W)
        {
            return W + leftDist*2;
        }
        
        leftDist -= W;
        W *= 3;
    }
    
    return W;
}

int solution(int dist_limit, int split_limit) {
    int answer = 0;
     
    int64 splitVal = 1;
    for(int i = 0; splitVal <= split_limit; i++)
    {
        int j = 0;
        int64 temp = splitVal;
        while(temp * 3 <= split_limit)
        {
            temp *= 3;
            j++;
        }
        
        // Process.
        int leafs = GetMaxLeafs(i, j, dist_limit);
        answer = max(answer, leafs);
        // printf("i: %d, j: %d, leafs: %d\n", i, j, leafs);
        
        // Update
        splitVal *= 2;
    }
    
    return answer;
}