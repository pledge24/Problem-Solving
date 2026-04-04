#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void)
{
    fastio;

    int T; cin >> T;
    for(int i = 0; i < T; i++)
    {
        int a, b; cin >> a >> b;
        int c = a + b;

        cout << c * (c-1) / 2 * c << '\n';
    }

    return 0;
}