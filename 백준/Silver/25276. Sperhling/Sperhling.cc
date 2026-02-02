#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void)
{
    fastio;
    string s1, s2; cin >> s1 >> s2;

    int start = -1;
    for(int i = 0; i < min(s1.length(), s2.length()); i++)
    {
        if(s1[i] != s2[i])
            break;

        start = i;
    }

    int insertN = s1.length() - (start + 1);
    int deleteN = s2.length() - (start + 1);

    cout << insertN + deleteN << '\n';

    return 0;
}