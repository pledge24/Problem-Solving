#include <bits/stdc++.h>

using namespace std;

int solution(string s)
{
    int answer = 0;

    auto GetOddN = [&s](int start){
        int left = start - 1;
        int right = start + 1;
        
        int cnt = 1;
        while(0 <= left && right < s.length())
        {
            if(s[left] != s[right])
                break;
            
            cnt += 2;
            left--;
            right++;
        }
        
        return cnt;
    };
    
    auto GetEvenN = [&s](int start){
        int left = start;
        int right = start + 1;
        
        int cnt = 0;
        while(0 <= left && right < s.length())
        {
            if(s[left] != s[right])
                break;
            
            cnt += 2;
            left--;
            right++;
        }
        
        return cnt;
    };
    
    for(int i = 0; i < s.length(); i++)
    {
        int oddN = GetOddN(i);
        int evenN = GetEvenN(i);
        
        // cout << oddN << " " << evenN << '\n';
        
        answer = max({answer, oddN, evenN});
    }
    
    return answer;
}