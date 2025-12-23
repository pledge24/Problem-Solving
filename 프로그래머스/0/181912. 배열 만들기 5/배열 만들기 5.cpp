#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

vector<int> solution(vector<string> intStrs, int k, int s, int l) {
    vector<int> answer;
    
    for(string& intStr : intStrs)
    {
        int64 num = stoll(intStr.substr(s, l));
        // cout << num << '\n';
        
        if(num > k)
            answer.push_back(num);
    }
    
    return answer;
}