#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void)
{
    fastio;
    string s; cin >> s;
    
    int total = 0;
    for(char c : s)
    {
        int num = c - '0';
        total += pow(num, 5);
    }

    cout << total << '\n';

    return 0;
}