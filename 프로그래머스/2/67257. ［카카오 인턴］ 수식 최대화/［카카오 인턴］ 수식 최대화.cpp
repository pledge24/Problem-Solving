#include <bits/stdc++.h>

#define OUT

using namespace std;
using int64 = long long;

vector<vector<char>> priorities =
{
    {'*', '+', '-'},
    {'*', '-', '+'},
    {'+', '*', '-'},
    {'+', '-', '*'},
    {'-', '+', '*'},
    {'-', '*', '+'}
};

int64 Calc(int64 oper1, int64 oper2, char op)
{
    switch(op)
    {
        case '*':
            {
                return oper1 * oper2;
            }
        case '+':
            {
                return oper1 + oper2;
            }
        case '-':
            {
                return oper1 - oper2;
            }
    }
    
    return oper1;
}

void ProcessOp(vector<int64>& numList, vector<char>& opList, char targetOp)
{
    vector<int64> xNumList;
    vector<char> xOpList;
    
    int64 curNum = numList[0];
    for(int i = 0; i < opList.size(); i++)
    {
        if(opList[i] == targetOp)
        {
            curNum = Calc(curNum, numList[i+1], targetOp);
        }
        else
        {
            xNumList.push_back(curNum);
            xOpList.push_back(opList[i]);
            curNum = numList[i+1];
        }
    }
    
//     for(int elem : xNumList)
//     {
//         cout << elem << ' ';
//     }
//     cout << '\n';

//     for(char c : xOpList)
//     {
//         cout << c << ' ';
//     }
//     cout << '\n';
    
    std::swap(numList, xNumList);
    std::swap(opList, xOpList);
}

long long solution(string expression) {
    long long answer = 0;
    
    expression += "."; // add dummy;
    
    vector<int64> numList;
    vector<char> opList;
    
    string strNum = "";
    for(char c : expression)
    {
        if(isdigit(c))
            strNum += c;
        else
        {
            numList.push_back(stoi(strNum));
            opList.push_back(c);
            
            strNum = "";
        }
    }
    
    int64 maxScore = 0;
    for(vector<char>& pList : priorities)
    {
        vector<int64> nL = numList;
        vector<char> oL = opList;
        
        for(char op : pList)
        {
            ProcessOp(OUT nL, OUT oL, op);
            
        }
        
        maxScore = max(maxScore, abs(nL[0]));
    }
    
    answer = maxScore;
    
    return answer;
}