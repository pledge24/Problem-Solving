#include <bits/stdc++.h>

using namespace std;

void Split(const string& str, vector<string>& splitted, string delimeter)
{
    int pos = 0;
    while(pos < str.length())
    {
        int nextDelimeterPos = str.find(delimeter, pos);
        if(nextDelimeterPos == string::npos)
            nextDelimeterPos = str.length();
        
        int len = nextDelimeterPos - pos;
        if(len > 0)
        {
            splitted.push_back(str.substr(pos, len));
        }
        
        pos = nextDelimeterPos + delimeter.length();
    }
}

int ToDecimal(string& strNum, int sys)
{
    int res = 0;
    int multiply = 1;
    for(int i = strNum.length()-1; i >= 0; i--)
    {
        res += (strNum[i] - '0') * multiply;
        multiply *= sys;
    }
    
    return res;
}

bool ValidExpr(const string& expr, int sys)
{
    // Check digit
    for(char c : expr)
    {
        if(isdigit(c) && sys <= (c - '0'))
            return false;
    }
    
    // Split
    vector<string> formation;
    Split(expr, formation, " ");
    
    if(formation[4] == "X")
        return true;
    
    // Calculate
    int num1 = ToDecimal(formation[0], sys);
    string op = formation[1];
    int num2 = ToDecimal(formation[2], sys);
    
    int lhs = op == "+" ? num1 + num2 : num1 - num2;
    int rhs = ToDecimal(formation[4], sys);
    
    return lhs == rhs;
}

string Calculate(vector<string> formation, int sys)
{
    // Calculate
    int num1 = ToDecimal(formation[0], sys);
    string op = formation[1];
    int num2 = ToDecimal(formation[2], sys);
    
    int decimal = op == "+" ? num1 + num2 : num1 - num2;
    
    // To sys.
    string res = "";
    while(decimal > 0)
    {
        res += (decimal % sys) + '0';
        decimal /= sys;
    }
    
    reverse(res.begin(), res.end());
    
    if(res.empty())
        res = "0";
    
    return res;
}

vector<string> solution(vector<string> expressions) {
    vector<string> answer;
    vector<bool> validSystem(10, true);
    vector<int> xExpr;
    
    for(int i = 0; i < expressions.size(); i++)
    {
        const string& expr = expressions[i];
        
        // Add xExpr.
        if(expr.find("X") != string::npos)
        {
            xExpr.push_back(i);
        }
        
        for(int sys = 2; sys <= 9; sys++)
        {
            if(!validSystem[sys])
                continue;
                        
            if(ValidExpr(expr, sys) == false)
                validSystem[sys] = false;
        }
        
        // for(int sys = 2; sys <= 9; sys++)
        // {
        //     cout << validSystem[sys] << ' ';
        // }
        // cout << '\n';
    }
    
    vector<int> systemList;
    for(int sys = 2; sys <= 9; sys++)
    {
        if(validSystem[sys])
        {
            systemList.push_back(sys);
            // cout << "sys: " << sys << '\n';
        }
    }
    
    for(int idx : xExpr)
    {
        string expr = expressions[idx];
        
        vector<string> formation;
        Split(expr, formation, " ");
        
        vector<string> xList;
        for(int sys : systemList)
        {
            xList.push_back(Calculate(formation, sys));
        }
        
        // remove duplciate
        std::sort(xList.begin(), xList.end());
        xList.erase(std::unique(xList.begin(), xList.end()), xList.end());
        
        // for(string str : xList)
        // {
        //     cout << str << " ";
        // }
        // cout << '\n';
        
        
        // push
        string X = xList.size() > 1 ? "?" : xList[0];
        answer.push_back(expr.substr(0, expr.length()-1) + X);
    }
    
    return answer;
}