#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

// delimiter의 종류가 1개일 때(길이가 2이상인 것도 가능)
vector<string> split(string &str, string &delimiter)
{
    vector<string> ret;
    int idx = 0;
    while (idx < str.size())
    {
        int nextIdx = str.find(delimiter, idx);
        if (nextIdx == string::npos)
            nextIdx = str.size();
        if (nextIdx - idx > 0)
            ret.push_back(str.substr(idx, nextIdx - idx));
        idx = nextIdx + delimiter.size();
    }

    return ret;
}

bool isLowerCase(char c)
{
    return 'a' <= c && c <= 'z';
}

bool isUpperCase(char c)
{
    return 'A' <= c && c <= 'Z';
}

string changeToJava(string str)
{
    string ret = "";

    string delimiter = "_";
    vector<string> splitted = split(str, delimiter);
    for (string s : splitted)
    {
        s[0] -= 32;
        ret += s;
    }

    return ret;
}

string changeToCpp(string str)
{
    string ret = "";

    for (char c : str)
    {
        if ('A' <= c && c <= 'Z')
        {
            ret += "_";
            ret += (c + 32);
        }
        else
        {
            ret += c;
        }
    }

    return ret;
}

bool isValidString(string str)
{
    if(!isLowerCase(str[0]) || str[str.length()-1] == '_')
        return false;


    bool upperFlag = false;
    bool underScoreFlag = false;

    for (int i = 1; i < str.length()-1; i++)
    {
        if(str[i] == '_'){
            underScoreFlag = true;
            if(!isLowerCase(str[i-1]) || !isLowerCase(str[i+1]))
                return false;
        }
        else if(isUpperCase(str[i])) 
            upperFlag = true;
    }

    if(underScoreFlag && upperFlag) return false;
    
    return true;
}

int main()
{
    fastio;
    string str;
    cin >> str;

    string ans;
    if (!isValidString(str))
    {
        ans = "Error!";
    }
    else
    {
        bool isCpp = str.find("_") != string::npos;

        if (isCpp)
            ans = changeToJava(str);
        else
            ans = changeToCpp(str);
    }

    cout << ans << '\n';
}