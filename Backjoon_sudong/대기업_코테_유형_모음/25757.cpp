#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

map<char, int> playerN = {
    make_pair('Y', 2),
    make_pair('F', 3),
    make_pair('O', 4)
};

int main(void){
    fastio;
    int N; char gameType; cin >> N >> gameType;

    map<string, bool> m1;
    for(int i = 0; i < N; i++){
        string str; cin >> str;
        m1[str] = true;
    }

    int players = playerN[gameType];
    int ans = m1.size() / (players - 1);

    cout << ans << '\n';
   
    return 0;
}