#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    
    set<string> notHaveGemList;
    for(const string& gem : gems)
    {
        notHaveGemList.insert(gem);
    }
    
    map<string, int> gemMap;
    int e = 0;
    pair<int, int> minSeq = make_pair(0, 100000);
    int seqLen = 100000;
    for(int s = 0; s < gems.size(); s++)
    {
        while(e < gems.size() && !notHaveGemList.empty())
        {
            string& gem = gems[e];
            notHaveGemList.erase(gem);
            gemMap[gem]++;
            e++;
        }
        
        // cout << s << " " << e << '\n';
        // Evaluate minSeq.
        if(notHaveGemList.empty() && e - s < seqLen)
        {
            minSeq = make_pair(s, e-1);
            seqLen = e - s;
        }
        
        // Except s pos gem.
        gemMap[gems[s]]--;
        if(gemMap[gems[s]] == 0)
        {
            notHaveGemList.insert(gems[s]);
        }
    }
    
    answer = {minSeq.first+1, minSeq.second+1};
    
    return answer;
}