#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	fastio;
    int N; cin >> N;

    for(int i = 0; i < N; i++){
        string str = "";
        int spaceN = N - 1 - i;
        int starN = i*2 + 1;
        str.append(spaceN, ' ');
        str.append(starN, '*');

        cout << str << '\n';

    }

	return 0;
}