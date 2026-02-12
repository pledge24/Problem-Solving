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

bool isCorrect(string &str, vector<string> &splitted)
{
    string startWord = splitted[0];
    string endWord = splitted[1];

    if (str.length() < startWord.length() + endWord.length())
        return false;

    bool startWordMatched = str.substr(0, startWord.length()) == startWord;
    bool endWordMatched = str.substr(str.length() - endWord.length(), endWord.length()) == endWord;

    return startWordMatched && endWordMatched; 
}

int main()
{
    fastio;
    int N;
    cin >> N;

    string pattern;
    cin >> pattern;
    string delimiter = "*";
    vector<string> splitted = split(pattern, delimiter);

    vector<string> strList(N);
    for (int i = 0; i < N; i++)
    {
        cin >> strList[i];
    }

    for (int i = 0; i < N; i++)
    {
        // 패턴 일치를 확인
        string ans = isCorrect(strList[i], splitted) ? "DA" : "NE";

        cout << ans << '\n';
    }
}