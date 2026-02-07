#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    // Init
    vector<int> answer = {0, 0};
    set<string> s1 = {words[0]};
    string prev = words[0];
    
    // Process
    for(int i = 1; i < words.size(); i++)
    {
        string& word = words[i];
        int turn = i / n + 1;
        int personNo = i % n + 1;
        
        if(s1.find(word) != s1.end() || prev.back() != word[0])
        {
            answer = {personNo, turn};
            break;
        }
        
        s1.insert(word);
        prev = word;
    }
    
    return answer;
}