#include <bits/stdc++.h>

using namespace std;

int solution(string message, vector<vector<int>> spoiler_ranges) {
    int answer = 0;
    
    // 스포일러 단어랑 아닌 단어를 구분하자.
    vector<bool> blind(message.length());
    for(vector<int> rng : spoiler_ranges)
    {
        int s = rng[0];
        int e = rng[1];
        for(int i = s; i <= e; i++)
        {
            blind[i] = true;
        }
    }
    
    // string checkStr = "";
    // for(int i = 0; i < message.length(); i++)
    // {
    //     checkStr += blind[i] ? '_' : message[i];
    // }
    // cout << checkStr << '\n';
    
    vector<string> closeWord;
    set<string> openWord;
    
    string temp = "";
    bool blinded = false;
    for(int i = 0; i < message.length(); i++)
    {
        char c = message[i];
        
        if(c != ' ')
        {
            temp += c;
            if(blind[i])
                blinded = true;
        }
        else
        {
            if(blinded)
                closeWord.push_back(temp);
            else
                openWord.insert(temp);
            
            temp = "";
            blinded = false;
        }
    }
    
    // Last Check.
    {
        if(blinded)
            closeWord.push_back(temp);
        else
            openWord.insert(temp);
    }
    
//     for(string str : closeWord)
//         cout << str << ' ';
//     cout << '\n';
    
//     cout << "============================\n";
    
//     for(string str : openWord)
//     {
//         cout << str << ' ';
//     }
//     cout << '\n';
    
//     cout << "============================\n";
    
    for(string str : closeWord)
    {
        if(openWord.find(str) == openWord.end())
        {
            // cout << str << '\n';
            openWord.insert(str);
            answer++;
        }
    }
    return answer;
}