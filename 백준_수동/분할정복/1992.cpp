#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

enum CompressStatus
{
    Non,
    Zero,
    One
};

bool isInclude(string src, string targetWord)
{
    return src.find(targetWord) != string::npos;
}

CompressStatus tryCompress(vector<string> &v1)
{
    bool zeroFlag = true;
    bool oneFlag = true;

    for (string s : v1)
    {
        zeroFlag &= !isInclude(s, "1");
        oneFlag &= !isInclude(s, "0");
    }

    CompressStatus res;
    if (zeroFlag)
        res = CompressStatus::Zero;
    else if (oneFlag)
        res = CompressStatus::One;
    else
        res = CompressStatus::Non;

    return res;
}

string dnc(vector<vector<int>> &matrix, int x, int y, int N)
{
    string str = "";

    if (N == 1)
        return to_string(matrix[x][y]);

    vector<string> v1;

    v1.push_back(dnc(matrix, x, y, N / 2));
    v1.push_back(dnc(matrix, x, y + N / 2, N / 2));
    v1.push_back(dnc(matrix, x + N / 2, y, N / 2));
    v1.push_back(dnc(matrix, x + N / 2, y + N / 2, N / 2));

    CompressStatus status = tryCompress(v1);

    if (status == CompressStatus::Zero)
        str = "0";
    else if (status == CompressStatus::One)
        str = "1";
    else
    {
        for (string s : v1)
            str += s;
        str = "(" + str + ")";
    }

    return str;
}

int main()
{
    fastio;
    int N;
    cin >> N;

    vector<vector<int>> matrix;
    matrix.resize(N, vector<int>(N));

    // input datas
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++)
        {
            matrix[i][j] = s[j] - '0';
        }
    }

    string ans = dnc(matrix, 0, 0, N);

    cout << ans << '\n';
}