#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

string Add(string a, string b)
{
    string res = "";
    int i = a.length() - 1;
    int j = b.length() - 1;
    int carry = 0;
    while(i >= 0 || j >= 0 || carry)
    {
        int num1 = i >= 0 ? a[i--] - '0' : 0;
        int num2 = j >= 0 ? b[j--] - '0' : 0;
        int sum = num1 + num2 + carry;

        res += char(sum % 10 + '0');
        carry = sum / 10;
    }

    std::reverse(res.begin(), res.end());
    // cout << "Check: " << res << '\n';
    
    return res;
}

bool IsCyclicNumber(string s)
{
    // {
    //     int pos = s.find_first_not_of('0');
    //     if(pos != string::npos)
    //         s = s.substr(pos);
    // }

    int digits = s.length();
    string temp = s;
    string cmpS = s + s;
    for(int i = 1; i < digits; i++)
    {
        temp = Add(temp, s);
        if(cmpS.find(temp) == string::npos)
            return false;
    }

    return true;
}

int main(void)
{
    fastio;
    string s;
    while(cin >> s)
    {
        if(IsCyclicNumber(s))
            cout << s << " is cyclic" << '\n';
        else
            cout << s << " is not cyclic" << '\n';
    }

    return 0;
}