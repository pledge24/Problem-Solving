#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> signals) {
    int answer = -1;
    
    int sigN = signals.size();
    vector<int> terms;
    for(int i = 0; i < sigN; i++)
    {
        vector<int>& signal = signals[i];
        int term = signal[0] + signal[1] + signal[2];
        
        terms.push_back(term);
    }
    
    int maxTerm = 1;
    for(int elem : terms)
    {
        maxTerm *= elem;
    }
    
    
    vector<int> yellowCnt(maxTerm, 0);
    for(int i = 0; i < sigN; i++)
    {
        vector<int>& signal = signals[i];
        int term = signal[0] + signal[1] + signal[2];
        int green = signal[0];
        int yellow = signal[1];
        
        for(int j = green; j < maxTerm; j+=term)
        {
            for(int k = 0; k < yellow; k++)
            {
                yellowCnt[j+k]++;
                if(yellowCnt[j+k] == sigN)
                    return j+k+1;
            }
        }
    }
    
    return answer;
}