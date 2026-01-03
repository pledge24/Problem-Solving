#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

void fillJobList(int cap, int n, vector<int>& originList, vector<int64>& jobList)
{   
    int maxDist = n;
    int boxN = 0;
    for(int i = n-1; i >= 0; i--)
    {
        int dist = i+1;
        if(boxN == 0)
            maxDist = dist;
        
        boxN += originList[i];
        int jobN = boxN / cap;
        
        if(jobN > 0)
        {
            jobList[maxDist]++;
            maxDist = dist;
            jobList[dist] += (jobN-1);
            
            boxN %= cap;
        }
    }
    
    if(boxN > 0)
    {
        jobList[maxDist]++;
    }
    
    // for(int elem : jobList)
    //     cout << elem << ' ';
    // cout << '\n';
}

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = -1;
    vector<int64> deliverJob(n+1, 0);
    vector<int64> pickupsJob(n+1, 0);
    
    // fill JobList
    fillJobList(cap, n, deliveries, deliverJob);
    fillJobList(cap, n, pickups, pickupsJob);
    
    int dDist = n;
    int pDist = n;
    int64 minDist = 0;
    while(dDist + pDist > 0)
    {
        while(deliverJob[dDist] == 0 && dDist > 0) dDist--;
        while(pickupsJob[pDist] == 0 && pDist > 0) pDist--;
        
        minDist += max(dDist, pDist) * 2;
        // cout << "Dist: " << max(dDist, pDist) << '\n';
        
        deliverJob[dDist] = max(deliverJob[dDist]-1, (int64)0);
        pickupsJob[pDist] = max(pickupsJob[pDist]-1, (int64)0);
    }
    
    answer = minDist;
    
    return answer;
}