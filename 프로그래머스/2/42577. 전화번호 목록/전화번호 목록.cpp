#include <bits/stdc++.h>

using namespace std;

const int DIGITS = 10;

struct Node
{
    bool isEnd = false;
    vector<Node*> next = vector<Node*>(DIGITS, nullptr);
};

bool Insert_And_Check(Node* cur, string& s)
{
    bool hasPrefix = false;
    
    for(char c : s)
    {
        int digit = c - '0';
        if(cur->next[digit] == nullptr)
        {
            cur->next[digit] = new Node();
        }
        
        if(cur->next[digit]->isEnd)
            hasPrefix = true;
        
        cur = cur->next[digit];
    }
    
    cur->isEnd = true;
    for(int i = 0; i < DIGITS; i++)
    {
        Node* node = cur->next[i];
        if(node != nullptr)
            hasPrefix = true;
    }
    
    return hasPrefix;
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end(), [](string& s1, string& s2){
        return s1.length() < s2.length();
    });
    
    Node root;
    for(string& s : phone_book)
    {
        bool hasPrefix = Insert_And_Check(&root, s);
        if(hasPrefix)
        {
            answer = false;
            break;
        }    
    }
    
    return answer;
}