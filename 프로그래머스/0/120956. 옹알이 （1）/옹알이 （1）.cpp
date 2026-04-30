#include <bits/stdc++.h>

using namespace std;

// 최대 1번 등장. 순서 고려. -> 다 구하고 하려면 DFS 사용 필요.
// 부분 포함이 있지는 않음.
int solution(vector<string> babbling) {
    int answer = 0;
    array<string, 4> babList = {"aya", "ye", "woo", "ma"};
    
    for(const string& babStr : babbling)
    {
        string temp = "";
        for(char c : babStr)
        {
            temp += c;
            if(find(babList.begin(), babList.end(), temp) != babList.end())
            {
                temp = "";
            }
        }
        
        // Last Check.
        if(find(babList.begin(), babList.end(), temp) != babList.end())
        {
            temp = "";
        }
        
        if(temp == "")
            answer++;
    }
    
    return answer;
}